/* === This file is part of Calamares - <http://github.com/calamares> ===
 *
 *   Copyright 2016, Teo Mrnjavac <teo@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#include "PythonQtConsoleViewStep.h"

using namespace Calamares;

PythonQtConsoleViewStep::PythonQtConsoleViewStep( PythonQtObjectPtr cxt,
                                                  QObject* parent )
    : ViewStep( parent )
{
    m_cxt = cxt;
    qDebug() << "SMO" << PythonQtConsoleViewStep::staticMetaObject.className();
    PythonQt::self()->registerClass( &PythonQtConsoleViewStep::staticMetaObject, "Calamares" );
    m_console = new PythonQtScriptingConsole( nullptr, m_cxt );
}

QWidget*
PythonQtConsoleViewStep::widget()
{
    return m_console;
}


