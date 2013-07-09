#include <QDesktopWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->move(QApplication::desktop()->screenGeometry().center() - this->rect().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btExit_clicked()
{
    QApplication::exit();
}

void MainWindow::on_btClear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_btSlash_clicked()
{
    QRegExp tester("(?:^\\s*|: \\d+)$");
    QRegExp counter("(ya|yu|yo|y(?![auo])|[aeiouаеёиоуыэюя])", Qt::CaseInsensitive);
    QRegExp slasher("((?:ya|yu|yo|y(?![auo])|[aeiouаеёиоуыэюя])(?:[bcdfghjklmnpqrstvwxzбвгджзйклмнпрстфхцчшщ](?:[ьъ](?=[aeiouyаеёиоуыэюя])|[ьъ]?(?![aeiouyаеёиоуыэюя])))?)(?=[bcdfghjklmnpqrstvwxzбвгджзйклмнпрстфхцчшщьъ]*[aeiouyаеёиоуыэюя])", Qt::CaseInsensitive);
    QString slasherReplace = "\\1-";

    int count, pos;
    QStringList result;
    QStringList lines = ui->textEdit->toPlainText().split("\n");
    foreach (QString line, lines)
    {
        if (tester.indexIn(line) != -1)
        {
            result.push_back(line);
        }
        else
        {
            pos = 0;
            count = 0;
            while (pos >= 0)
            {
                pos = counter.indexIn(line, pos);
                if (pos >= 0) {
                    pos += counter.matchedLength();
                    ++count;
                }
            }
            line.replace(slasher, slasherReplace);
            line += " : " + QString::number(count);
            result.push_back(line);
        }
    }

    ui->textEdit->setPlainText(result.join("\n"));
}
