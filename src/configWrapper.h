#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>
#include <KLocalizedContext>
#include <KLocalizedString>
#include <KConfig>

class ConfigWrapper: public QObject
{
  Q_OBJECT
  public:
    Q_INVOKABLE bool addConnection();
    Q_INVOKABLE bool deleteConnection();
};

