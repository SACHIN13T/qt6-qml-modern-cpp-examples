import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    id: root
    width: 400
    height: 400

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Button {
                text: "Back"
                onClicked: stackView.pop()
            }
            Label {
                text: "Expense List"
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: expensemodel
        delegate: Rectangle {
            width: parent.width
            height: 50
            color: index % 2 === 0 ? "#f0f0f0" : "#d0d0d0"
            Row {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 20

                Text { text: description; font.pixelSize: 16 }
                Text { text: "₹ " + amount; font.pixelSize: 16 }
            }
        }
    }
}
