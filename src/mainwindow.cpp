#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QRegularExpression>


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
    const QRegularExpression counter("(?:ya|yu|yo|y(?![auo])|[aeiouаеёиоуыэюя])", QRegularExpression::CaseInsensitiveOption);
    const QRegularExpression slasher("((?:ya|yu|yo|y(?![auo])|[aeiouаеёиоуыэюя])(?:[bcdfghjklmnpqrstvwxzбвгджзйклмнпрстфхцчшщ](?:[ьъ](?=[aeiouyаеёиоуыэюя])|[ьъ]?(?![aeiouyаеёиоуыэюя])))?)(?=[bcdfghjklmnpqrstvwxzбвгджзйклмнпрстфхцчшщьъ]*[aeiouyаеёиоуыэюя])", QRegularExpression::CaseInsensitiveOption);
    const QString slasherReplace = "\\1-";

    int count;
    QStringList result;
    const QStringList lines = ui->textEdit->toPlainText().split("\n");
    for (QString line : lines)
    {
        if (line.contains(" : "))
        {
            result.push_back(line);
        }
        else
        {
            count = line.count(counter);
            line.replace(slasher, slasherReplace);
            line.append(QString(" : %1").arg(count));
            result.push_back(line);
        }
    }

    ui->textEdit->setPlainText(result.join("\n"));
}
