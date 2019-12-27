/*
 *  BoxCollider Component is a frontend component inheriting QComponent class. It is used as a QML component and hold some properties
 *  related to an entity's collider size. The box collider shape is like a cube or a cuboid. When a property changes in this frontend component
 *  a signal is sent the backend component with the change in the property.
 */
#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include <Qt3DCore/QComponent>
#include <QVector3D>
class BoxCollider : public Qt3DCore::QComponent
{
    Q_OBJECT
    // Property that holds the collider size. The Vector3D defines the size in x,y and z components.
    Q_PROPERTY(QVector3D colliderSize READ colliderSize WRITE setColliderSize NOTIFY colliderSizeChanged)
    // Property that holds the collider position. The Vector3D defines the position in x,y and z for the center of the collider.
    Q_PROPERTY(QVector3D colliderPosition READ colliderPosition WRITE setColliderPosition NOTIFY colliderPositionChanged)
public:
    BoxCollider();
    // Getter functions for the properties defined above.
    QVector3D colliderSize();
    QVector3D colliderPosition();
public slots:
    // Setter functions for the properties defined above.
   void setColliderSize(QVector3D size);
   void setColliderPosition(QVector3D position);
signals:
   // Signals that are sent when the properties changes to notify any property binding to them.
   void colliderSizeChanged(QVector3D size);
   void colliderPositionChanged(QVector3D position);
private:
   /* This function overrides the base class function. It's purpose it to notify backend node of this frontend node
    * about the initial values of properties. This function is called Qt3D backend */
   Qt3DCore::QNodeCreatedChangeBasePtr createNodeCreationChange() const override;
private:
   // Member variables to hold the properties values.
    QVector3D mColliderSize;
    QVector3D mColliderPosition;
};
// Struct to hold this component properties data before sending it to the backend using createNodeCreationChange function
struct ColliderData{
    QVector3D colliderSize;
};

#endif // BOXCOLLIDER_H
