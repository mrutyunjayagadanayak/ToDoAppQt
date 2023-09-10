#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fileops.h"

#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FileOps read_file;
    read_file.read_file(ui);
}

MainWindow::~MainWindow()
{
    FileOps write_file;
    write_file.write_file(ui);
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
