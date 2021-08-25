import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQuick.Controls.Imagine 2.12
import CI 1.0

import "QML/Modules/"
import "QML/CControls/"
import "QML/Blocks/"

ApplicationWindow {
    id: mainWnd

    property rect viedoRect:  Qt.rect(
                                  video.x + mainFrame.anchors.margins + mainFrame.rightPadding + 2,
                                  video.y + mainFrame.anchors.margins + mainFrame.topPadding + 1,
                                  video.width - 2,
                                  video.height - 2
                                  )


    property alias viedoArea: video

    visible: true
    width: 1280
    height: 720
//    minimumWidth: 1280
//    minimumHeight: 720
    title: qsTr("测试地面站")
    font.pixelSize: CTheme.normalFontSize
    Component.onCompleted: {
       // CI.authLogin()
      //  CI.startRealPlay(0)
    }
    CUdpSocket {
        id: udp
        onSigRecieveMsg: {
        }
    }

    Frame {
        id: mainFrame
        anchors.fill: parent
        anchors.margins: 60
        topPadding: 30
        bottomPadding: 30

        LeftFrame {
            id: leftFrame
            width: parent.width / 4
        }

        Frame {
            id: video
            anchors {
                left: leftFrame.right
                leftMargin: 12
                right: rightFrame.left
                rightMargin: 12
            }
            height: parent.height
        }

        RightFrame {
            id: rightFrame
            width: parent.width / 4
            anchors {
                right: parent.right
            }
        }
    }
}


