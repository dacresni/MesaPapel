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
    
    ListModel {
        id: connectionsModel
        // Each ListElement is an element on the list, containing information
        ListElement { name: "name"; description: "description"; port: 5432; hostname: "hostname" }
        ListElement { name: "name"; description: "description"; port: 5432; hostname: "hostname" }
    }
    // Initial page to be loaded on app load
    pageStack.initialPage: Qt.resolvedUrl("ConnectionList.qml")
}
