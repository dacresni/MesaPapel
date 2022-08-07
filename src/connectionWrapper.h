#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>
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
    QString name;
    QString database;
    QString hostname;
    int port;
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
   KConfigGroup connections;

};

