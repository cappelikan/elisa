/*
 * Copyright 2016-2017 Matthieu Gallien <matthieu_gallien@yahoo.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "localfilelisting.h"

#include "musicaudiotrack.h"

#include <KFileMetaData/Properties>
#include <KFileMetaData/ExtractorCollection>
#include <KFileMetaData/Extractor>
#include <KFileMetaData/SimpleExtractionResult>
#include <KFileMetaData/UserMetaData>

#include <QThread>
#include <QHash>
#include <QFileInfo>
#include <QDir>
#include <QFileSystemWatcher>
#include <QMimeDatabase>
#include <QStandardPaths>

#include <QDebug>

#include <algorithm>

class LocalFileListingPrivate
{
public:

    QString mRootPath;

};

LocalFileListing::LocalFileListing(QObject *parent) : AbstractFileListing(QStringLiteral("local"), parent), d(new LocalFileListingPrivate)
{
    const auto &musicLocations(QStandardPaths::standardLocations(QStandardPaths::MusicLocation));

    if (musicLocations.isEmpty()) {
        return;
    }

    d->mRootPath = musicLocations.first();
}

LocalFileListing::~LocalFileListing()
{
}

QString LocalFileListing::rootPath() const
{
    return d->mRootPath;
}

void LocalFileListing::setRootPath(QString rootPath)
{
    if (d->mRootPath == rootPath) {
        return;
    }

    d->mRootPath = rootPath;
    Q_EMIT rootPathChanged();
}

void LocalFileListing::triggerRefreshOfContent()
{
    scanDirectoryTree(d->mRootPath);
}


#include "moc_localfilelisting.cpp"
