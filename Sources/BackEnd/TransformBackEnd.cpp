#include "TransformBackEnd.h"
#include "PhysicsAspect.h"

TransformBackEndMapper::TransformBackEndMapper(PhysicsAspect *aspect)
{
    mAspect = aspect;
}

Qt3DCore::QBackendNode *TransformBackEndMapper::create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    TransformBackEnd* node = new TransformBackEnd();
    mAspect->addNewTransform(change->subjectId(),node);
    return node;
}

Qt3DCore::QBackendNode *TransformBackEndMapper::get(Qt3DCore::QNodeId id) const
{
    return mAspect->getSavedTransform(id);
}

void TransformBackEndMapper::destroy(Qt3DCore::QNodeId id) const
{
    TransformBackEnd* node = mAspect->removeSavedTransform(id);
    delete node;
}

TransformBackEnd::TransformBackEnd()
    :Qt3DCore::QBackendNode(Qt3DCore::QBackendNode::ReadWrite)
{

}

void TransformBackEnd::setTranslation(QVector3D translation)
{
    mPreviousTranslation = mTranslation;
    mTranslation = translation;
    notifyTranslationToFrontEnd();
}


QVector3D TransformBackEnd::getTranslation()
{
    return mTranslation;
}

QVector3D TransformBackEnd::getPreviousTranslation()
{
    return mPreviousTranslation;
}

void TransformBackEnd::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{

    const auto typedChange = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<TransformData>>(change);
    const auto &data = typedChange->data;
    mTranslation = data.translation;
}

void TransformBackEnd::notifyTranslationToFrontEnd()
{
    auto propertyUpdateEvent = Qt3DCore::QPropertyUpdatedChangePtr::create(peerId());
    propertyUpdateEvent->setDeliveryFlags(Qt3DCore::QSceneChange::DeliverToAll);
    propertyUpdateEvent->setPropertyName("translation");
    propertyUpdateEvent->setValue(QVariant::fromValue(mTranslation));
    notifyObservers(propertyUpdateEvent);
}

