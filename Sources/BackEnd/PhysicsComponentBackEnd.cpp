#include "PhysicsComponentBackEnd.h"
#include "PhysicsAspect.h"
struct ForceData{
    int objectMass;
    bool isPhysical;
    QVector3D initialVelocity;
    QList<QVariant> forceList;
};

PhysicsComponentBackEnd::PhysicsComponentBackEnd()
    :Qt3DCore::QBackendNode(Qt3DCore::QBackendNode::ReadWrite)
{
    mIsPhysical = true;
}


QVector3D PhysicsComponentBackEnd::getObjectDisplacement()
{
    return mObjectDisplacement;
}

QVector3D PhysicsComponentBackEnd::getObjectVelocity()
{
    return mObjectVelocity;
}

QVector3D PhysicsComponentBackEnd::getObjectAcceleration()
{
    return mObjectAcceleration;
}

QVector3D PhysicsComponentBackEnd::getObjectForce()
{
    return mObjectForce;
}

int PhysicsComponentBackEnd::getObjectMass()
{
    return mObjectMass;
}

bool PhysicsComponentBackEnd::getIsPhysical()
{
    return mIsPhysical;
}

void PhysicsComponentBackEnd::setObjectVelocity(QVector3D velocity)
{
    mObjectVelocity = velocity;
}

void PhysicsComponentBackEnd::setObjectForce(QVector3D force)
{
    mObjectForce = force;
}

void PhysicsComponentBackEnd::setObjectAcceleration(QVector3D acceleration)
{
    mObjectAcceleration = acceleration;
}

void PhysicsComponentBackEnd::setObjectDisplacement(QVector3D displacement)
{
    mObjectDisplacement = displacement;
}

void PhysicsComponentBackEnd::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{
    auto forceData =  qSharedPointerCast<Qt3DCore::QNodeCreatedChange<ForceData>>(change);
    mObjectMass = forceData->data.objectMass;
    mIsPhysical = forceData->data.isPhysical;
    QList<QVariant> list = forceData->data.forceList;
    mObjectVelocity = forceData->data.initialVelocity;
    forceSummation(list);
}

void PhysicsComponentBackEnd::forceSummation(QList<QVariant> forceList)
{
    for(auto force : forceList){

        mObjectForce += force.value<QVector3D>();
    }
}

PhysicsComponentMapper::PhysicsComponentMapper(PhysicsAspect *aspect)
{
    mAspect = aspect;
}

Qt3DCore::QBackendNode *PhysicsComponentMapper::create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    PhysicsComponentBackEnd* node = new PhysicsComponentBackEnd();
    mAspect->addNewPhysicsComponentBackEnd(change->subjectId(),node);
    return node;
}

Qt3DCore::QBackendNode *PhysicsComponentMapper::get(Qt3DCore::QNodeId id) const
{
    return mAspect->getSavedPhysicsComponentBackEnd(id);
}

void PhysicsComponentMapper::destroy(Qt3DCore::QNodeId id) const
{
    PhysicsComponentBackEnd* node = mAspect->removeSavedPhysicsComponentBackEnd(id);
    delete node;
}
