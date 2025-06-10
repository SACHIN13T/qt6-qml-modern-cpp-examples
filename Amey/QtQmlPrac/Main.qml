import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        text: applicationData.getCurrentDateTime()
        Connections {
               target: applicationData
               onDataChanged: console.log("The application data changed!")
           }
    }
}
