#include "objectsCreate.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* objectsCreate::CreateRoad(
    const std::string& name,
    std::vector<VertexFormat> vertices,
    glm::vec3 color,
    std::vector<unsigned int> *indicesRoad,
    std::vector<VertexFormat> *verticesRoad,
    std::vector<VertexFormat> *verticesForCarFirst,
    glm::vec3 *internalPointForRandomCarFirst,
    std::vector<VertexFormat>* verticesForCarSecond,
    glm::vec3* internalPointForRandomCarSecond,
    std::vector<glm::vec3> *distances,
    bool fill)
{
    glm::vec3 distance;
    glm::vec3 P1, P2, P;

    std::vector<VertexFormat> newVerticesInternal, newVerticesExternal;
    glm::vec3 externalPoint, internalPoint;
    std::vector<VertexFormat> verticesMorePoints;

    float newPointX, newPointZ;

    for (size_t i = 0; i < vertices.size(); i++) {
        for (size_t j = 0; j < 125; j++) {
            if (i < vertices.size() - 1) {
                newPointX = vertices[i].position.x + 0.008f * j * (vertices[i + 1].position.x - vertices[i].position.x);
                newPointZ = vertices[i].position.z + 0.008f * j * (vertices[i + 1].position.z - vertices[i].position.z);
            }
            else {
                newPointX = vertices[i].position.x + 0.008f * j * (vertices[0].position.x - vertices[i].position.x);
                newPointZ = vertices[i].position.z + 0.008f * j * (vertices[0].position.z - vertices[i].position.z);
            }
            verticesMorePoints.push_back(glm::vec3(newPointX, 0.0f, newPointZ));
        }
    }

    for (size_t i = 0; i < verticesMorePoints.size(); i++) {
        P1 = verticesMorePoints[i].position;

        if (i < verticesMorePoints.size() - 1) {
            P2 = verticesMorePoints[i + 1].position;
        }
        else {
            P2 = verticesMorePoints[0].position;
        }
        distance = glm::normalize(P2 - P1);
        P = glm::normalize(glm::cross(distance, glm::vec3 (0, 1, 0)));

        externalPoint = P1 + 0.5f * P;
        internalPoint = P1 - 0.5f * P;

        newVerticesInternal.push_back(VertexFormat(internalPoint, color));
        newVerticesExternal.push_back(VertexFormat(externalPoint, color));
    }

    for (size_t i = 0; i < vertices.size(); i++) {
        P1 = vertices[i].position;

        if (i < vertices.size() - 1) {
            P2 = vertices[i + 1].position;
        }
        else {
            P2 = vertices[0].position;
        }

        distance = glm::normalize(P2 - P1);
        P = glm::normalize(glm::cross(distance, glm::vec3(0, 1, 0)));

        *internalPointForRandomCarFirst = P1 + 0.3f * P;
        *internalPointForRandomCarSecond = P1 + 0.00001f * P;

        (*verticesForCarFirst).push_back(*internalPointForRandomCarFirst);
        (*verticesForCarSecond).push_back(*internalPointForRandomCarSecond);
    }

    for (size_t i = 0; i < newVerticesExternal.size(); i++) {
        (*verticesRoad).push_back(newVerticesExternal[i]);
    }

    for(size_t i = 0; i < newVerticesInternal.size(); i++) {

        (*verticesRoad).push_back(newVerticesInternal[i]);
    }

    Mesh* road = new Mesh(name);

    for (int i = 0; i < newVerticesExternal.size(); i++) {

        if (i == newVerticesExternal.size() - 1) {
            (*indicesRoad).push_back(i);
            (*indicesRoad).push_back(newVerticesExternal.size() + i);
            (*indicesRoad).push_back(i + 1);

            (*indicesRoad).push_back(i);
            (*indicesRoad).push_back(i + 1);
            (*indicesRoad).push_back(0);
        }
        else {
            (*indicesRoad).push_back(i);
            (*indicesRoad).push_back(newVerticesExternal.size() + i);
            (*indicesRoad).push_back(newVerticesExternal.size() + i + 1);

            (*indicesRoad).push_back(i);
            (*indicesRoad).push_back(newVerticesExternal.size() + i + 1);
            (*indicesRoad).push_back(i + 1);
        }
    }

    road->InitFromData(*verticesRoad, *indicesRoad);
    return road;
}

Mesh* objectsCreate::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;

    for (size_t i = 0; i <= length; i++) {
        for (size_t j = 0; j <= length; j++) {
            vertices.push_back(VertexFormat(corner + glm::vec3(i, 0, j), color));
        }
    }

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices;

    for (size_t i = 0; i < length; i++) {
        int cnt = 0;

        while (cnt < length) {
            indices.push_back((i + 1) * 41 + cnt);
            indices.push_back(i * 41 + cnt);
            indices.push_back(i * 41 + cnt + 1);
            indices.push_back((i + 1) * 41 + cnt);
            indices.push_back(i * 41 + cnt + 1);
            indices.push_back((i + 1) * 41 + cnt + 1);
            cnt += 1;
        }
    }

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}