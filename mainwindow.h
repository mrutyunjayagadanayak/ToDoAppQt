#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_add_clicked();

    void on_button_remove_clicked();

    void on_button_remove_all_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_save_todo_clicked();

private:
    Ui::MainWindow *ui;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/toDoFile.txt";
};
#endif // MAINWINDOW_H
