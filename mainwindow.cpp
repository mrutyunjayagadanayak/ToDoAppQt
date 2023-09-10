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
        //item->setCheckState(Qt::Unchecked);
    }
    ui->txt_task->clear();
    ui->txt_task->setFocus();
}


void MainWindow::on_button_remove_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    FileOps delete_file;
    delete_file.delete_file(FileOps::dir_path + "/" +item->text());
    ui->textEdit->clear();
    delete item;
}


void MainWindow::on_button_remove_all_clicked()
{
    FileOps delete_file;
    for(size_t i{0};i < ui->listWidget->count();i++)
    {
        delete_file.delete_file(FileOps::dir_path + "/" + ui->listWidget->item(i)->text());
    }
    ui->listWidget->clear();
    ui->textEdit->clear();
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    FileOps change_todo_item;
    change_todo_item.read_todo(ui,FileOps::dir_path + "/" +item->text(),item->text());
}

void MainWindow::on_save_todo_clicked()
{
    FileOps todo_file;
    todo_file.write_todo(ui,FileOps::dir_path + "/" + ui->listWidget->currentItem()->text());
}

