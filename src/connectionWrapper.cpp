#include "connectionWrapper.h"

Connection::Connection(QObject *parent):
  QObject(parent){}

QString Connection::name() {
  return m_name;
}

QString Connection::hostname() {
  return m_hostname;
}

QString Connection::database() {
  return m_database;
}

int Connection::port() {
  return m_port;
}


void setName(const QString &connectionname){
  
}
void setName(const QString &connectionname){}
void setDatabase(const QString &dbname){}
void setHostname(const QString &hostname){}
void setPort(const QString &port){}


ConfigWrapper::ConfigWrapper() {
    conf = KSharedConfig::openConfig(KConfig::SimpleConfig);
    KConfigGroup connections = conf.group("Connections");
}
bool ConfigWrapper::addConnection( QObject conn) {
    QString Name = conn.name;
    QString Database = conn.database;
    QString Hostname = conn.hostname;
    int Port = conn.port;

    if (!connections.hasGroup(Name)){
        KConfigGroup newConnection = conf.group(conn.name);
        newConnection.writeEntry("Name",Name);
        newConnection.writeEntry("Database",Database);
        newConnection.writeEntry("Hostname",Hostname);
        newConnection.writeEntry("Port",Port);
        config.sync();
    }
}
bool ConfigWrapper::deleteConnection(QObject conn) {
    qDebug() << "delete group:" << conn.name;
}
