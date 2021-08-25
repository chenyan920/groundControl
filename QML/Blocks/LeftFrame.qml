import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Imagine 2.12
import CI 1.0

import "../Modules/"
import "../CControls/"

ColumnLayout {
    id: leftLayout

    CuiSeparator {
        _p: leftLayout
        label: qsTr("操作")
    }

//    Settings {
//    }

    RowLayout {
        CuiFeatureButton {
            text: qsTr("登录")
            Layout.preferredHeight: autoLoginSwitch.height
            onClicked: {
                CI.authLogin()
            }
        }
        CuiFeatureButton {
            text: qsTr("注销")
            Layout.preferredHeight: autoLoginSwitch.height
        }
        SwitchDelegate {
            id: autoLoginSwitch
            font.pixelSize: CTheme.normalFontSize * 0.8
            text: qsTr("自动登录")
        }
    }

    CuiSeparator {
        _p: leftLayout
        Layout.topMargin: 24
        label: qsTr("预览")
    }
    RowLayout {
        Layout.alignment: Qt.AlignHCenter
        CuiFeatureButton {
            text: qsTr("预览")
            Layout.preferredHeight: autoLoginSwitch.height
            onClicked: {
                CI.startRealPlay(0)
            }
        }
        CuiFeatureButton {
            text: qsTr("开始")
            Layout.preferredHeight: autoLoginSwitch.height
        }
        CuiFeatureButton {
            text: qsTr("截图")
            Layout.preferredHeight: autoLoginSwitch.height
        }
    }

    CuiSeparator {
        _p: leftLayout
        Layout.topMargin: 24
        label: qsTr("视频")
    }
    RowLayout {
        Layout.alignment: Qt.AlignHCenter
        CuiFeatureButton {
            text: qsTr("均衡") //what's this?
            Layout.preferredHeight: autoLoginSwitch.height
        }
        CuiFeatureButton {
            text: qsTr("高清")
            Layout.preferredHeight: autoLoginSwitch.height
        }
        CuiFeatureButton {
            text: qsTr("超清")
            Layout.preferredHeight: autoLoginSwitch.height
        }
    }

    CuiSeparator {
        _p: leftLayout
        Layout.topMargin: 24
        label: qsTr("云台")
    }
    GridLayout {
        rows: 2
        columns: 3
        Layout.alignment: Qt.AlignHCenter
        CuiFeatureButton {
            text: qsTr("向上")
            Layout.preferredHeight: autoLoginSwitch.height
            Layout.columnSpan: 3
            Layout.alignment: Qt.AlignHCenter
            onPressed: {
                CI.ptzControl(CEnum.DIRECTUP)
            }
            onReleased: {
                CI.ptzStop(CEnum.DIRECTUP)
            }
        }
        CuiFeatureButton {
            text: qsTr("向左")
            Layout.preferredHeight: autoLoginSwitch.height
            onPressed:{
                CI.ptzControl(CEnum.DIRECTLEFT, 2)
            }
            onReleased: {
                CI.ptzStop(CEnum.DIRECTLEFT)
            }
        }
        CuiFeatureButton {
            text: qsTr("向下")
            Layout.preferredHeight: autoLoginSwitch.height
            onPressed: {
                CI.ptzControl(CEnum.DIRECTDOWN)
            }
            onReleased: {
                CI.ptzStop(CEnum.DIRECTDOWN)
            }
        }
        CuiFeatureButton {
            text: qsTr("向右")
            Layout.preferredHeight: autoLoginSwitch.height
            onPressed: {
                CI.ptzControl(CEnum.DIRECTRIGHT, 7)
            }
            onReleased: {
                CI.ptzStop(CEnum.DIRECTRIGHT)
            }
        }
    }

    CuiSeparator {
        _p: leftLayout
        Layout.topMargin: 24
        label: qsTr("对讲")
    }
    RowLayout{
        Layout.preferredWidth: leftLayout.width
        Layout.alignment: Qt.AlignHCenter
        ColumnLayout{
            id: voiceClayout
            Layout.fillHeight: true
            SwitchDelegate {
                id: voiceSwitch
                Layout.alignment: Qt.AlignTop
                font.pixelSize: CTheme.normalFontSize * 0.8
                text: qsTr("开启声音")
            }
            SwitchDelegate {
                id: talkSwitch
                Layout.alignment: Qt.AlignBottom
                font.pixelSize: CTheme.normalFontSize * 0.8
                text: qsTr("开启对讲")
            }
        }

        CuiDial {
            id: volumeDial
            font.pixelSize: CTheme.normalFontSize
            enabled: voiceSwitch.checked
            Layout.preferredHeight: 100
            Layout.preferredWidth: height
        }
    }
}

