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


void Connection::setName(const QString &connectionname){
  m_name = connectionname;
}
void Connection::setDatabase(const QString &dbname){
  m_database = dbname;
}
void Connection::setHostname(const QString &hostname){
  m_hostname = hostname;
}
void Connection::setPort(const int &port){
  m_port = port;
}


ConfigWrapper::ConfigWrapper() {
    conf = KSharedConfig::openConfig(KConfig::SimpleConfig);
    KConfigGroup connections = conf.group("Connections");
}
bool ConfigWrapper::addConnection( QObject conn) {
    QString Name = conn.m_name;
    QString Database = conn.m_database;
    QString Hostname = conn.m_hostname;
    int Port = conn.m_port;

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
