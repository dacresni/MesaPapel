#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>
#include <QObject>
#include <QString>
#include <KLocalizedContext>
#include <KLocalizedString>
#include <KSharedConfig>

class Connection: public QObject {
  Q_OBJECT
  Q_PROPERTY(QString name READ name WRITE setName )
  Q_PROPERTY(QString database READ database WRITE setDatabase )
  Q_PROPERTY(QString hostname READ hostname WRITE setHostname )
  Q_PROPERTY(int port READ port WRITE setPort )
  public:
    explicit Connection(QObject *parent = nullptr);
    QString name();
    void setName(const QString &connectionname);
    QString database();
    void setDatabase(const QString &dbname);
    QString hostname();
    void setHostname(const QString &hostname);
    int port();
    void setPort(const QString &port);
  private:
    QString m_name;
    QString m_database;
    QString m_hostname;
    int m_port;
};

class ConnectionList: public QObject
{
  Q_OBJECT
  public:
    QQmlListProperty<Connection> connections();
    Q_INVOKABLE bool addConnection();
    Q_INVOKABLE bool EditConnection();
    Q_INVOKABLE bool deleteConnection();
  private:
   KSharedConfigPtr conf;
   // KConfigGroup connections;

};

