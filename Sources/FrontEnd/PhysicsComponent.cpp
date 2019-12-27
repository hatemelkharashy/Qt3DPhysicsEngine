#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent():
    mInitialVelocity(QVector3D(0,0,0)),
    mIsPhysical(true)
{
    mIsPhysical = true;
}

QList<QVariant> PhysicsComponent::forceList()
{
    return mForceList;
}

QVector3D PhysicsComponent::initialVelocity()
{
    return mInitialVelocity;
}

int PhysicsComponent::objectMass()
{
    return mObjectMass;
}

bool PhysicsComponent::isPhysical()
{
    return mIsPhysical;
}

void PhysicsComponent::setForceList(QList<QVariant> list)
{
    mForceList = list;
    emit forceListChanged(list);
}

void PhysicsComponent::setInitialVelocity(QVector3D initialVelocity)
{
    mInitialVelocity = initialVelocity;
}

void PhysicsComponent::setObjectMass(int mass)
{
    mObjectMass = mass;
    emit objectMassChanged(mass);
}

void PhysicsComponent::setIsPhysical(bool physical)
{
    mIsPhysical = physical;
    emit isPhysicalChanged(physical);
}

Qt3DCore::QNodeCreatedChangeBasePtr PhysicsComponent::createNodeCreationChange() const
{
    // Creates a shared pointer "QNodeCreatedChangePtr" for "QNodeCreatedChange" event and gives it ForceData struct as template.
    Qt3DCore::QNodeCreatedChangePtr<ForceData> forceData = Qt3DCore::QNodeCreatedChangePtr<ForceData>::create(this);
    // The struct data are filled here from this component properties.
    forceData->data.forceList = mForceList;
    forceData->data.initialVelocity = mInitialVelocity;
    forceData->data.objectMass = mObjectMass;
    forceData->data.isPhysical = mIsPhysical;

    return forceData;
}
