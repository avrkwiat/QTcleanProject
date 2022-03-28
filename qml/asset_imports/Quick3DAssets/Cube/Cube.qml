import QtQuick
import QtQuick3D
Node {
    id: rootNode
    Model {
        id: cube
        rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
        scale.x: 100
        scale.y: 100
        scale.z: 100
        source: "meshes/cube.mesh"

        DefaultMaterial {
            id: m_cube_material
            diffuseColor: "#ffcccccc"
        }
        materials: [
            m_cube_material
        ]
    }
}
