/*************************************************************************
 *     Copyright (C) 2011 by Joseph Boudou                               *
 *      Copyright (C) 2014 by Renaud Guezennec                            *
 *                                                                       *
 *     http://www.rolisteam.org/                                         *
 *                                                                       *
 *   Rolisteam is free software; you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published   *
 *   by the Free Software Foundation; either version 2 of the License,   *
 *   or (at your option) any later version.                              *
 *                                                                       *
 *   This program is distributed in the hope that it will be useful,     *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of      *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       *
 *   GNU General Public License for more details.                        *
 *                                                                       *
 *   You should have received a copy of the GNU General Public License   *
 *   along with this program; if not, write to the                       *
 *   Free Software Foundation, Inc.,                                     *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.           *
 *************************************************************************/


#include "data/person.h"

#include <QUuid>
#include <QApplication>


#include "network/networkmessagereader.h"
#include "network/networkmessagewriter.h"

/**********
 * Person *
 **********/
Person::Person(const QString & name, const QColor & color)
    : m_name(name), m_color(color)
{
    m_uuid = QUuid::createUuid().toString();
}

Person::Person(const QString & uuid, const QString & name, const QColor & color)
    : m_uuid(uuid), m_name(name), m_color(color)
{
}

Person::Person()
{
}
Person::~Person()
{
}
const QString Person::uuid() const
{
    return m_uuid;
}

QString Person::getName() const
{
    return m_name;
}

QColor Person::getColor() const
{
    return m_color;
}

Person* Person::parent() const
{
    return NULL;
}

bool Person::setColor(const QColor & color)
{
    if (color == m_color)
        return false;

    m_color = color;
    return true;
}

bool Person::setName(const QString & name)
{
    if (name == m_name)
        return false;

    m_name = name;
    return true;
}



const QImage& Person::getAvatar() const
{
    return m_avatar;
}

bool Person::hasAvatar() const
{
    return !m_avatar.isNull();
}

void Person::setAvatar(QImage& p)
{
    m_avatar = p;
}
Qt::CheckState Person::checkedState()
{
    return m_checkState;
}

bool Person::isLeaf()
{
    return true;
}
void Person::setState(Qt::CheckState c)
{
    m_checkState = c;
}
