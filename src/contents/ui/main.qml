// Includes relevant modules used by the QML
import QtQuick 2.6
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.2
import org.kde.kirigami 2.13 as Kirigami

// Base element, provides basic features needed for all kirigami applications
Kirigami.ApplicationWindow {
    // ID provides unique identifier to reference this element
    id: root

    // Window title
    // i18nc is useful for adding context for translators, also lets strings be changed for different languages
    title: i18nc("@title:window", "Postgres Admin")
    ListModel {
      id: connectionsModel
      ListElement { name: "example connectio name"; description: "example connection string "; date: 100 }
    }

    // Initial page to be loaded on app load
    pageStack.initialPage: Kirigami.Page {
        contentItem: Item {
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
				}
    }
}
