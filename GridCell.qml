import QtQuick 2.0

Item {

    property string strColor: ""

    Rectangle {
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            anchors.margins: 0.5

            color: strColor

            border {
                width: 0.5
                color: "gray"
            }
        }

        MouseArea {
            id: mouseareaCell
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onClicked: {
                if(mouse.button == Qt.LeftButton){
                    appController.clickedCell(index, 0)
                } else if(mouse.button == Qt.RightButton){
                    appController.clickedCell(index, 1)
                } else {

                }
            }
        }
    }
}
