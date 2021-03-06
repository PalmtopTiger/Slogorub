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
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	a.setApplicationName("Slogorub");
	a.setApplicationVersion("1.0");
	a.setOrganizationName("Unlimited Web Works");
    a.setWindowIcon(QIcon(":/main.ico"));

    MainWindow w;
    w.show();
    
    return a.exec();
}
