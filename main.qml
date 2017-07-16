import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Habit Tracker")

    StackView {
        id: swipeView
        anchors.fill: parent

        initialItem: HabitsPage {
            id: listPage
        }


    }

    footer: TabBar {
        id: tabBar
        //currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Tracker")
        }
        TabButton {
            text: qsTr("Stats")
        }
    }
}
