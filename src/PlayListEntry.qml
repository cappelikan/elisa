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

import QtQuick 2.5
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import org.mgallien.QmlExtension 1.0

Rectangle {
    id: viewAlbumDelegate

    property string title
    property string artist
    property string album
    property var index
    property var itemDecoration
    property alias duration : durationLabel.text
    property int trackNumber
    property int discNumber
    property alias rating: ratingWidget.starRating
    property alias isPlaying : playIcon.visible
    property bool isSelected
    property bool isValid
    property bool isAlternateColor
    property bool containsMouse
    property bool hasAlbumHeader
    property var playListModel
    property var playListControler
    property var contextMenu
    property alias clearPlayListAction: removeFromPlayList
    property alias playNowAction: playNow

    SystemPalette {
        id: myPalette
        colorGroup: SystemPalette.Active
    }

    color: (isAlternateColor ? myPalette.alternateBase : myPalette.base)

    height: (hasAlbumHeader ? Screen.pixelDensity * 21 : Screen.pixelDensity * 7.)

    Action {
        id: removeFromPlayList
        text: i18nc("Remove current track from play list", "Remove")
        iconName: "list-remove"
        onTriggered: {
            playListModel.removeRows(viewAlbumDelegate.index, 1)
        }
    }

    Action {
        id: playNow
        text: i18nc("Play now current track from play list", "Play Now")
        iconName: "media-playback-start"
        enabled: !isPlaying && isValid
        onTriggered: {
            playListControler.switchTo(viewAlbumDelegate.index)
        }
    }

    ColumnLayout {
        spacing: 0

        anchors.fill: parent
        anchors.leftMargin: Screen.pixelDensity * 1.5
        anchors.rightMargin: Screen.pixelDensity * 5.5
        anchors.topMargin: 0
        anchors.bottomMargin: 1

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: Screen.pixelDensity * 15.
            Layout.minimumHeight: Screen.pixelDensity * 15.
            Layout.maximumHeight: Screen.pixelDensity * 15.

            visible: hasAlbumHeader

            RowLayout {
                id: headerRow

                spacing: Screen.pixelDensity * 1.5

                anchors.fill: parent

                Image {
                    id: mainIcon

                    source: (isValid ? (viewAlbumDelegate.itemDecoration ? viewAlbumDelegate.itemDecoration : 'image://icon/media-optical-audio') : 'image://icon/error')

                    Layout.minimumWidth: headerRow.height - 4
                    Layout.maximumWidth: headerRow.height - 4
                    Layout.preferredWidth: headerRow.height - 4
                    Layout.minimumHeight: headerRow.height - 4
                    Layout.maximumHeight: headerRow.height - 4
                    Layout.preferredHeight: headerRow.height - 4
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                    sourceSize.width: headerRow.height - 4
                    sourceSize.height: parent.height - 4

                    fillMode: Image.PreserveAspectFit
                    asynchronous: true

                    visible: isValid
                }

                BrightnessContrast {
                    source: mainIcon

                    cached: true

                    visible: !isValid

                    contrast: -0.9

                    Layout.minimumWidth: headerRow.height - 4
                    Layout.maximumWidth: headerRow.height - 4
                    Layout.preferredWidth: headerRow.height - 4
                    Layout.minimumHeight: headerRow.height - 4
                    Layout.maximumHeight: headerRow.height - 4
                    Layout.preferredHeight: headerRow.height - 4
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    spacing: 0

                    Item {
                        height: Screen.pixelDensity * 1.5
                    }

                    Text {
                        id: mainLabel
                        text: album

                        font.weight: Font.Bold
                        color: myPalette.text

                        horizontalAlignment: "AlignHCenter"

                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignCenter

                        elide: "ElideRight"
                    }

                    Item {
                        Layout.fillHeight: true
                    }

                    Text {
                        id: authorLabel

                        text: artist

                        font.weight: Font.Light
                        color: myPalette.text

                        horizontalAlignment: "AlignHCenter"

                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignCenter

                        elide: "ElideRight"
                    }

                    Item {
                        height: Screen.pixelDensity * 1.5
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                id: trackRow

                anchors.fill: parent

                spacing: Screen.pixelDensity * 1.

                Text {
                    id: mainCompactLabel

                    text: (discNumber ? discNumber + ' - ' + trackNumber : trackNumber) + ' - ' + title

                    font.weight: Font.Bold
                    color: myPalette.text

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

                    visible: isValid

                    elide: "ElideRight"
                }

                Text {
                    id: mainInvalidCompactLabel

                    text: title

                    font.weight: Font.Bold
                    color: myPalette.text

                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

                    visible: !isValid

                    elide: "ElideRight"
                }

                Item { Layout.fillWidth: true }

                ToolButton {
                    id: playNowButton

                    implicitHeight: Screen.pixelDensity * 6.
                    implicitWidth: Screen.pixelDensity * 6.

                    visible: opacity > 0.1
                    action: playNow
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                }

                ToolButton {
                    id: removeButton

                    implicitHeight: Screen.pixelDensity * 6.
                    implicitWidth: Screen.pixelDensity * 6.

                    visible: opacity > 0.1
                    action: removeFromPlayList
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                }

                Image {
                    id: playIcon

                    Layout.preferredWidth: parent.height * 1
                    Layout.preferredHeight: parent.height * 1
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                    Layout.maximumWidth: Screen.pixelDensity * 6
                    Layout.maximumHeight: Screen.pixelDensity * 6

                    source: 'image://icon/media-playback-start'
                    width: parent.height * 1.
                    height: parent.height * 1.
                    sourceSize.width: parent.height * 1.
                    sourceSize.height: parent.height * 1.
                    fillMode: Image.PreserveAspectFit
                    visible: isPlaying

                    SequentialAnimation on opacity {
                        running: isPlaying
                        loops: Animation.Infinite

                        NumberAnimation {
                            from: 0
                            to: 1.
                            duration: 1000
                            easing.type: Easing.InOutCubic
                        }
                        NumberAnimation {
                            from: 1
                            to: 0
                            duration: 1000
                            easing.type: Easing.InOutCubic
                        }
                    }
                }

                RatingStar {
                    id: ratingWidget

                    starSize: Screen.pixelDensity * 2.5
                }

                Text {
                    id: durationLabel
                    text: duration

                    color: myPalette.text

                    elide: "ElideRight"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                }
            }
        }
    }

    states: [
        State {
            name: 'notSelected'
            when: !isSelected && !containsMouse
            PropertyChanges {
                target: viewAlbumDelegate
                height: Screen.pixelDensity * (hasAlbumHeader ? 21 : 7)
            }
            PropertyChanges {
                target: removeButton
                opacity: 0
            }
            PropertyChanges {
                target: playNowButton
                opacity: 0
            }
            PropertyChanges {
                target: viewAlbumDelegate
                color: (isAlternateColor ? myPalette.alternateBase : myPalette.base)
            }
        },
        State {
            name: 'selected'
            when: isSelected
            PropertyChanges {
                target: viewAlbumDelegate
                height: Screen.pixelDensity * (hasAlbumHeader ? 21 : 7)
            }
            PropertyChanges {
                target: removeButton
                opacity: 1
            }
            PropertyChanges {
                target: playNowButton
                opacity: 1
            }
            PropertyChanges {
                target: viewAlbumDelegate
                color: myPalette.highlight
            }
        },
        State {
            name: 'hoveredAndNotSelected'
            when: !isSelected && containsMouse
            PropertyChanges {
                target: viewAlbumDelegate
                height: Screen.pixelDensity * (hasAlbumHeader ? 21 : 7)
            }
            PropertyChanges {
                target: removeButton
                opacity: 1
            }
            PropertyChanges {
                target: playNowButton
                opacity: 1
            }
            PropertyChanges {
                target: viewAlbumDelegate
                color: myPalette.mid
            }
        }
    ]
    transitions: Transition {
        ParallelAnimation {
            NumberAnimation {
                properties: "height, opacity"
                easing.type: Easing.InOutQuad
                duration: 50
            }
            ColorAnimation {
                properties: "color"
                duration: 200
            }
        }
    }
}

