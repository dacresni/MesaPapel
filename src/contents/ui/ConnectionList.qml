import QtQuick 2.6
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.2
import org.kde.kirigami 2.13 as Kirigami
Kirigami.Page {
    title: i18nc("@title:window", "Postgres Admin")
    Controls.Label {
        // Center label horizontally and vertically within parent element
        anchors.centerIn: parent
        text: i18n("Connections")
    }
    Kirigami.CardsListView {
        id: layout
        model: connectionsModel
        delegate: connectionsDelegate
    }
    actions.main: Kirigami.Action {
        id: addAction
        icon.name: "list-add"
        text: i18nc("@action:button", "Add kountdown")
        onTriggered: connectionsModel.append({
          name: "Kirigami Action added card!",
          description: "Congratulations, your Kirigami Action works!",
          port: 1000
        })
    }
    Component {
        id: connectionsDelegate
        Kirigami.AbstractCard {
            contentItem: Item {
                // implicitWidth/Height define the natural width/height of an item if no width or height is specified.
                // The setting below defines a component's preferred size based on its content
                implicitWidth: delegateLayout.implicitWidth
                implicitHeight: delegateLayout.implicitHeight
                GridLayout {
                    id: delegateLayout
                    anchors {
                        left: parent.left
                        top: parent.top
                        right: parent.right
                    }
                    rowSpacing: Kirigami.Units.largeSpacing
                    columnSpacing: Kirigami.Units.largeSpacing
                    columns: root.wideScreen ? 4 : 2

                    Kirigami.Heading {
                        Layout.fillHeight: true
                        level: 1
                        text: (port < 100000) ? port : i18n("%1 days", Math.round((port-Date.now())/86400000))
                    }

                    ColumnLayout {
                        Kirigami.Heading {
                            Layout.fillWidth: true
                            level: 2
                            text: name
                        }
                        Kirigami.Separator {
                            Layout.fillWidth: true
                            visible: description.length > 0
                        }
                        Controls.Label {
                            Layout.fillWidth: true
                            wrapMode: Text.WordWrap
                            text: description
                            visible: description.length > 0
                        }
                    }
                    Controls.Button {
                        Layout.alignment: Qt.AlignRight
                        Layout.columnSpan: 2
                        text: i18n("Edit")
                        // onClicked: to be done... soon!
                    }
                }
            }
        }
    }
}

