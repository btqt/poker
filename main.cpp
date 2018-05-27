#include <QApplication>

#include <QDebug>
#include <iostream>
#include "core/pokerdeck.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    std::shared_ptr<Deck> deck_ptr = std::make_shared<PokerDeck>();

    return app.exec();
}
