#ifndef BOXCOLLIDERBACKEND_H
#define BOXCOLLIDERBACKEND_H
#include <Qt3DCore/QBackendNode>
#include <QVector3D>

/*
 *  BoxColliderBackEnd is a counterpart for frond end component . It stores collider size value
 *  it contains a getter for collider size that will be used by CollisionDetector to detect collision
 */

class BoxColliderBackEnd : public Qt3DCore::QBackendNode
{
public:
    BoxColliderBackEnd();
    /* This component implements this function that exist in the base class. When a node is created at the front end
     * The arbiter takes the data from createNodeCreationChange function and notifies this backend component through this function
     */
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) override;
    //Getter for collider size
    QVector3D getColliderSize();

private:
    QVector3D mColliderSize;

};
// Forward declaration for physics aspect class
class PhysicsAspect;
class BoxColliderBackEndMapper : public Qt3DCore::QBackendNodeMapper
{
public:
    BoxColliderBackEndMapper(PhysicsAspect* aspect);
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

#endif // BOXCOLLIDERBACKEND_H
