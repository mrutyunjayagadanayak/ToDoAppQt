#ifndef FILEOPS_H
#define FILEOPS_H

#include <QStandardPaths>
#include "mainwindow.h"

class FileOps
{
private:
    const static QString dir_path;
    const static QString main_config_path;
    void initiate_dir();
public:
    bool read_file(Ui::MainWindow *ui, QString path=main_config_path);
    bool write_file(Ui::MainWindow *ui,QString path=main_config_path);
    FileOps();
};

#endif // FILEOPS_H
