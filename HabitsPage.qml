import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Page {
    id: listPage
    ListView{
        anchors.fill: parent
        id: habitsView
        onModelChanged: print ("Model changed")

        model: habitsModel
        delegate: TaskButton{
            id: delegate
            habit: position
            task_id : id
            text:name
            parentPage: listPage
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
