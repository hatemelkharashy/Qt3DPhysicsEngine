#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "../PhysicsAspect.h"
#include "BoxColliderBackEnd.h"
#include "../TransformBackEnd.h"
#include "../PhysicsEntity.h"
#include "../PhysicsComponentBackEnd.h"
#include "../PhysicsController.h"

/*
 * This class is not part of Qt3D library and does not inherit from any Qt class.
 * it is responsible for detecting the collision between two entities. The currently supported collision detection is between two box colliders
 */
class CollisionDetector
{
public:
    CollisionDetector(PhysicsAspect* aspect);
    //This function is called inside the Aspect Job and starts looping on all Physics entity to check the collision between them.
    void detectCollision();
    //This function takes two entities and check if the two of them collides or not
    bool BoxToBoxColliding(PhysicsEntity* first,PhysicsEntity* second);
    void SendCollisionData(PhysicsEntity *first, PhysicsEntity *second);

private:
    bool isEntityValidForCollisionDetection(PhysicsEntity* entity);
private:
    PhysicsAspect* mAspect;
};

#endif // COLLISIONDETECTOR_H
