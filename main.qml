import QtQuick 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import Qt3D.Input 2.0
import PhysicsEngine 1.0
Entity{
    id :parentEntity


    components: [
        RenderSettings{
            activeFrameGraph: ForwardRenderer{
                camera:mainCamera
                clearColor: "cyan"
            }
        },
        InputSettings{}
    ]



    Camera{
        id : mainCamera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        nearPlane: 0.1
        farPlane: 1000.0
        position: Qt.vector3d(0.0, 20.0, 30.0)
        upVector: Qt.vector3d(0.0, 1.0, 0.0)

    }

    BouncingCubeExample{

    }

    FirstPersonCameraController{
        camera : mainCamera
    }



}
