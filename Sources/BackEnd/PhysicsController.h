#ifndef PHYSICSCONTROLLER_H
#define PHYSICSCONTROLLER_H
#include "PhysicsAspect.h"
#include "PhysicsEntity.h"
#include "PhysicsComponentBackEnd.h"
#include "TransformBackEnd.h"

/*
 * This class is not part of Qt3D library and does not inherit from any Qt class.
 * it is responsible for calculating the motion of an entity according to it's physics value inside PhysicsComponentBackend.
 * It also calculates the new velocity of the entity after colliding with another object
 */
class PhysicsController
{
public:
    PhysicsController(PhysicsAspect* spect);
    /* Takes two entities and calculate the velocity after collision. The supported collision is elastic and according to the law :
     *         (m1v1 + m2v2)before = (m1v1 +m2v2)after
     */
    void calculateAfterCollisionData(PhysicsEntity* first,PhysicsEntity* second);
    /* Calculates an entity new velocity, acceleration and displacement according to Newton's law F=ma
     */
    void calculateLinearMotion(PhysicsEntity* entity,long long int dt);
private:
    PhysicsAspect* mAspect;
};

#endif // PHYSICSCONTROLLER_H
