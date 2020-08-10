#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>

#include <QScrollArea>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QMdiSubWindow>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
   /* auto nextTab = new QTextEdit();
    ui->tabWidget->addTab(nextTab, QString("new%0").arg(ui->tabWidget->count() + 1));
   */

    QMdiSubWindow* window = ui->mdiArea->addSubWindow(new QTextEdit());
    window->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    window->show();

}

void MainWindow::closeTab(int index)
{
    ui->tabWidget->removeTab(index);
}


