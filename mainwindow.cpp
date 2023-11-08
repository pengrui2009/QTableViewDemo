#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList strList;
    strList<<QString("ID")<<"Name"<<"one"<<"two"<<"three"<<"four"<<"five"<<"six";
    model_ptr = new TableViewModel();
    model_ptr->SetHeadData(strList);
    ui->tableView->setModel(model_ptr);
    ui->tableView->verticalHeader()->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

