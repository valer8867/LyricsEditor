#include "note.h"
#include "ui_note.h"

#include <QMouseEvent>

Note::Note(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Note),
    mousePressed(false)
{
    ui->setupUi(this);
    ui->label->installEventFilter(this);


}

Note::~Note()
{
    delete ui;
}



bool Note::eventFilter(QObject *watched, QEvent *event)
{
    if (parentWidget()) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                startPos  = mouseEvent->pos();
                mousePressed = true;
                return true;
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease){
            mousePressed = false;
            return true;
        }
        else if (event->type() == QEvent::MouseMove && mousePressed) {
            QMouseEvent *moveMouseEvent = static_cast<QMouseEvent *>(event);
            parentWidget()->move(parentWidget()->pos() + moveMouseEvent->pos() - startPos);
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void Note::on_pushButton_clicked()
{
    parentWidget()->close();
}
