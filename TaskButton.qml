import QtQuick 2.7
import QtQuick.Controls 2.0

Item {
    property int habit: 1
    property int task_id: -1
    property alias text: button.text
    width: parent.width
    height: 100
    Button {
        id: button

        text: "Unassigned"
        autoRepeat: false
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: modify.left
        anchors.left: parent.left
        onClicked: dbconnector.insertEvent(parent.task_id)
    }

    Button {
        id: modify
        text: "M"
        anchors.top: parent.top
        anchors.bottom: stats.top
        anchors.right: parent.right
        onClicked: print(parent.text+": Modify task: "+ parent.habit+ ", id" +parent.task_id)
    }

    Button {
        id: stats
        text: "S"
        anchors.top: modify.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onClicked: print(parent.text+": Stats: "+ parent.habit+ ", id" +parent.task_id)
    }

}
