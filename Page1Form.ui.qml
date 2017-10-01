import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    property alias rowLayout: rowLayout
    property alias buttonValidate: buttonValidate
    property alias taskName: taskName
    property alias buttonCancel: buttonCancel
    visible: true

    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        transformOrigin: Item.Top
        anchors.rightMargin: 5
        anchors.leftMargin: 4
        anchors.topMargin: 5

        RowLayout {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
            anchors.top: parent.top

            Text {
                id: textTaskName
                text: qsTr("Task Name")
                Layout.fillWidth: false
                Layout.rowSpan: 1
                font.pixelSize: 16
            }

            TextField {
                id: taskName
                Layout.fillWidth: true
                placeholderText: qsTr("Set your task")
            }
        }

        RowLayout {
            id: rowLayout
            width: 100
            height: 100
            transformOrigin: Item.Center
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillHeight: false
            Layout.fillWidth: true

            ListModel {
                id: modelDuration
                ListElement {
                    key: "Day"
                    value: 1
                }
                ListElement {
                    key: "Week"
                    value: 7
                }
                ListElement {
                    key: "Month"
                    value: 30
                }
            }

            SpinBox {
                id: spinTaskTimes
            }

            Text {
                id: text1
                text: qsTr("times a ")
                font.pixelSize: 12
            }

            ComboBox {
                id: comboTaskDuration
                currentIndex: 1
                textRole: "key"
                model: modelDuration
            }
        }
    }

    ColumnLayout {
        y: 410
        anchors.right: parent.right
        anchors.rightMargin: 4
        anchors.left: parent.left
        anchors.leftMargin: 4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0


        Text {
            id: textValidate
            text: qsTr("Please, set the Task parameters before validation")
            visible: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            font.pixelSize: 12
        }
        RowLayout {
            id: rowLayout1
            width: 100
            height: 100


            Button {
                id: buttonValidate
                width: 100
                text: qsTr("Validate")
                Layout.preferredHeight: 50
                autoRepeat: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                Layout.fillHeight: false
                Layout.fillWidth: true
            }
            Button {
                id: buttonCancel
                x: 500
                width: 100
                text: qsTr("Cancel")
                Layout.fillWidth: true
            }
        }
    }
}
