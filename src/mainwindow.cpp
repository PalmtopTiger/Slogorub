/*
 * This file is part of Slogorub.
 * Copyright (C) 2012-2019  Andrey Efremov <duxus@yandex.ru>
 *
 * Slogorub is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Slogorub is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Slogorub.  If not, see <https://www.gnu.org/licenses/>.
 */

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
