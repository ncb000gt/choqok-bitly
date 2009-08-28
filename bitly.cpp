/*
This file is part of the choqok-bitly plugin for Choqok.

Copyright (C) 2009 Nick Campbell <nicholas.j.campbell@gmail.com>

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

#include "bitly.h"
#include <QString>
#include <KIO/Job>
#include <KDebug>
#include <kio/netaccess.h>
#include <KAboutData>
#include <KGenericFactory>
#include <kglobal.h>
#include <ksharedconfig.h>
#include <kconfiggroup.h>

typedef KGenericFactory<Bitly> MyPluginFactory;
static const KAboutData aboutdata("choqok_bitly", 0, ki18n("Bit.ly Shortener") , "0.1" );
K_EXPORT_COMPONENT_FACTORY( choqok_bitly, MyPluginFactory( &aboutdata )  )

Bitly::Bitly( QObject *parent, const QStringList &  args  )
: Choqok::Shortener( MyPluginFactory::componentData(), parent )
{
    Q_UNUSED(args)
}

QString Bitly::shorten( const QString &url )
{
    kDebug()<<"Using bit.ly";
    QByteArray data;//output
    KUrl reqUrl;
    const QString apiname = KGlobal::config()->group("Advanced").readEntry("ShortenPlugin_APIName", QString());
    const QString apikey = KGlobal::config()->group("Advanced").readEntry("ShortenPlugin_APIKey", QString());
    kDebug() << "API Login: " << apiname;
    kDebug() << "API Key: " << apikey;
    if ( ! ( apiname.isEmpty() && apikey.isEmpty() ) ) {
	reqUrl.setHost( QString( "http://api.bit.ly/shorten" ) );
	reqUrl.addQueryItem( "version", "2.0.1" );
	reqUrl.addQueryItem( "longUrl", KUrl( url ).url() );
	reqUrl.addQueryItem( "login", apiname );
	reqUrl.addQueryItem( "apiKey", apikey );
    } else {
	reqUrl.setHost( QString( "http://bit.ly/" ) );
	reqUrl.addQueryItem( "s", "" );
	reqUrl.addQueryItem( "keyword", "" );
	reqUrl.addQueryItem( "url", KUrl( url ).url() );
    }

    KIO::Job *job = KIO::get( reqUrl, KIO::Reload, KIO::HideProgressInfo );

    if ( KIO::NetAccess::synchronousRun( job, 0, &data ) ) {
        QString output(data);
        QRegExp rx( QString( "\"shortUrl\": \"([^\"]*)\"," ) );
        kDebug() << output;
        rx.setMinimal(true);
        rx.indexIn(output);
        output = rx.cap(1);
        kDebug() << "Short url is: " << output;
        if(!output.isEmpty()) {
            return output;
        }
    } else {
        kDebug() << "Cannot create a shortened url.\t" << "KJob ERROR";
    }
    return url;
}

Bitly::~Bitly()
{
}

#include "bitly.moc"
