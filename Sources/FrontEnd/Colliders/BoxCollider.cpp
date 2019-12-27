#include "BoxCollider.h"
#include <Qt3DCore/qentity.h>
BoxCollider::BoxCollider()
{

}

QVector3D BoxCollider::colliderSize()
{
return mColliderSize;
}

QVector3D BoxCollider::colliderPosition()
{
    return mColliderPosition;
}

void BoxCollider::setColliderSize(QVector3D size)
{
    mColliderSize = size;
    emit colliderSizeChanged(size);
}

void BoxCollider::setColliderPosition(QVector3D position)
{
    mColliderPosition = position;
    emit colliderPositionChanged(position);
}

Qt3DCore::QNodeCreatedChangeBasePtr BoxCollider::createNodeCreationChange() const
{
    // Creates a shared pointer "QNodeCreatedChangePtr" for "QNodeCreatedChange" event and gives it ColliderData struct as template.
    Qt3DCore::QNodeCreatedChangePtr<ColliderData> colliderData = Qt3DCore::QNodeCreatedChangePtr<ColliderData>::create(this);
    // The struct data are filled here from this component properties.
    colliderData->data.colliderSize = mColliderSize;

    return colliderData;
}
