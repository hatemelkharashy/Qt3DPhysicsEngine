#ifndef TRANSFORMBACKEND_H
#define TRANSFORMBACKEND_H
#include <Qt3DCore/QBackendNode>
#include <Qt3DCore/QPropertyUpdatedChange>
#include <QQuaternion>

/*
 *  TransformBackEnd is a backend for Transform component provided by Qt3D. It stores translation and rotation values
 *  it contains a getter for translation that will be used by CollisionDetector to detect collision
 */
class TransformBackEnd : public Qt3DCore::QBackendNode
{
public:
    TransformBackEnd();
   // This function is called by PhysicsController class to update the translation by the displacement value.
   void updateTranslation(QVector3D displacement);
   // Getter for translation
   QVector3D getTranslation();
private:
   /* This component implements this function that exist in the base class. When a node is created at the front end
    * The arbiter takes the data from createNodeCreationChange function and notifies this backend component through this function
    */
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) override;
    //Sends the new translation value to front end Transform component.
    void notifyTranslationToFrontEnd();
private:
    QVector3D mTranslation;
    QQuaternion mRotation;
};

// Forward declaration for physics aspect class
class PhysicsAspect;
class TransformBackEndMapper : public Qt3DCore::QBackendNodeMapper{
public:
    TransformBackEndMapper(PhysicsAspect* aspect);
    /*Virtual function provided by base class to create a new BackEnd component and must be overriden.
     * The QNodeCreatedChangeBasePtr argument holds the Id of the front end component that will be created
     * by this mapper and stored in a HashMap.
     */
    Qt3DCore::QBackendNode *create(const Qt3DCore::QNodeCreatedChangeBasePtr &change) const override;
    //Virtual function provided by base class to get a new BackEnd component and must be overriden
    Qt3DCore::QBackendNode *get(Qt3DCore::QNodeId id) const override;
    //Virtual function provided by base class to remove a new BackEnd component and must be overriden
    void destroy(Qt3DCore::QNodeId id) const override;

private:
    PhysicsAspect* mAspect;

};
struct TransformData
{
    QQuaternion rotation;
    QVector3D scale;
    QVector3D translation;
};
#endif // TRANSFORMBACKEND_H
