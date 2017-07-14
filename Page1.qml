import QtQuick 2.7

Page1Form {
    buttonValidate.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
    }
}
