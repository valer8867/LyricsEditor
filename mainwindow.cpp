#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <QMdiArea>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMdiSubWindow>
#include <QTextEdit>
#include <QDockWidget>

#include "note.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    QMdiSubWindow* note = ui->mdiArea->addSubWindow(new Note());

    note->setWindowFlag(Qt::FramelessWindowHint);
    note->setWindowTitle("new note");
    note->show();

}

void MainWindow::closeTab(int index)
{
    ui->tabWidget->removeTab(index);
}


