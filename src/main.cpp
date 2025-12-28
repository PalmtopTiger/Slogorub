/*
 * This file is part of Slogorub.
 * Copyright (C) 2012-2025  Andrey Efremov <duxus@yandex.ru>
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
#include <QLocale>
#include <QLibraryInfo>
#include <QTranslator>

using namespace Qt::StringLiterals;


int main(int argc, char *argv[])
{
    QApplication::setStyle("Fusion"_L1);

    QApplication app(argc, argv);

    QTranslator translator;
    if (translator.load(QLocale(), "qtbase"_L1, "_"_L1, QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        QCoreApplication::installTranslator(&translator);
    }

    MainWindow window;
    window.show();
    
    return app.exec();
}
