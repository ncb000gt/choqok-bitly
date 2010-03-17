/*
    This file is part of Choqok-bitly, a plugin to the KDE micro-blogging
    client Choqok.

    Copyright (C) 2009-2010 Nick Campbell <nicholas.j.campbell@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.


    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, see http://www.gnu.org/licenses/

*/

#ifndef BITLYCONFIG_H
#define BITLYCONFIG_H

#include <kcmodule.h>
#include "ui_bitlyshortnerprefs.h"

class BitlyConfig : public KCModule
{
    Q_OBJECT
public:
    BitlyConfig(QWidget* parent, const QVariantList&);
    ~BitlyConfig();

    virtual void save();
    virtual void load();

protected slots:
    void emitChanged();
private:
    Ui_BitlyShortnerPrefs ui;
};

#endif
