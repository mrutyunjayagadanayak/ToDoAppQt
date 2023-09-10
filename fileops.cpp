#include "fileops.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>

const QString FileOps::dir_path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/ToDoAppQt";
const QString FileOps::main_config_path = dir_path + "/.ToDoAppSave";
FileOps::FileOps()
{
    initiate_dir();
}
void FileOps::initiate_dir()
{
    QDir config_dir{dir_path};
    if(!config_dir.exists())
    {
        config_dir.mkdir(dir_path);
    }
}
bool FileOps::read_file(Ui::MainWindow *ui, QString path)
{
    QFile save_file{path};
    if(!save_file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",save_file.errorString());
        return false;
    }

    QTextStream in{&save_file};
    while (!in.atEnd()) {
        QListWidgetItem *item = new QListWidgetItem(in.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
    save_file.close();
    return true;
}
bool FileOps::write_file(Ui::MainWindow *ui, QString path)
{
    QFile save_file{path};
    if(!save_file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",save_file.errorString());
        return false;
    }
    save_file.resize(0);
    QTextStream out{&save_file};
    for(size_t i {0}; i < ui->listWidget->count(); i++) {
        out << ui->listWidget->item(i)->text() << "\n";
    }
    save_file.close();
    return true;
}
bool FileOps::delete_file(QString path)
{
    QFile delete_file{path};
    if(!delete_file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",delete_file.errorString());
        return false;
    }
    delete_file.remove();
    delete_file.close();
    return true;
}
bool FileOps::write_todo(Ui::MainWindow *ui, QString path)
{
    QFile todo_file{path};
    if(!todo_file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",todo_file.errorString());
        return false;
    }
    todo_file.resize(0);
    QTextStream out{&todo_file};
    out << ui->textEdit->toPlainText();
    todo_file.close();
    return true;
}

bool FileOps::read_todo(Ui::MainWindow *ui, QString path,QString item_name)
{
    QFile todo_file{path};
    if(!todo_file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",todo_file.errorString());
        return false;
    }
    QTextStream in{&todo_file};
    ui->textEdit->setText(in.readAll());
    return true;
}
