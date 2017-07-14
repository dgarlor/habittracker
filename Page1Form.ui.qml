import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias taskTitle: taskTitle
    property alias rowLayout: rowLayout
    property alias buttonValidate: buttonValidate

    ColumnLayout {
        id: columnLayout
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

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
                id: taskTitle
                text: ""
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
                      ListElement { key: "Day"; value: 1 }
                      ListElement { key: "Week"; value: 7 }
                      ListElement { key: "Month"; value: 30 }
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

        Button {
            id: buttonValidate
            text: qsTr("Validate")
            autoRepeat: false
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.fillWidth: true
        }
    }
}
