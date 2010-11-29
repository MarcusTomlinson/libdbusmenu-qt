/* This file is part of the dbusmenu-qt library
   Copyright 2009 Canonical
   Author: Aurelien Gateau <aurelien.gateau@canonical.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License (LGPL) as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later
   version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#ifndef DBUSMENUCUSTOMITEMFACTORY_H
#define DBUSMENUCUSTOMITEMFACTORY_H

// Qt
#include <QtCore/QVariant>

#include <QtGui/QAction>

// Local
#include <dbusmenu_export.h>

class QObject;

class DBusMenuImporter;

class DBUSMENU_EXPORT DBusMenuImporterAction : public QAction
{
public:
    DBusMenuImporterAction(DBusMenuImporter *importer, int id);

    virtual void update(const QVariantMap &properties, const QVariant &keys);

    int id() const;
    
protected:
    void sendEvent(const QString &name, const QVariant &data = QVariant()) const;
};

class DBusMenuCustomItemFactoryPrivate;
/**
 * A DBusMenuCustomItemFactory instance can recreate custom items serialized over DBus
 */
class DBUSMENU_EXPORT DBusMenuCustomItemFactory
{
public:
    DBusMenuCustomItemFactory(const QString &itemType);
    virtual ~DBusMenuCustomItemFactory();

    QString itemType() const;

    virtual DBusMenuImporterAction *createAction(const QVariantMap &properties, QObject *parent) = 0;

private:
    Q_DISABLE_COPY(DBusMenuCustomItemFactory)
    DBusMenuCustomItemFactoryPrivate *const d;
    friend class DBusMenuCustomItemFactoryPrivate;
};

#endif /* DBUSMENUCUSTOMITEMFACTORY_H */
