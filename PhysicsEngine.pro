QT += 3dcore 3drender 3dinput 3dquick qml quick 3dquickextras
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/main.cpp \
    Sources/BackEnd/PhysicsAspect.cpp \
    Sources/BackEnd/TransformBackEnd.cpp \
    Sources/FrontEnd/Colliders/BoxCollider.cpp \
    Sources/BackEnd/Colliders/BoxColliderBackEnd.cpp \
    Sources/BackEnd/PhysicsEntity.cpp \
    Sources/BackEnd/Colliders/CollisionDetector.cpp \
    Sources/FrontEnd/PhysicsComponent.cpp \
    Sources/BackEnd/PhysicsComponentBackEnd.cpp \
    Sources/BackEnd/PhysicsJob.cpp \
    Sources/BackEnd/PhysicsController.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Sources/BackEnd/PhysicsAspect.h \
    Sources/BackEnd/TransformBackEnd.h \
    Sources/FrontEnd/Colliders/BoxCollider.h \
    Sources/BackEnd/Colliders/BoxColliderBackEnd.h \
    Sources/BackEnd/PhysicsEntity.h \
    Sources/BackEnd/Colliders/CollisionDetector.h \
    Sources/FrontEnd/PhysicsComponent.h \
    Sources/BackEnd/PhysicsComponentBackEnd.h \
    Sources/BackEnd/PhysicsJob.h \
    Sources/BackEnd/PhysicsController.h \


