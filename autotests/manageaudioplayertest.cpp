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

#include "manageaudioplayertest.h"

#include "manageaudioplayer.h"

#include <QtTest>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QUrl>

ManageAudioPlayerTest::ManageAudioPlayerTest(QObject *parent) : QObject(parent)
{
}

void ManageAudioPlayerTest::initTestCase()
{
}

void ManageAudioPlayerTest::simpleInitialCase()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::noPlayCase()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::skipNextTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::skipPreviousTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::playTrackAndskipNextTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 5);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));
}

void ManageAudioPlayerTest::playTrackAndskipPreviousTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 5);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));
}

void ManageAudioPlayerTest::skipNextTrackAndPlayTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::skipPreviousTrackAndPlayTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::playLastCase()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.playListFinished();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    QCOMPARE(playerPlaySpy.wait(100), false);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::playRestoredTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::testRestoreSettingsAutomaticPlay()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = true;

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::testRestoreSettingsNoAutomaticPlay()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = false;

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(1000), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::testRestoreSettingsAutomaticPlayAndPosition()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = true;
    settings[QStringLiteral("playerPosition")] = 10000;

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));
    QCOMPARE(seekSpy.at(0).at(0).toInt(), 10000);

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::InvalidMedia));

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::playTrackPauseAndSkipNextTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loading);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loading));

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(ManageAudioPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPauseSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PausedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PausedState));

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(ManageAudioPlayer::Loaded);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Loaded));

    myPlayer.setPlayerStatus(ManageAudioPlayer::Buffering);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::Buffering));

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(ManageAudioPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), static_cast<int>(ManageAudioPlayer::EndOfMedia));
}

QTEST_MAIN(ManageAudioPlayerTest)


#include "moc_manageaudioplayertest.cpp"
