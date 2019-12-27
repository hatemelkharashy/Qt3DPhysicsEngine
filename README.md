# Qt3DPhysicsEngine
Qt3D Physics engine calculates linear motion for objects and can detect collision between them. It extends Qt3D backend and register components to the Qt3D aspect engine to do physics calculations on Entities. The components can be used directly in the QML.

Supported QML components :

PhysicsComponent : Used to provide physical data about the entity holding this component. It has four properties objectMass, isPhysical, initialVelocity and forceList. isPhysical holds true or false values and tells the Physics engine if this entity should act under physics law and forceList holds a list of forces acting on this entity.

BoxCollider : Used to define the size of the box collider. The box collider can be visualized as a cube or cuboid and when the Physics engine detects an overlap between two entities that have BoxCollider a collision is detected. It has one property colliderSize which is Vector3D that defines the size of the collider in x, y and z coordinates.
