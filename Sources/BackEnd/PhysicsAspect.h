#ifndef PHYSICSASPECT_H
#define PHYSICSASPECT_H

/*
 *      PhysicsAspect class inherits from QAbstractAspect and it is responsible for creating Objects from Mappers
 *      and tells them which frontend component they would create backend components for. It also holds Hash that contains
 *      the backend object created by the mappers that can be access with the component ID. To help access the hash and modify
 *      them it contains functions to insert and remove form the hash and getter to retrieve the hash.
 *      The class also override the jobsToExecute function to provide jobs to the Aspect Engine.
 */

#include <Qt3DCore/QAbstractAspect>
#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qentity.h>
#include "PhysicsJob.h"

class TransformBackEnd;
class BoxColliderBackEnd;
class PhysicsComponentBackEnd;
class PhysicsEntity;
class CollisionDetector;
class PhysicsController;
class PhysicsAspect : public Qt3DCore::QAbstractAspect
{
public:
    PhysicsAspect();
    ~PhysicsAspect();

    //Functions to add, get and remove physics component
    void addNewPhysicsComponentBackEnd(Qt3DCore::QNodeId id,PhysicsComponentBackEnd *component);
    PhysicsComponentBackEnd* getSavedPhysicsComponentBackEnd(Qt3DCore::QNodeId id);
    PhysicsComponentBackEnd* removeSavedPhysicsComponentBackEnd(Qt3DCore::QNodeId id);
    QHash<Qt3DCore::QNodeId,PhysicsComponentBackEnd*> &physicsComponentBackEndList(){
        return mPhysicsComponentBackEndList;
    }

    //Functions to add, get and remove transform component
    void addNewTransform(Qt3DCore::QNodeId id,TransformBackEnd *transform);
    TransformBackEnd* getSavedTransform(Qt3DCore::QNodeId id);
    TransformBackEnd* removeSavedTransform(Qt3DCore::QNodeId id);
    QHash<Qt3DCore::QNodeId,TransformBackEnd*> &transformBackEndList(){
        return mTransformBackEndList;
    }

    //Functions to add, get and remove collider component
    void addNewBoxCollider(Qt3DCore::QNodeId id,BoxColliderBackEnd *collider);
    BoxColliderBackEnd* getSavedBoxCollider(Qt3DCore::QNodeId id);
    BoxColliderBackEnd* removeSavedBoxCollider(Qt3DCore::QNodeId id);
    QHash<Qt3DCore::QNodeId,BoxColliderBackEnd*> &boxColliderBackEndList(){
        return mBoxColliderBackEndList;
    }

    //Functions to add, get and remove physics entity component
    void addNewPhysicsEntity(Qt3DCore::QNodeId id,PhysicsEntity *entity);
    PhysicsEntity* getSavedPhysicsEntity(Qt3DCore::QNodeId id);
    PhysicsEntity* removeSavedPhysicsEntity(Qt3DCore::QNodeId id);
    QHash<Qt3DCore::QNodeId,PhysicsEntity*> &physicsEntityBackEndList(){
        return mPhysicsEntityBackEndList;
    }

    TransformBackEnd* getEntityTransform(Qt3DCore::QNodeId entityId);
    BoxColliderBackEnd* getEntityCollider(Qt3DCore::QNodeId entityId);
    PhysicsComponentBackEnd* getEntityPhysicsComponent(Qt3DCore::QNodeId entityId);


    CollisionDetector* getCollisionDetector();
    PhysicsController* getPhysicsController();
protected :
    // Function that returns list of jobs to be executed in the threadpool by the Aspect Engine
    QVector<Qt3DCore::QAspectJobPtr> jobsToExecute(qint64 time);
private:
    QHash<Qt3DCore::QNodeId,PhysicsComponentBackEnd *> mPhysicsComponentBackEndList;
    QHash<Qt3DCore::QNodeId,TransformBackEnd *> mTransformBackEndList;
    QHash<Qt3DCore::QNodeId,BoxColliderBackEnd *> mBoxColliderBackEndList;
    QHash<Qt3DCore::QNodeId,PhysicsEntity *> mPhysicsEntityBackEndList;
    qint64 mLastFrameTime;
    QSharedPointer<PhysicsJob> mPhysicsJob;
    CollisionDetector* mCollisionDetector;
    PhysicsController* mPhysicsController;

};

#endif // PHYSICSASPECT_H
