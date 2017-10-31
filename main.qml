import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    maximumHeight: 480
    minimumHeight: 480
    maximumWidth: 640
    minimumWidth: 640
    title: qsTr("A Star Example")

    GridView {
        anchors.centerIn: parent
        width: 400
        height: 400
        interactive: false

        cellHeight: 10
        cellWidth: 10

        model: gridviewModel

        delegate: GridCell {
            width: 10
            height: 10
            strColor: color
        }
    }

    Rectangle {
        id: rectControlPanel
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        width: 80
        height: 300

        border {
            color: "black"
            width: 1
        }

        Rectangle {
            id: btnStart

            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            width: 60
            height: 30

            border {
                color: "black"
                width: 1
            }

            Text {
                id: txtBtnStart
                anchors.centerIn: parent
                text: qsTr("Start")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    appController.clickedBtnStart()
                }
            }
        }

        Rectangle {
            id: btnReset

            anchors.top: btnStart.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            width: 60
            height: 30

            border {
                color: "black"
                width: 1
            }

            Text {
                id: txtBtnReset
                anchors.centerIn: parent
                text: qsTr("Reset")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    appController.clickedBtnReset()
                }
            }
        }
    }
}
