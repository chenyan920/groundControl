import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import "../Modules/"
import "../CControls/"

RowLayout {
    property var _p: null
    property alias label: loginAbstractLabel.text

    Rectangle {
        color: CTheme.colorMain
        Layout.preferredWidth: (_p.width - loginAbstractLabel.width)/2 - 6
        Layout.preferredHeight: 1
        Layout.alignment: Qt.AlignVCenter
    }

    CuiGlowingLabel{
        id: loginAbstractLabel
        font.pixelSize: CTheme.smallFontSize
    }

    Rectangle {
        color: CTheme.colorMain
        Layout.preferredWidth: (_p.width - loginAbstractLabel.width)/2 - 6
        Layout.preferredHeight: 1
        Layout.alignment: Qt.AlignVCenter
    }
}
