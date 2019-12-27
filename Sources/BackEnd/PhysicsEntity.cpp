#include "PhysicsEntity.h"
#include "PhysicsAspect.h"
#include "../FrontEnd/PhysicsComponent.h"
#include "../FrontEnd/Colliders/BoxCollider.h"
#include "TransformBackEnd.h"
#include "PhysicsComponentBackEnd.h"
#include "Qt3DCore/QNode"
struct QEntityData
{
    Qt3DCore::QNodeId parentEntityId;
    QVector<Qt3DCore::QNodeIdTypePair> componentIdsAndTypes;
};

PhysicsEntityBackEndMapper::PhysicsEntityBackEndMapper(PhysicsAspect *aspect)
{
    mAspect=aspect;
}

Qt3DCore::QBackendNode *PhysicsEntityBackEndMapper::create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    PhysicsEntity* node = new PhysicsEntity(mAspect);
    mAspect->addNewPhysicsEntity(change->subjectId(),node);
    return node;
}

Qt3DCore::QBackendNode *PhysicsEntityBackEndMapper::get(Qt3DCore::QNodeId id) const
{
    return mAspect->getSavedPhysicsEntity(id);
}



void PhysicsEntityBackEndMapper::destroy(Qt3DCore::QNodeId id) const
{
    PhysicsEntity* node = mAspect->removeSavedPhysicsEntity(id);
    delete node;
}

void PhysicsEntity::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{
    const auto typedChange = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<QEntityData>>(change);
    const auto &data = typedChange->data;
    QVector<Qt3DCore::QNodeIdTypePair> componentList = data.componentIdsAndTypes;
    for(auto component : componentList ){
        if (component.type->inherits(&PhysicsComponent::staticMetaObject))
            mPhysicsComponentId = component.id;
        else if (component.type->inherits(&BoxCollider::staticMetaObject))
            mColliderId = component.id;
        else if (component.type->inherits(&Qt3DCore::QTransform::staticMetaObject))
            mTransformId = component.id;
    }

}

bool PhysicsEntity::hasTransform()
{
    return !mTransformId.isNull();
}

bool PhysicsEntity::hasCollider()
{
    return !mColliderId.isNull();
}

bool PhysicsEntity::hasPhysicsComponent()
{
    return !mPhysicsComponentId.isNull();
}


Qt3DCore::QNodeId PhysicsEntity::getTransformId()
{
    return mTransformId;
}

Qt3DCore::QNodeId PhysicsEntity::getColliderId()
{
    return mColliderId;
}


Qt3DCore::QNodeId PhysicsEntity::getPhysicsComponentId()
{
    return mPhysicsComponentId;
}




void PhysicsEntity::setCollisionState(bool value)
{
    mCollisionState = value;
}



bool PhysicsEntity::getCollisionState()
{
    return mCollisionState;
}
PhysicsEntity::PhysicsEntity(PhysicsAspect* aspect)
    :Qt3DCore::QBackendNode(Qt3DCore::QBackendNode::ReadWrite)
{
    mAspect = aspect;
}
