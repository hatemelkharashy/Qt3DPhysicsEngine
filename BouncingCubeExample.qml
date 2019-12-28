import QtQuick 2.11
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import PhysicsEngine 1.0

Entity {

    CuboidMesh{
        id : cubeMesh
    }


    BoxCollider{
        id : cubeCollider
        colliderSize: Qt.vector3d(4.0,4.0,4.0)
    }
    BoxCollider{
        id : bouncingCubeCollider
        colliderSize: Qt.vector3d(2.0,2.0,2.0)
    }



    PhongMaterial{
        id : cubeMaterial1
        ambient : "red"
    }
    PhongMaterial{
        id : cubeMaterial2
        ambient : "green"
    }


    Transform{
        id : bouncingCubeTransform1
        translation: Qt.vector3d(15,15,-35)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform2
        translation: Qt.vector3d(-15,15,-35)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform3
        translation: Qt.vector3d(0,0,-35)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform4
        translation: Qt.vector3d(0,30,-35)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }

    Transform{
        id : bouncingCubeTransform5
        translation: Qt.vector3d(15,15,-65)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform6
        translation: Qt.vector3d(-15,15,-65)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform7
        translation: Qt.vector3d(0,0,-65)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform8
        translation: Qt.vector3d(0,30,-65)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }


    Transform{
        id : bouncingCubeTransform9
        translation: Qt.vector3d(15,0,-50)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform10
        translation: Qt.vector3d(-15,0,-50)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform11
        translation: Qt.vector3d(15,30,-50)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform12
        translation: Qt.vector3d(-15,30,-50)
        scale3D: Qt.vector3d(2.0,2.0,2.0)

    }



    Transform{
        id : staticCubeTransform1
        translation: Qt.vector3d(15,0,-35)
        scale3D: Qt.vector3d(4.0,4.0,4.0)

    }

    Transform{
        id : staticCubeTransform2
        translation: Qt.vector3d(15,30,-35)
        scale3D: Qt.vector3d(4.0,4.0,4.0)
    }
    Transform{
        id : staticCubeTransform3
        translation: Qt.vector3d(-15,0,-35)
        scale3D: Qt.vector3d(4.0,4.0,4.0)
    }
    Transform{
        id : staticCubeTransform4
        translation: Qt.vector3d(-15,30,-35)
        scale3D: Qt.vector3d(4.0,4.0,4.0)
    }



    Transform{
        id : staticCubeTransform5
        translation: Qt.vector3d(15,0,-65)
        scale3D: Qt.vector3d(4.0,4.0,4.0)

    }
    Transform{
        id : staticCubeTransform6
        translation: Qt.vector3d(15,30,-65)
        scale3D: Qt.vector3d(4.0,4.0,4.0)
    }
    Transform{
        id : staticCubeTransform7
        translation: Qt.vector3d(-15,0,-65)
        scale3D: Qt.vector3d(4.0,4.0,4.0)
    }
    Transform{
        id : staticCubeTransform8
        translation: Qt.vector3d(-15,30,-65)
        scale3D: Qt.vector3d(4.0,4.0,4.0)
    }





    PhysicsComponent{
        id : bouncingForceData1
        objectMass: 2000
//        forceList: [
//            Qt.vector3d(0.0,-200.0,0.0)
//        ]
        initialVelocity: Qt.vector3d(0.0,-10.0,0.0)
    }

    property real forceComponent  : 100.0
    PhysicsComponent{
        id : bouncingForceData2
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,-forceComponent,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData3
        objectMass: 2000
        forceList: [
            Qt.vector3d(forceComponent,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData4
        objectMass: 2000
        forceList: [
            Qt.vector3d(forceComponent,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData5
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,-forceComponent,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData6
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,-forceComponent,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData7
        objectMass: 2000
        forceList: [
            Qt.vector3d(forceComponent,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData8
        objectMass: 2000
        forceList: [
            Qt.vector3d(forceComponent,0.0,0.0)
        ]
    }

    PhysicsComponent{
        id : bouncingForceData9
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,0,-forceComponent)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData10
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,0.0,-forceComponent)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData11
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,0.0,-forceComponent)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData12
        objectMass: 2000
        forceList: [
            Qt.vector3d(0.0,0.0,-forceComponent)
        ]
    }




    PhysicsComponent{
        id : staticForceData1
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData2
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData3
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData4
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }

    PhysicsComponent{
        id : staticForceData5
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData6
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData7
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData8
        objectMass: 5000000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }


    Entity{
        id : bouncingCubeEntity1
        components: [bouncingForceData1,bouncingCubeCollider,bouncingCubeTransform1,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity2
        components: [bouncingForceData2,bouncingCubeCollider,bouncingCubeTransform2,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity3
        components: [bouncingForceData3,bouncingCubeCollider,bouncingCubeTransform3,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity4
        components: [bouncingForceData4,bouncingCubeCollider,bouncingCubeTransform4,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity5
        components: [bouncingForceData5,bouncingCubeCollider,bouncingCubeTransform5,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity6
        components: [bouncingForceData6,bouncingCubeCollider,bouncingCubeTransform6,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity7
        components: [bouncingForceData7,bouncingCubeCollider,bouncingCubeTransform7,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity8
        components: [bouncingForceData8,bouncingCubeCollider,bouncingCubeTransform8,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity9
        components: [bouncingForceData9,bouncingCubeCollider,bouncingCubeTransform9,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity10
        components: [bouncingForceData10,bouncingCubeCollider,bouncingCubeTransform10,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity11
        components: [bouncingForceData11,bouncingCubeCollider,bouncingCubeTransform11,cubeMesh,cubeMaterial1]

    }
    Entity{
        id : bouncingCubeEntity12
        components: [bouncingForceData12,bouncingCubeCollider,bouncingCubeTransform12,cubeMesh,cubeMaterial1]

    }



    Entity{
        id : staticcubeEntity1
        components: [staticForceData1,staticCubeTransform1,cubeCollider,cubeMesh,cubeMaterial2]

    }

    Entity{
        id : staticcubeEntity2
        components: [staticForceData2,staticCubeTransform2,cubeCollider,cubeMesh,cubeMaterial2]

    }
    Entity{
        id : staticcubeEntity3
        components: [staticForceData3,staticCubeTransform3,cubeCollider,cubeMesh,cubeMaterial2]

    }
    Entity{
        id : staticcubeEntity4
        components: [staticForceData4,staticCubeTransform4,cubeCollider,cubeMesh,cubeMaterial2]

    }
    Entity{
        id : staticcubeEntity5
        components: [staticForceData5,staticCubeTransform5,cubeCollider,cubeMesh,cubeMaterial2]

    }

    Entity{
        id : staticcubeEntity6
        components: [staticForceData6,staticCubeTransform6,cubeCollider,cubeMesh,cubeMaterial2]

    }
    Entity{
        id : staticcubeEntity7
        components: [staticForceData7,staticCubeTransform7,cubeCollider,cubeMesh,cubeMaterial2]

    }
    Entity{
        id : staticcubeEntity8
        components: [staticForceData8,staticCubeTransform8,cubeCollider,cubeMesh,cubeMaterial2]

    }
}
