/*
 *  Physics Component is a frontend component inheriting QComponent class. It is used as a QML component and hold some properties
 *  related to an entity's physical properties. When a property change in this frontend component a signal
 *  is sent the backend component with the change in the property.
 */
#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include <Qt3DCore/QComponent>
#include <QVector3D>
class PhysicsComponent : public Qt3DCore::QComponent
{
    Q_OBJECT
    /* List property that holds all the forces which act on the entity. Each entry in the list is a Vector3D for x,y and z
    * components of the force.
    */
    Q_PROPERTY(QList<QVariant> forceList READ forceList WRITE setForceList NOTIFY forceListChanged)
    //Property for the initial velocity of the entity.
    Q_PROPERTY(QVector3D initialVelocity READ initialVelocity WRITE setInitialVelocity)
    //Property that holds the mass of the object. It is required to apply law of motion F=m*a
    Q_PROPERTY(int objectMass READ objectMass WRITE setObjectMass NOTIFY objectMassChanged)
    //Property that states if the entity holding this physics component should act under the rules of physics or not.
    Q_PROPERTY(bool isPhysical READ isPhysical WRITE setIsPhysical NOTIFY isPhysicalChanged)
public:
    PhysicsComponent();

    // Getter functions for the properties defined above.
    QList<QVariant> forceList();
    QVector3D initialVelocity();
    int objectMass();
    bool isPhysical();
public slots:
    // Setter functions for the properties defined above.
    void setForceList(QList<QVariant> list);
    void setInitialVelocity(QVector3D initialVelocity);
    void setObjectMass(int mass);
    void setIsPhysical(bool physical);
signals:
    // Signals that are sent when the properties changes to notify any property binding to them.
    void forceListChanged(QList<QVariant> list);
    void objectMassChanged(int mass);
    void isPhysicalChanged(bool isPhysical);
private:
    /* This function overrides the base class function. It's purpose it to notify backend node of this frontend node
     * about the initial values of properties. This function is called Qt3D backend */
    Qt3DCore::QNodeCreatedChangeBasePtr createNodeCreationChange() const override;
private:
    // Member variables to hold the properties values.
    QList<QVariant> mForceList;
    QVector3D mInitialVelocity;
    int mObjectMass;
    bool mIsPhysical;
};
// Struct to hold this component properties data before sending it to the backend using createNodeCreationChange function
struct ForceData{
    int objectMass;
    bool isPhysical;
    QVector3D initialVelocity;
    QList<QVariant> forceList;
};
#endif // PHYSICSCOMPONENT_H
