#ifndef PHYSICSENTITY_H
#define PHYSICSENTITY_H
#include <Qt3DCore/QBackendNode>
#include <QVector3D>

// Forward declaration for physics aspect class
class PhysicsAspect;
/*
 *  PhysicsEntity is a backend for Entity component provided by Qt3D. It stores the IDs for the components the entity hold.
 *  By this way we can organize the components by Entity. The components this entity interested in are Transform,Collider and PhysicsComponent.
 */
class PhysicsEntity : public Qt3DCore::QBackendNode
{
public:
    PhysicsEntity(PhysicsAspect* aspect);
    /* This component implements this function that exist in the base class. When a node is created at the front end
     * The arbiter takes the data from createNodeCreationChange function and notifies this backend component through this function
     */
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) override;

    // Functions to check if this entity has certain component
    bool hasTransform();
    bool hasCollider();
    bool hasPhysicsComponent();
    // Function to set if this entity has collided with other entity or not
    void setCollisionState(bool value);
    // Getter function for the collision state
    bool getCollisionState();

    // Getter function for this entity components ID
    Qt3DCore::QNodeId getTransformId();
    Qt3DCore::QNodeId getColliderId();
    Qt3DCore::QNodeId getPhysicsComponentId();


private:
    Qt3DCore::QNodeId mTransformId;
    Qt3DCore::QNodeId mColliderId;
    Qt3DCore::QNodeId mPhysicsComponentId;
    bool mCollisionState=false;
    PhysicsAspect* mAspect;
};


class PhysicsEntityBackEndMapper : public Qt3DCore::QBackendNodeMapper{
public:
    PhysicsEntityBackEndMapper(PhysicsAspect* aspect);
    /*Virtual function provided by base class to create a new BackEnd component and must be overriden.
     * The QNodeCreatedChangeBasePtr argument holds the Id of the front end component that will be created
     * by this mapper and stored in a HashMap.
     */
    Qt3DCore::QBackendNode *create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const override;
    //Virtual function provided by base class to get a new BackEnd component and must be overriden
    Qt3DCore::QBackendNode *get(Qt3DCore::QNodeId id) const override;
    //Virtual function provided by base class to remove a new BackEnd component and must be overriden
    void destroy(Qt3DCore::QNodeId id) const override;
private:
    PhysicsAspect* mAspect;

};



#endif // PHYSICSENTITY_H
