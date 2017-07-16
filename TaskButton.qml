import QtQuick 2.7
import QtQuick.Controls 2.1

Item {
    property int habit: 1
    property int task_id: -1
    property alias text: button.text
    property var parentPage

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
        onClicked: dbconnector.insertAction(parent.task_id)
    }

    Button {
        id: modify
        text: "M"
        anchors.top: parent.top
        anchors.bottom: stats.top
        anchors.right: parent.right
        onClicked: {
            print(parent.text+": Modify task: "+ parent.habit+ ", id" +parent.task_id)
            parentPage.StackView.view.push(
                        "qrc:/Page1.qml",
                        { position:parent.habit }
                        )
        }
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
