#include "PhysicsController.h"


PhysicsController::PhysicsController(PhysicsAspect *aspect)
{
    mAspect = aspect;
}

void PhysicsController::calculateAfterCollisionData(PhysicsEntity *first, PhysicsEntity *second)
{

    PhysicsComponentBackEnd* component1 = mAspect->getEntityPhysicsComponent(first->peerId());
    PhysicsComponentBackEnd* component2 = mAspect->getEntityPhysicsComponent(second->peerId());
    float objectMass2 = component2->getObjectMass()/1000.0f;
    QVector3D objectVelocity2 = component2->getObjectVelocity();
    float objectMass1 = component1->getObjectMass()/1000.0f;
    QVector3D objectVelocity1 = component1->getObjectVelocity();

    QVector3D mAfterCollisionVelocity1 = ((objectMass1-objectMass2)/(objectMass1+objectMass2))*objectVelocity1
            + ((2*objectMass2)/(objectMass1+objectMass2))*objectVelocity2;
    QVector3D mAfterCollisionVelocity2 = ((2*objectMass1)/(objectMass1+objectMass2))*objectVelocity1
            -((objectMass1-objectMass2)/(objectMass1+objectMass2))*objectVelocity2;

    if(component1->getIsPhysical()){
        component1->setObjectVelocity(mAfterCollisionVelocity1);
        component1->setObjectForce(QVector3D());
    }
    if(component2->getIsPhysical()){
        component2->setObjectVelocity(mAfterCollisionVelocity2);
        component2->setObjectForce(QVector3D());
    }
}

void PhysicsController::calculateLinearMotion(PhysicsEntity *entity,long long int dt)
{
    if(!(entity->hasTransform()&&entity->hasPhysicsComponent()))
        return;

    //This part get PhysicsComponent and Transform from the entity using the id.
    PhysicsComponentBackEnd* component = mAspect->getEntityPhysicsComponent(entity->peerId());
    TransformBackEnd* transform = mAspect->getEntityTransform(entity->peerId());

    //If the entity is not phyiscal it should not act under physics of law
    if(!component->getIsPhysical())
        return;

    //Fetches the physics data from the PhysicsComponent
    QVector3D entityForce = component->getObjectForce();
    QVector3D entityVelocity = component->getObjectVelocity();
    int entityMass = component->getObjectMass();

    //Calculates the new Acceleration according to the law F=ma.
    QVector3D newEntityAcceleration = entityForce/(entityMass*1.0e-3);
    //Calculates the new Velocity according to law v=at.
    QVector3D newEntityVelocity = entityVelocity+newEntityAcceleration*dt*1.0e-9;
    //Calculates the new Displacement according to law s=vt;
    QVector3D newEntityDisplacement = entityVelocity*dt*1.0e-9;

    //Sets the new values inside the Physics component to be used in the next frame calculations.
    component->setObjectAcceleration(newEntityAcceleration);
    component->setObjectVelocity(newEntityVelocity);
    component->setObjectDisplacement(newEntityDisplacement);

    //Tells the Transform component to update the translation of the entity and notify the front end Transform component
    transform->updateTranslation(newEntityDisplacement);

}
