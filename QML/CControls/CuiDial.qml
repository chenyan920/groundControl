import QtQuick 2.12
import QtQuick.Controls 2.12
import "../Modules/"

Dial {
    id: control
    from: 0
    value: 0
    to: 100
    stepSize: 1

    Label {
        text: control.value.toFixed(0)
        color: "white"
        anchors.centerIn: parent
    }
}
