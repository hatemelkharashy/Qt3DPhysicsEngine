#include "BoxColliderBackEnd.h"
#include "../PhysicsAspect.h"
struct ColliderData{
    QVector3D colliderSize;
};
BoxColliderBackEndMapper::BoxColliderBackEndMapper(PhysicsAspect* aspect)
{
    mAspect = aspect;
}

Qt3DCore::QBackendNode *BoxColliderBackEndMapper::create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    BoxColliderBackEnd* node = new BoxColliderBackEnd();
    mAspect->addNewBoxCollider(change->subjectId(),node);
    return node;
}

Qt3DCore::QBackendNode *BoxColliderBackEndMapper::get(Qt3DCore::QNodeId id) const
{
    return mAspect->getSavedBoxCollider(id);
}

void BoxColliderBackEndMapper::destroy(Qt3DCore::QNodeId id) const
{
    BoxColliderBackEnd* node = mAspect->removeSavedBoxCollider(id);
    delete node;
}

BoxColliderBackEnd::BoxColliderBackEnd()
    :Qt3DCore::QBackendNode(Qt3DCore::QBackendNode::ReadWrite)
{

}

void BoxColliderBackEnd::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{
    const auto typedChange = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<ColliderData>>(change);
    const auto &data = typedChange->data;
    mColliderSize = data.colliderSize;
}



QVector3D BoxColliderBackEnd::getColliderSize()
{
    return mColliderSize;
}




