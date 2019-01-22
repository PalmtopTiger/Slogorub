#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btExit_clicked();

    void on_btClear_clicked();

    void on_btSlash_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
