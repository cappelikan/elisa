/*
 * Copyright 2016 Matthieu Gallien <matthieu_gallien@yahoo.fr>
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

#ifndef PLAYLISTCONTROLERTEST_H
#define PLAYLISTCONTROLERTEST_H

#include <QObject>

class PlayListControlerTest : public QObject
{

    Q_OBJECT

public:

    explicit PlayListControlerTest(QObject *parent = 0);

Q_SIGNALS:

private Q_SLOTS:

    void initTestCase();

    void testBringUpCase();

    void testBringUpCaseFromNewAlbum();

    void testBringUpAndDownCase();

    void testBringUpAndRemoveCase();

    void testBringUpAndRemoveMultipleCase();

    void testBringUpAndRemoveMultipleNotBeginCase();

    void testBringUpAndPlayCase();

    void testBringUpAndSkipNextCase();

    void testBringUpAndSkipPreviousCase();

    void finishPlayList();

    void randomPlayList();

    void continuePlayList();

    void testRestoreSettings();

    void removeBeforeCurrentTrack();

    void switchToTrackTest();

};

#endif // PLAYLISTCONTROLERTEST_H
