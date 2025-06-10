import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Hello App"

    Rectangle {
        anchors.fill: parent
        color: "#f0f0f0"

        Column {
            anchors.centerIn: parent
            spacing: 20

            Button {
                id:mybutton
                text: "Hello"
                onClicked: {
                    messageText.text = "This is Welcome code!"
                    mybutton.enabled = false
                }
            }


            Text {
                id: messageText
                text: ""
                font.pixelSize: 24
                color: "black"
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}

