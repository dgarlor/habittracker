import QtQuick 2.7

Page1Form {
    property string backPage:""
    property int position: -1

    buttonValidate.onClicked: {
        print("Button Pressed. Entered text: " + taskName.text+ " for position "+position);
    }
}
