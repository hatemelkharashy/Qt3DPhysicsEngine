#include "CollisionDetector.h"

CollisionDetector::CollisionDetector(PhysicsAspect *aspect)
{
    mAspect = aspect;
}

void CollisionDetector::detectCollision()
{
    QHash<Qt3DCore::QNodeId,PhysicsEntity*>::iterator entityIterator1;
    QHash<Qt3DCore::QNodeId,PhysicsEntity*>::iterator entityIterator2;
    /* two for loops are used to check the collision between each two entities.
     * The function exclude entities that has no collider and transform components
     */
    for(entityIterator1 = mAspect->physicsEntityBackEndList().begin();entityIterator1!= mAspect->physicsEntityBackEndList().end();++entityIterator1){

        if(!isEntityValidForCollisionDetection(entityIterator1.value()))
            continue;

        for(entityIterator2 = entityIterator1+1;entityIterator2!= mAspect->physicsEntityBackEndList().end();++entityIterator2){

            if(!isEntityValidForCollisionDetection(entityIterator2.value()))
                continue;

            bool areColliding = BoxToBoxColliding(entityIterator1.value(),entityIterator2.value());

            if(areColliding)
                mAspect->getPhysicsController()->calculateAfterCollisionData(entityIterator1.value(),entityIterator2.value());
        }
    }
}

bool CollisionDetector::BoxToBoxColliding(PhysicsEntity *first, PhysicsEntity *second)
{

    //This part fetches the transform and collider component for each entity using the id.
    TransformBackEnd* transform1 = mAspect->getEntityTransform(first->peerId());
    TransformBackEnd* transform2 = mAspect->getEntityTransform(second->peerId());
    BoxColliderBackEnd* collider1 = mAspect->getEntityCollider(first->peerId());
    BoxColliderBackEnd* collider2 = mAspect->getEntityCollider(second->peerId());
    /*This part gets the translation of each entity from Transform component
     * It also gets the collider size from BoxCollider component.
     */
    QVector3D firstColliderPosition = transform1->getTranslation();
    QVector3D secondColliderPosition =  transform2->getTranslation();
    QVector3D firstColliderSize = collider1->getColliderSize();
    QVector3D secondColliderSize = collider2->getColliderSize();

    /*If the shape is visualized as a cube or cuboid
     * The values for max and min corresponds to the y value of the top and bottom faces of the cube or cuboid
     */
    float maxFirstY = firstColliderPosition.y() + firstColliderSize.y()/2;
    float minFirstY = firstColliderPosition.y() - firstColliderSize.y()/2;
    float maxSecondY = secondColliderPosition.y() + secondColliderSize.y()/2;
    float minSecondY = secondColliderPosition.y() - secondColliderSize.y()/2;

    /*If the shape is visualized as a cube or cuboid
     * The values for max and min corresponds to the x value of the left and right faces of the cube or cuboid.
     */

    float maxFirstX = firstColliderPosition.x() + firstColliderSize.x()/2;
    float minFirstX = firstColliderPosition.x() - firstColliderSize.x()/2;
    float maxSecondX = secondColliderPosition.x() + secondColliderSize.x()/2;
    float minSecondX = secondColliderPosition.x() - secondColliderSize.x()/2;

    /*If the shape is visualized as a cube or cuboid
     * The values for max and min corresponds to the z value of the front and back faces of the cube or cuboid
     */
    float maxFirstZ = firstColliderPosition.z() + firstColliderSize.z()/2;
    float minFirstZ = firstColliderPosition.z() - firstColliderSize.z()/2;
    float maxSecondZ = secondColliderPosition.z() + secondColliderSize.z()/2;
    float minSecondZ = secondColliderPosition.z() - secondColliderSize.z()/2;

    //The differences between the y values is calculated and if it less than zero this means the two entites overlap and collision is detected
    float dy1 = minSecondY-maxFirstY;
    float dy2 = minFirstY - maxSecondY;

    //The differences between the x values is calculated and if it less than zero this means the two entites overlap and collision is detected
    float dx1 = minSecondX-maxFirstX;
    float dx2 = minFirstX - maxSecondX;

    //The differences between the z values is calculated and if it less than zero this means the two entites overlap and collision is detected
    float dz1 = minSecondZ-maxFirstZ;
    float dz2 = minFirstZ - maxSecondZ;



    if(dy1>0.0f || dx1>0.0f || dz1>0.0f)
        return false;
    if(dy2>0.0f || dx2>0.0f|| dz2>0.0f)
        return false;

    return true;
}

bool CollisionDetector::isEntityValidForCollisionDetection(PhysicsEntity *entity)
{
    return (entity->hasTransform()&&entity->hasCollider());
}


