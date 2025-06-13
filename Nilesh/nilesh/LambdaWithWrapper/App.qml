import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Lambda with Wrapper Example"

    Column {
        spacing: 10
        anchors.centerIn: parent

        Button {
            text: "Click Me"
            onClicked: {
                // Using a lambda function to handle the button click
                console.log("Button was clicked!")
            }
        }

        Button {
            text: "Another Button"
            onClicked: {
                // Another lambda function for a different action
                console.log("Another button was clicked!")
            }
        }
    }
}