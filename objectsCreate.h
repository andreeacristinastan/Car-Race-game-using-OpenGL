#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace objectsCreate
{


    Mesh* CreateRoad(const std::string& name, std::vector<VertexFormat> vertices, glm::vec3 color, std::vector<unsigned int> *indicesRoad, std::vector<VertexFormat> *verticesRoad, std::vector<VertexFormat> *verticesForCarFirst,
                        glm::vec3 *internalPointForRandomCarFirst, std::vector<VertexFormat>* verticesForCarSecond, glm::vec3* internalPointForRandomCarSecond,
                        std::vector<glm::vec3> *distances, bool fill = false);
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
}
