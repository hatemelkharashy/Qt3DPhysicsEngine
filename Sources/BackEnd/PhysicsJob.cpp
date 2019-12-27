#include "PhysicsJob.h"
#include "PhysicsAspect.h"
#include "TransformBackEnd.h"
#include "PhysicsEntity.h"
#include "PhysicsComponentBackEnd.h"
#include "Colliders/CollisionDetector.h"
#include "PhysicsController.h"
PhysicsJob::PhysicsJob(PhysicsAspect *aspect)
{
    mAspect = aspect;
}

void PhysicsJob::setDeltaTime(qint64 dt)
{
    mdt = dt;
}

void PhysicsJob::run()
{
    const auto physicEntitiesList = mAspect->physicsEntityBackEndList();
    mAspect->getCollisionDetector()->detectCollision();
    for (const auto physicEntity : physicEntitiesList) {
        mAspect->getPhysicsController()->calculateLinearMotion(physicEntity,mdt);
    }

}
