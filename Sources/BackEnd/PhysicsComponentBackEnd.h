#ifndef PHYSICSCOMPONENTBACKEND_H
#define PHYSICSCOMPONENTBACKEND_H
#include <Qt3DCore/QBackendNode>
#include <Qt3DCore/QPropertyUpdatedChange>
#include <QVector3D>

/*
 *  PhysicsComponentBackEnd is front end component counterpart. It stores the data sent from the front end via the arbiter
 *  It contains setter and getter function for this data that will be used by the Physics Controller to calculate the new
 *  phyiscal data for this component.
 */
class PhysicsComponentBackEnd: public Qt3DCore::QBackendNode
{


public:
    PhysicsComponentBackEnd();
    //Getter functions for this component member variables
    int getObjectMass();
    bool getIsPhysical();
    QVector3D getObjectForce();
    QVector3D getObjectAcceleration();
    QVector3D getObjectVelocity();
    QVector3D getObjectDisplacement();
    /*Setter functions for this component member variables. Those setters are for properties held only by
     * The backend component and are not exposed to the front end component. They will be modified by the physics controller
     */
    void setObjectForce(QVector3D force);
    void setObjectAcceleration(QVector3D acceleration);
    void setObjectVelocity(QVector3D velocity);
    void setObjectDisplacement(QVector3D displacement);

private:
    /* This component implements this function that exist in the base class. When a node is created at the front end
     * The arbiter takes the data from createNodeCreationChange function and notifies this backend component through this function
     */
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) override;
    // This function is called to calculate the resultant force acting on the entity from the force list
    void forceSummation(QList<QVariant> forceList);
private:
    int mObjectMass;
    bool mIsPhysical;
    // The resultant of the force in the force list sent from the front end component
    QVector3D mObjectForce;
    // Variables that will be manipulated by the PhysicsController class
    QVector3D mObjectVelocity,mObjectAcceleration,mObjectDisplacement;


};


// Forward declaration for physics aspect class
class PhysicsAspect;

/* The mapper class for PhysicsComponent implements base class functions to create, destroy and get PhysicsComponent
 */
class PhysicsComponentMapper : public Qt3DCore::QBackendNodeMapper
{
public:
    PhysicsComponentMapper(PhysicsAspect* aspect);
    /*Virtual function provided by base class to create a new BackEnd component and must be overriden.
     * The QNodeCreatedChangeBasePtr argument holds the Id of the front end component that will be created
     * by this mapper and stored in the HashMap.
     */
    Qt3DCore::QBackendNode *create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const override;
    //Virtual function provided by base class to get a new BackEnd component and must be overriden
    Qt3DCore::QBackendNode *get(Qt3DCore::QNodeId id) const override;
    //Virtual function provided by base class to remove a new BackEnd component and must be overriden
    void destroy(Qt3DCore::QNodeId id) const override;

private:
    PhysicsAspect* mAspect;
};



#endif // PHYSICSCOMPONENTBACKEND_H
