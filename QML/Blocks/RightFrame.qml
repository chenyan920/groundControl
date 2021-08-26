import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Imagine 2.12
import CI 1.0

import "../Modules/"
import "../CControls/"

ColumnLayout {
    id: rightLayout

    CuiSeparator {
        _p: rightLayout
        label: qsTr("设备信息")
    }

    RowLayout {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignRight
        Layout.topMargin: 10

        CuiGlowingLabel {
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            text: qsTr("温度")
        }
        Row {
            Layout.alignment: Qt.AlignRight

            CuiGlowingLabel {
                id: outsideTempValueLabel
                text: qsTr("31.2")
                font.pixelSize: CTheme.fontSizeExtraLarge
            }

            CuiGlowingLabel {
                text: qsTr("°C")
                font.pixelSize: Qt.application.font.pixelSize * 2.5
                anchors.baseline: outsideTempValueLabel.baseline
            }
        }
    }

    RowLayout {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignRight
        Layout.topMargin: 12

        CuiGlowingLabel {
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            text: qsTr("湿度")
        }
        Row {
            Layout.alignment: Qt.AlignRight

            CuiGlowingLabel {
                id: outsideHumidityValueLabel
                text: qsTr("70.0")
                font.pixelSize: CTheme.fontSizeExtraLarge
            }

            CuiGlowingLabel {
                text: qsTr(" %")
                font.pixelSize: Qt.application.font.pixelSize * 2.5
                anchors.baseline: outsideHumidityValueLabel.baseline
            }
        }
    }

    RowLayout {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignRight
        Layout.topMargin: 12

        CuiGlowingLabel {
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            text: qsTr("电量")
        }
        Row {
            Layout.alignment: Qt.AlignRight

            CuiGlowingLabel {
                id: batteryValue
                text: qsTr("75")
                font.pixelSize: CTheme.fontSizeExtraLarge
            }

            CuiGlowingLabel {
                text: qsTr(" %")
                font.pixelSize: Qt.application.font.pixelSize * 2.5
                anchors.baseline: batteryValue.baseline
            }
        }
    }

    CuiSeparator {
        _p: rightLayout
        Layout.topMargin: 24
        label: qsTr("设备控制")
    }
    GridLayout {
        rows: 2
        columns: 3
        Layout.alignment: Qt.AlignHCenter
        columnSpacing: 24
        flow: GridLayout.TopToBottom
        CuiFeatureButton {
            implicitHeight: width
            text: qsTr("前进")
        }
        CuiFeatureButton {
            implicitHeight: width
            text: qsTr("后退")
        }
        CuiFeatureButton {
            implicitHeight: width
            text: qsTr("左转")
        }
        CuiFeatureButton {
            implicitHeight: width
            text: qsTr("右转")
        }
        CuiFeatureButton {
            implicitHeight: width
            text: qsTr("启动")
        }
        CuiFeatureButton {
            implicitHeight: width
            text: qsTr("停止")
        }
    }

    CuiSeparator {
        _p: rightLayout
        Layout.topMargin: 24
        label: qsTr("调试信息")
    }

    RowLayout {
        implicitWidth: rightLayout.width
        Label {
            text: qsTr("视频流延迟:")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: CTheme.fontSizeMedium
        }
        Label {
            text: parseInt(700) + "ms"
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            font.pixelSize: CTheme.fontSizeMedium
        }
    }

    RowLayout {
        Layout.preferredWidth: rightLayout.width
        Label {
            text: qsTr("控制流延迟:")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: CTheme.fontSizeMedium
        }
        Label {
            text: parseInt(10) + "ms"
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
            font.pixelSize: CTheme.fontSizeMedium
        }
    }
    RowLayout {
        Layout.preferredWidth: rightLayout.width
        Label {
            text: qsTr("操作进度:")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: CTheme.fontSizeMedium
        }
        ProgressBar {
            id: control
            Layout.fillWidth: true
            Layout.fillHeight: true
            indeterminate: true
            background: Item{
                height: control.height
                width: control.width
                Rectangle{
                    height: 6
                    anchors.verticalCenter : parent.verticalCenter
                    width: parent.width
                    border.color: CTheme.colorMain
                    border.width: 1
                    color: "transparent"
                }
            }

            contentItem: Item{
                height: control.height
                width: control.width
                Rectangle{
                    height: 6
                    anchors.verticalCenter : parent.verticalCenter
                    width: parent.width * control.value
                    color: CTheme.colorMain
                }
            }
            from: 0
            to: 1
            value: 0.1
        }
    }
}
