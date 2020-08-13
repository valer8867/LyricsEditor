#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QPoint>

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

     bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
     void on_pushButton_clicked();

private:
    Ui::Note *ui;
    QPoint startPos;
    bool mousePressed;


};

#endif // NOTE_H
