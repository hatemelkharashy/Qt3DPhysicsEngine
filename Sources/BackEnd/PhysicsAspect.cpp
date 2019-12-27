#include "PhysicsAspect.h"
#include "../FrontEnd/PhysicsComponent.h"
#include "../FrontEnd/Colliders/BoxCollider.h"
#include "TransformBackEnd.h"
#include "PhysicsComponentBackEnd.h"
#include "Colliders/BoxColliderBackEnd.h"
#include "PhysicsEntity.h"
#include "Colliders/CollisionDetector.h"
#include "PhysicsController.h"
PhysicsAspect::PhysicsAspect():mPhysicsJob(new PhysicsJob(this))
{

    mLastFrameTime=0;
    QSharedPointer<PhysicsComponentMapper> forceMapper = QSharedPointer<PhysicsComponentMapper>::create(this);
    QSharedPointer<TransformBackEndMapper> transformMapper = QSharedPointer<TransformBackEndMapper>::create(this);
    QSharedPointer<BoxColliderBackEndMapper> colliderMapper = QSharedPointer<BoxColliderBackEndMapper>::create(this);
    QSharedPointer<PhysicsEntityBackEndMapper> physicsEntityMapper = QSharedPointer<PhysicsEntityBackEndMapper>::create(this);
    registerBackendType<PhysicsComponent>(forceMapper);
    registerBackendType<BoxCollider>(colliderMapper);
    registerBackendType<Qt3DCore::QTransform>(transformMapper);
    registerBackendType<Qt3DCore::QEntity>(physicsEntityMapper);
    mCollisionDetector = new CollisionDetector(this);
    mPhysicsController = new PhysicsController(this);
}

PhysicsAspect::~PhysicsAspect()
{
    delete mCollisionDetector;
    delete mPhysicsController;
}


void PhysicsAspect::addNewPhysicsComponentBackEnd(Qt3DCore::QNodeId id, PhysicsComponentBackEnd *component)
{
    mPhysicsComponentBackEndList.insert(id,component);
}

PhysicsComponentBackEnd *PhysicsAspect::getSavedPhysicsComponentBackEnd(Qt3DCore::QNodeId id)
{
   return mPhysicsComponentBackEndList.value(id,nullptr);
}

PhysicsComponentBackEnd *PhysicsAspect::removeSavedPhysicsComponentBackEnd(Qt3DCore::QNodeId id)
{
   return mPhysicsComponentBackEndList.take(id);
}

void PhysicsAspect::addNewTransform(Qt3DCore::QNodeId id, TransformBackEnd *transform)
{
    mTransformBackEndList.insert(id,transform);
}

TransformBackEnd *PhysicsAspect::getSavedTransform(Qt3DCore::QNodeId id)
{
    return mTransformBackEndList.value(id,nullptr);
}

TransformBackEnd *PhysicsAspect::removeSavedTransform(Qt3DCore::QNodeId id)
{
    return mTransformBackEndList.take(id);
}

void PhysicsAspect::addNewBoxCollider(Qt3DCore::QNodeId id, BoxColliderBackEnd *collider)
{
    mBoxColliderBackEndList.insert(id,collider);
}

BoxColliderBackEnd *PhysicsAspect::getSavedBoxCollider(Qt3DCore::QNodeId id)
{
    return mBoxColliderBackEndList.value(id,nullptr);
}

BoxColliderBackEnd *PhysicsAspect::removeSavedBoxCollider(Qt3DCore::QNodeId id)
{
    return mBoxColliderBackEndList.take(id);
}

void PhysicsAspect::addNewPhysicsEntity(Qt3DCore::QNodeId id, PhysicsEntity *entity)
{
    mPhysicsEntityBackEndList.insert(id,entity);
}

PhysicsEntity *PhysicsAspect::getSavedPhysicsEntity(Qt3DCore::QNodeId id)
{
    return mPhysicsEntityBackEndList.value(id,nullptr);
}

PhysicsEntity *PhysicsAspect::removeSavedPhysicsEntity(Qt3DCore::QNodeId id)
{
    return mPhysicsEntityBackEndList.take(id);
}

TransformBackEnd *PhysicsAspect::getEntityTransform(Qt3DCore::QNodeId entityId)
{

    PhysicsEntity* entity = getSavedPhysicsEntity(entityId);
    if(!entity->hasTransform())
        return nullptr;
    Qt3DCore::QNodeId transformId = entity->getTransformId();
    TransformBackEnd* node = getSavedTransform(transformId);
    return node;

}

BoxColliderBackEnd *PhysicsAspect::getEntityCollider(Qt3DCore::QNodeId entityId)
{

    PhysicsEntity* entity = getSavedPhysicsEntity(entityId);
    if(!entity->hasCollider())
        return nullptr;
    Qt3DCore::QNodeId colliderId = entity->getColliderId();
    BoxColliderBackEnd* node = getSavedBoxCollider(colliderId);
    return node;

}

PhysicsComponentBackEnd *PhysicsAspect::getEntityPhysicsComponent(Qt3DCore::QNodeId entityId)
{

    PhysicsEntity* entity = getSavedPhysicsEntity(entityId);
    if(!entity->hasPhysicsComponent())
        return nullptr;
    Qt3DCore::QNodeId physicsComponentId = entity->getPhysicsComponentId();
    PhysicsComponentBackEnd* node = getSavedPhysicsComponentBackEnd(physicsComponentId);
    return node;

}

CollisionDetector *PhysicsAspect::getCollisionDetector()
{
    return mCollisionDetector;
}

PhysicsController *PhysicsAspect::getPhysicsController()
{
    return mPhysicsController;
}

QVector<Qt3DCore::QAspectJobPtr> PhysicsAspect::jobsToExecute(qint64 time)
{
    auto dt = time - mLastFrameTime;
    mLastFrameTime = time;
    mPhysicsJob->setDeltaTime(dt);
    return {mPhysicsJob};
}
