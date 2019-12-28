import QtQuick 2.11
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import PhysicsEngine 1.0

Entity {

    property real forceComponent  : 100.0
    CuboidMesh{
        id : cubeMesh
    }


    BoxCollider{
        id : cubeCollider
        colliderSize: Qt.vector3d(4.5,4.5,4.5)
    }
    BoxCollider{
        id : bouncingCubeCollider
        colliderSize: Qt.vector3d(2.5,2.5,2.5)
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
        translation: Qt.vector3d(0,0,-35)
        scale3D: Qt.vector3d(2.0,2.0,2.0)
    }
    Transform{
        id : bouncingCubeTransform2
        translation: Qt.vector3d(0,30,-35)
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








    PhysicsComponent{
        id : bouncingForceData1
        objectMass: 2000
        forceList: [
            Qt.vector3d(forceComponent,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : bouncingForceData2
        objectMass: 2000
        forceList: [
            Qt.vector3d(forceComponent,0.0,0.0)
        ]
    }






    PhysicsComponent{
        id : staticForceData1
        objectMass: 500000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData2
        objectMass: 500000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData3
        objectMass: 500000
        isPhysical: false
        forceList: [
            Qt.vector3d(0.0,0.0,0.0)
        ]
    }
    PhysicsComponent{
        id : staticForceData4
        objectMass: 500000
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

}
