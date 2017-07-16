import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
Page1Form {
    property string backPage:""
    property int position: -1

    buttonValidate.onClicked: {

        print("Button Pressed. Entered text: " + taskName.text+ " for position "+position);
        if( taskName.length == 0){
            print(" Cannot add task with length 0")
            return
        }

        dbconnector.insertTask(taskName.text, position)
        pop()
    }
}
