#ifndef FILEOPS_H
#define FILEOPS_H

#include <QStandardPaths>
#include "mainwindow.h"

class FileOps
{
private:
    void initiate_dir();
    const static QString main_config_path;
public:
    bool read_file(Ui::MainWindow *ui, QString path=main_config_path);
    bool write_file(Ui::MainWindow *ui,QString path=main_config_path);
    bool write_todo(Ui::MainWindow *ui,QString path=main_config_path);
    bool read_todo(Ui::MainWindow *ui,QString path=main_config_path,QString item_name="");
    bool delete_file(QString path);
    FileOps();
    const static QString dir_path;

};

#endif // FILEOPS_H
