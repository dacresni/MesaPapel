#include <QApplication>
#include <KConfig>
#include <KSharedConfig>
#include "configWrapper.h"

ConfigWrapper::ConfigWrapper() {
    conf = KSharedConfig::openConfig(KConfig::SimpleConfig);
}
bool ConfigWrapper::addConnection( QObject conn) {
    QString Name = conn.name;
    QString Database = conn.database;
    QString Hostname = conn.hostname;
    int Port = conn.port;

    if (!(conf->hasGroup(Name))){
        KConfigGroup newConnection = conf->group(conn->name);
        newConnection.writeEntry("Name",Name);
        newConnection.writeEntry("Database",Database);
        newConnection.writeEntry("Hostname",Hostname);
        newConnection.writeEntry("Port",Port);
        config->sync();
    }
}
bool ConfigWrapper::deleteConnection(QObject conn)
