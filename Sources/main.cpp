#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <Qt3DQuick/QQmlAspectEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include "Sources/FrontEnd/PhysicsComponent.h"
#include "Sources/FrontEnd/Colliders/BoxCollider.h"
#include "Sources/BackEnd/PhysicsAspect.h"
int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<PhysicsComponent>("PhysicsEngine",1,0,"PhysicsComponent");
    qmlRegisterType<BoxCollider>("PhysicsEngine",1,0,"BoxCollider");
    Qt3DExtras::Quick::Qt3DQuickWindow view;
    view.engine()->aspectEngine()->registerAspect(new PhysicsAspect);
    view.resize(1600, 800);
    view.engine()->qmlEngine()->rootContext()->setContextProperty("_window", &view);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
