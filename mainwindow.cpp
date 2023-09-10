#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
    file.close();
}

MainWindow::~MainWindow()
{
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0,"error",file.errorString());
    }
    file.resize(0);
    QTextStream out(&file);
    for(size_t i {0}; i < ui->listWidget->count(); i++) {
        out << ui->listWidget->item(i)->text() << "\n";
    }
    file.close();
    delete ui;
}


void MainWindow::on_button_add_clicked()
{
    if(ui->txt_task->text().size() > 0) {
        QListWidgetItem* item = new QListWidgetItem(ui->txt_task->text(),
                                                    ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
    ui->txt_task->clear();
    ui->txt_task->setFocus();
}


void MainWindow::on_button_remove_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow::on_button_remove_all_clicked()
{
    ui->listWidget->clear();
}
