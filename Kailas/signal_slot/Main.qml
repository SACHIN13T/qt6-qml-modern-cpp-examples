import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Signal-Slot Example")

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: inputField
            width: 200
            placeholderText: "Enter text"
        }

        Button {
            text: "Send to C++"
            onClicked: {
                backend.receiveFromQml(inputField.text)
            }
        }

        Text {
            id: responseText
            text: ""
        }
    }

    Connections {
        target: backend
        function onSendToQml(message) {
            responseText.text = message
        }
    }
}
