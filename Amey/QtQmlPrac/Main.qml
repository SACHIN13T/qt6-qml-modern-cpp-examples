import QtQuick 2.15
import QtQuick.Controls 2.15
import App.Models 1.0
import App.Config 1.0
import App.Visuals 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Expense Tracker"

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: Item {
            id: mainPage
            Column {
                anchors.centerIn: parent
                spacing: 20

                Text {
                    text: backendService.status
                    color: "White"
                }

                ExpenseItem {
                    id: item
                    description: "Lunch"
                    amount: 150.0
                }

                Text {
                    text: "Description: " + item.description + ", Amount: " + item.amount
                    color: "White"
                }

                ExpenseCircle { width: 100; height: 100 }

                Text {
                    text: "Currency: " + AppSettings.currency
                    color: "White"
                }

                Button {
                    text: "Add Expense"
                    onClicked: backendService.addExpense(item.description, item.amount)
                }

                Button {
                    text: "List View Model"
                    onClicked: stackView.push("ExpenseListView.qml")
                }
            }
        }
    }
}
