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

#include "bitlyconfig.h"
#include <KPluginFactory>
#include <klocale.h>
#include <qlayout.h>
#include "bitlysettings.h"
#include <QVBoxLayout>

K_PLUGIN_FACTORY( BitlyConfigFactory, registerPlugin < BitlyConfig > (); )
K_EXPORT_PLUGIN( BitlyConfigFactory( "kcm_choqok_bitly" ) )

BitlyConfig::BitlyConfig(QWidget* parent, const QVariantList& ):
        KCModule( BitlyConfigFactory::componentData(), parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QWidget *wd = new QWidget(this);
    wd->setObjectName("mBitlyCtl");
    ui.setupUi(wd);
    addConfig( BitlySettings::self(), wd );
    layout->addWidget(wd);
    connect( ui.kcfg_apiname,SIGNAL(textChanged(QString)), SLOT(emitChanged()) );
    connect( ui.kcfg_apikey, SIGNAL(textChanged(QString)), SLOT(emitChanged()) );
}

BitlyConfig::~BitlyConfig()
{

}

void BitlyConfig::load()
{
    kDebug();
    KCModule::load();
}

void BitlyConfig::save()
{
    kDebug();
    KCModule::save();
}

void BitlyConfig::emitChanged()
{
    emit changed(true);
    disconnect( ui.kcfg_apiname, SIGNAL(textChanged(QString)), this, SLOT(emitChanged()) );
    disconnect( ui.kcfg_apikey, SIGNAL(textChanged(QString)), this, SLOT(emitChanged()) );
}
