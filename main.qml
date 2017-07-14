import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Habit Tracker")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page {
            ListView{
                anchors.fill: parent
                id: habitsView
                model: habitsModel
                delegate: TaskButton{
                    id: delegate
                    habit: position
                    text:name
                    }

                header: Label{
                    anchors.centerIn: parent
                    text: "Current Tasks"
                    font.pixelSize: 22
                    font.italic: true
                    color: "steelblue"
                }

            }
        }

        Page1 {
        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Tracker")
        }
        TabButton {
            text: qsTr("Stats")
        }
    }
}
