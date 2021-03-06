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
#include <choqokuiglobal.h>
#include <bitlysettings.h>

K_PLUGIN_FACTORY( MyPluginFactory, registerPlugin < Bitly > (); )
K_EXPORT_PLUGIN( MyPluginFactory( "choqok_bitly" ) )

Bitly::Bitly( QObject *parent, const QVariantList& )
: Choqok::Shortener( MyPluginFactory::componentData(), parent )
{
}
Bitly::~Bitly()
{
}

QString Bitly::shorten( const QString &url )
{
    kDebug()<<"Using bit.ly";
    QByteArray data;
    KUrl reqUrl;
    const QString apiname = BitlySettings::apiname().toLatin1();
    const QString apikey = BitlySettings::apikey().toLatin1();
    kDebug() << "API Login: " << apiname;
    kDebug() << "API Key: " << apikey;
    if ( ! ( apiname.isEmpty() && apikey.isEmpty() ) ) {
	KUrl buildUrl ( "http://api.bit.ly/shorten" );
	buildUrl.addQueryItem( "version", "2.0.1" );
	buildUrl.addQueryItem( "longUrl", KUrl( url ).url() );
	buildUrl.addQueryItem( "login", apiname );
	buildUrl.addQueryItem( "apiKey", apikey );
	reqUrl = buildUrl;
    } else {
	//XXX: this will break if they change the results in their page.
	KUrl buildUrl ( "http://bit.ly" );
	buildUrl.addQueryItem( "s", "" );
	buildUrl.addQueryItem( "keyword", "" );
	buildUrl.addQueryItem( "url", KUrl( url ).url() );
	reqUrl = buildUrl;
    }

    kDebug() << "Url: " << reqUrl;
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
