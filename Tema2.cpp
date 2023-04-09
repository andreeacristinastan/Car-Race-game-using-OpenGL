#include "lab_m1/Tema2/Tema2.h"
#include "lab_m1/Tema2/objectsCreate.h"
#include "lab_m1/Tema2/transform3D.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{
    polygonMode = GL_FILL;

    right = -2.f;
    left = 2.f;
    bottom = -2.f;
    top = 2.f;
    fov = RADIANS(90);
    angularStepOy = 0.0f;
    translateZ = carZ;
    translateX = carX;
    translateY = carY;

    renderCameraTarget = false;

    camera = new implemented::Camera();
    camera->Set(glm::vec3(carX - 0.4f, carY + 0.25f, carZ), glm::vec3(carX, carY + 0.25f, carZ), glm::vec3(0, 1, 0));

    camera->distanceToTarget = 0.4f;

    vertices = {
        glm::vec3(9.97f, 0.0f, 0.19f),
        glm::vec3(9.81f, 0.0f, 0.85f),
        glm::vec3(9.53f, 0.0f, 1.49f),
        glm::vec3(9.0f, 0.0f, 2.0f),
        glm::vec3(8.49f, 0.0f, 2.35f),
        glm::vec3(7.79f, 0.0f, 2.73f),
        glm::vec3(7.21f, 0.0f, 3.09f),
        glm::vec3(6.81f, 0.0f, 3.47f),
        glm::vec3(6.61f, 0.0f, 3.95f),
        glm::vec3(6.51f, 0.0f, 4.69f),
        glm::vec3(6.05f, 0.0f, 5.49f),
        glm::vec3(5.51f, 0.0f, 5.73f),
        glm::vec3(4.85f, 0.0f, 5.49f),
        glm::vec3(4.49f, 0.0f, 5.11f),
        glm::vec3(4.09f, 0.0f, 4.65f),
        glm::vec3(3.63f, 0.0f, 4.13f),
        glm::vec3(3.05f, 0.0f, 3.73f),
        glm::vec3(2.41f, 0.0f, 3.73f),
        glm::vec3(1.73f, 0.0f, 3.91f),
        glm::vec3(1.27f, 0.0f, 4.39f),
        glm::vec3(0.73f, 0.0f, 4.89f),
        glm::vec3(0.33f, 0.0f, 5.17f),
        glm::vec3(-0.13f, 0.0f, 5.31f),
        glm::vec3(-0.61f, 0.0f, 5.07f),
        glm::vec3(-0.95f, 0.0f, 4.63f),
        glm::vec3(-1.23f, 0.0f, 4.23f),
        glm::vec3(-1.43f, 0.0f, 3.71f),
        glm::vec3(-1.67f, 0.0f, 3.25f),
        glm::vec3(-2.0f, 0.0f, 3.0f),
        glm::vec3(-2.49f, 0.0f, 2.93f),
        glm::vec3(-3.0f, 0.0f, 3.0f),
        glm::vec3(-3.41f, 0.0f, 3.25f),
        glm::vec3(-3.91f, 0.0f, 3.53f),
        glm::vec3(-4.25f, 0.0f, 3.81f),
        glm::vec3(-4.65f, 0.0f, 3.99f),
        glm::vec3(-5.13f, 0.0f, 3.99f),
        glm::vec3(-5.57f, 0.0f, 3.93f),
        glm::vec3(-6.15f, 0.0f, 3.77f),
        glm::vec3(-6.67f, 0.0f, 3.61f),
        glm::vec3(-7.29f, 0.0f, 3.63f),
        glm::vec3(-7.95f, 0.0f, 3.59f),
        glm::vec3(-8.39f, 0.0f, 3.41f),
        glm::vec3(-8.83f, 0.0f, 2.87f),
        glm::vec3(-8.87f, 0.0f, 2.33f),
        glm::vec3(-8.77f, 0.0f, 1.71f),
        glm::vec3(-8.55f, 0.0f, 1.21f),
        glm::vec3(-8.33f, 0.0f, 0.81f),
        glm::vec3(-8.35f, 0.0f, 0.39f),
        glm::vec3(-8.41f, 0.0f, -0.13f),
        glm::vec3(-8.41f, 0.0f, -0.63f),
        glm::vec3(-8.19f, 0.0f, -1.07f),
        glm::vec3(-7.85f, 0.0f, -1.55f),
        glm::vec3(-7.37f, 0.0f, -1.79f),
        glm::vec3(-6.77f, 0.0f, -2.05f),
        glm::vec3(-6.13f, 0.0f, -2.15f),
        glm::vec3(-5.57f, 0.0f, -2.37f),
        glm::vec3(-5.13f, 0.0f, -2.71f),
        glm::vec3(-4.61f, 0.0f, -2.91f),
        glm::vec3(-4.07f, 0.0f, -2.85f),
        glm::vec3(-3.63f, 0.0f, -2.69f),
        glm::vec3(-3.17f, 0.0f, -2.47f),
        glm::vec3(-2.71f, 0.0f, -2.35f),
        glm::vec3(-2.23f, 0.0f, -2.27f),
        glm::vec3(-1.77f, 0.0f, -2.09f),
        glm::vec3(-1.41f, 0.0f, -1.81f),
        glm::vec3(-1.05f, 0.0f, -1.47f),
        glm::vec3(-0.55f, 0.0f, -1.39f),
        glm::vec3(-0.11f, 0.0f, -1.59f),
        glm::vec3(0.31f, 0.0f, -1.93f),
        glm::vec3(0.63f, 0.0f, -2.25f),
        glm::vec3(1.11f, 0.0f, -2.51f),
        glm::vec3(1.71f, 0.0f, -2.63f),
        glm::vec3(2.17f, 0.0f, -2.67f),
        glm::vec3(2.65f, 0.0f, -2.59f),
        glm::vec3(3.13f, 0.0f, -2.65f),
        glm::vec3(3.55f, 0.0f, -2.49f),
        glm::vec3(3.85f, 0.0f, -2.17f),
        glm::vec3(4.17f, 0.0f, -1.79f),
        glm::vec3(4.57f, 0.0f, -1.55f),
        glm::vec3(5.15f, 0.0f, -1.59f),
        glm::vec3(5.53f, 0.0f, -1.77f),
        glm::vec3(5.75f, 0.0f, -2.11f),
        glm::vec3(5.95f, 0.0f, -2.47f),
        glm::vec3(6.21f, 0.0f, -2.79f),
        glm::vec3(6.61f, 0.0f, -3.13f),
        glm::vec3(7.23f, 0.0f, -3.33f),
        glm::vec3(7.85f, 0.0f, -3.37f),
        glm::vec3(8.45f, 0.0f, -3.15f),
        glm::vec3(8.89f, 0.0f, -2.49f),
        glm::vec3(9.15f, 0.0f, -1.79f),
        glm::vec3(9.53f, 0.0f, -1.07f),
        glm::vec3(9.87f, 0.0f, -0.31f)
    };

    Mesh* road = objectsCreate::CreateRoad("road", vertices, glm::vec3(NormalizedRGB(64, 64, 64)), &indicesRoad, &verticesRoad, &verticesForCarFirst,
                                            &internalPointForRandomCarFirst, &verticesForCarSecond, &internalPointForRandomCarSecond, &distances, true);
    AddMeshToList(road);

    firstPoint = verticesForCarFirst[0].position;
    countPoints1 = 0, countPoints2 = 10, countPoints3 = 50, countPoints4 = 25, countPoints5 = 44, countPoints6 = 37;
    {
        Mesh* mesh = new Mesh("car");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "volk"), "volkswagen_beetle_toy_SF.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("car2");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "car3"), "car2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("car3");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "car4"), "car2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("car4");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "car5"), "car2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("car5");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "car6"), "car2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("car6");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "car7"), "car2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("tree");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "trees"), "lowpolytree.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    Mesh* grass = objectsCreate::CreateSquare("grass", glm::vec3(-20, -0.02f, -20), 40, glm::vec3(NormalizedRGB(121, 92, 50)), true);
    AddMeshToList(grass);

    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(30, 30, resolution.x / 5.f, resolution.y / 5.f);

    projectionMatrix = glm::perspective(fov, window->props.aspectRatio, 0.01f, 200.0f);

    {
        Shader* shader = new Shader("LabShaderSimple");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShaderS.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }

    {
        Shader* shader = new Shader("LabShaderVertexColor");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShaderVC.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(135./255, 206. / 255, 250. / 255, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

bool Tema2::CheckInside(glm::vec3 myPoint)
{
    for (size_t i = 0; i < indicesRoad.size(); i += 3) {
        glm::vec3 firstPoint, secondPoint, thirdPoint, firstCheck, secondCheck, thirdCheck;

        firstPoint = verticesRoad[indicesRoad[i]].position;
        secondPoint = verticesRoad[indicesRoad[i + 1]].position;
        thirdPoint = verticesRoad[indicesRoad[i + 2]].position;
           
        firstCheck = thirdPoint - firstPoint;
        secondCheck = secondPoint - firstPoint;
        thirdCheck = myPoint - firstPoint;

        float firstDot = glm::dot(firstCheck, firstCheck);
        float secondDot = glm::dot(firstCheck, secondCheck);
        float thirdDot = glm::dot(firstCheck, thirdCheck);
        float fourthDot = glm::dot(secondCheck, secondCheck);
        float fifthDot = glm::dot(secondCheck, thirdCheck);

        float invDenom = 1.0f / (firstDot * fourthDot - secondDot * secondDot);
        float barycentricFirst = (fourthDot * thirdDot - secondDot * fifthDot) * invDenom;
        float barycentricSecond = (firstDot * fifthDot - secondDot * thirdDot) * invDenom;

        if (barycentricFirst >= 0 && barycentricSecond >= 0 && (barycentricFirst + barycentricSecond) < 1) {
            return true;
        }
    }
    return false;
}

void::Tema2::RenderScene(float deltaTimeSeconds)
{
    {
        glm::mat3 modelMatrix = glm::mat3(1);
        RenderMesh(meshes["grass"], shaders["LabShaderVertexColor"], modelMatrix);
    }
   
    RouteRandomCars(&countPoints1, verticesForCarFirst, deltaTimeSeconds, &translateXForRandomCarsF, &translateZForRandomCarsF, &timeSpentBetweenPointsF, &angleForCars);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateXForRandomCarsF, 0.0f, translateZForRandomCarsF));
        modelMatrix *= transform3D::RotateOY(angleForCars);

        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.03f, 0.03f, 0.03f));
        RenderMesh(meshes["car2"], shaders["LabShaderSimple"], modelMatrix);
    }

    RouteRandomCars(&countPoints2, verticesForCarSecond, deltaTimeSeconds, &translateXForRandomCarsS, &translateZForRandomCarsS, &timeSpentBetweenPointsS, &angleForCars);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateXForRandomCarsS, 0.0f, translateZForRandomCarsS));
        modelMatrix *= transform3D::RotateOY(angleForCars);

        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.03f, 0.03f, 0.03f));
        RenderMesh(meshes["car3"], shaders["LabShaderSimple"], modelMatrix);
    }

    RouteRandomCars(&countPoints3, vertices, deltaTimeSeconds, &translateXForRandomCarsT, &translateZForRandomCarsT, &timeSpentBetweenPointsT, &angleForCars);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateXForRandomCarsT, 0.0f, translateZForRandomCarsT));
        modelMatrix *= transform3D::RotateOY(angleForCars);

        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.03f, 0.03f, 0.03f));
        RenderMesh(meshes["car4"], shaders["LabShaderSimple"], modelMatrix);
    }

    RouteRandomCars(&countPoints4, verticesForCarFirst, deltaTimeSeconds, &translateXForRandomCars4, &translateZForRandomCars4, &timeSpentBetweenPoints4, &angleForCars);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateXForRandomCars4, 0.0f, translateZForRandomCars4));
        modelMatrix *= transform3D::RotateOY(angleForCars);

        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.03f, 0.03f, 0.03f));
        RenderMesh(meshes["car5"], shaders["LabShaderSimple"], modelMatrix);
    }

    RouteRandomCars(&countPoints5, verticesForCarSecond, deltaTimeSeconds, &translateXForRandomCars5, &translateZForRandomCars5, &timeSpentBetweenPoints5, &angleForCars);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateXForRandomCars5, 0.0f, translateZForRandomCars5));
        modelMatrix *= transform3D::RotateOY(angleForCars);

        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.03f, 0.03f, 0.03f));
        RenderMesh(meshes["car6"], shaders["LabShaderSimple"], modelMatrix);
    }

    RouteRandomCars(&countPoints6, vertices, deltaTimeSeconds, &translateXForRandomCars6, &translateZForRandomCars6, &timeSpentBetweenPoints6, &angleForCars);

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateXForRandomCars6, 0.0f, translateZForRandomCars6));
        modelMatrix *= transform3D::RotateOY(angleForCars);

        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.03f, 0.03f, 0.03f));
        RenderMesh(meshes["car2"], shaders["LabShaderSimple"], modelMatrix);
    }

    {
        glm::mat3 modelMatrix = glm::mat3(1);
        RenderMesh(meshes["road"], shaders["LabShaderVertexColor"], modelMatrix);
    }

    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateX, translateY - 0.01f, translateZ);
    modelMatrix *= transform3D::RotateOY(angularStepOy);
    modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(0, 1, 0));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f, 0.15f, 0.15f));

    RenderMesh(meshes["car"], shaders["LabShaderSimple"], modelMatrix);

    for (size_t i = 0; i < vertices.size(); i++) {
        if (i % 2 == 0) {
            P1 = vertices[i].position;

            if (i < vertices.size() - 1) {
                P2 = vertices[i + 1].position;

            }
            else {
                P2 = vertices[0].position;
            }
            distance = glm::normalize(P2 - P1);

            P = glm::cross(distance, glm::vec3(0, 1, 0));

            externalPointForTrees = P1 + 0.9f * P;
            internalPointForTrees = P1 - 0.7f * P;

            {
                glm::mat4 modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.15f, 0.0f));

                modelMatrix = glm::translate(modelMatrix, externalPointForTrees);
                modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.1f, 0.1f));
                RenderMesh(meshes["tree"], shaders["LabShaderSimple"], modelMatrix);
            }

            {
                glm::mat4 modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.15f, 0.0f));

                modelMatrix = glm::translate(modelMatrix, internalPointForTrees);
                modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.1f, 0.1f));
                RenderMesh(meshes["tree"], shaders["LabShaderSimple"], modelMatrix);
            }
        }
    }

}

void::Tema2::RouteRandomCars(size_t *countPoints, std::vector<VertexFormat> verticesForCar, float deltaTimeSeconds,
                                float *translateXForRandomCars, float *translateZForRandomCars, float *timeSpentBetweenPoints, float *angleForCars) {

    if ((*timeSpentBetweenPoints) >= 1.0f) {
        (*timeSpentBetweenPoints) = 0.0f;
        (*countPoints) += 1;
    }
    else {
        (*timeSpentBetweenPoints) += deltaTimeSeconds * 1.5f;

        if ((*countPoints) < verticesForCar.size() - 1) {
            *translateXForRandomCars = verticesForCar[(*countPoints)].position.x + (*timeSpentBetweenPoints) * (verticesForCar[(*countPoints) + 1].position.x - verticesForCar[(*countPoints)].position.x);
            *translateZForRandomCars = verticesForCar[(*countPoints)].position.z + (*timeSpentBetweenPoints) * (verticesForCar[(*countPoints) + 1].position.z - verticesForCar[(*countPoints)].position.z);

            glm::vec3 distance = glm::normalize(verticesForCar[(*countPoints) + 1].position - verticesForCar[*countPoints].position);
            (*angleForCars) = atan2(distance.x, distance.z);
        }
        else {
            *translateXForRandomCars = verticesForCar[(*countPoints)].position.x + (*timeSpentBetweenPoints) * (verticesForCar[0].position.x - verticesForCar[(*countPoints)].position.x);
            *translateZForRandomCars = verticesForCar[(*countPoints)].position.z + (*timeSpentBetweenPoints) * (verticesForCar[0].position.z - verticesForCar[(*countPoints)].position.z);

            glm::vec3 distance = glm::normalize(verticesForCar[0].position - verticesForCar[(*countPoints)].position);
            (*angleForCars) = atan2(distance.x, distance.z);

            *countPoints = 0;
        }
    }
}

void Tema2::Update(float deltaTimeSeconds)
{
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glLineWidth(3);
    glPointSize(5);

    glm::vec3 beforePosition = camera->position;
    glm::vec3 beforeForward = camera->forward;
    glm::vec3 beforeUp = camera->up;
    glm::vec3 beforeRight = camera->right;

    RenderScene(deltaTimeSeconds);
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);
    
    camera->Set(glm::vec3(translateX - 0.4f, 20.0f, translateZ), glm::vec3(translateX, 0, translateZ), glm::vec3(0, 1, 0));
    projectionMatrix = glm::ortho(left, right, bottom, top, 0.01f, 100.0f);
    
    RenderScene(deltaTimeSeconds);
    
    camera->position = beforePosition;
    camera->forward = beforeForward;
    camera->up = beforeUp;
    camera->right = beforeRight;
    projectionMatrix = glm::perspective(fov, window->props.aspectRatio, 0.01f, 200.0f);
}


void Tema2::FrameEnd()
{
}


void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    shader->Use();

    GLint carLocationX = glGetUniformLocation(shader->GetProgramID(), "carPositionX");
    glUniform1f(carLocationX, translateX);

    GLint carLocationY = glGetUniformLocation(shader->GetProgramID(), "carPositionY");
    glUniform1f(carLocationY, translateY);

    GLint carLocationZ = glGetUniformLocation(shader->GetProgramID(), "carPositionZ");
    glUniform1f(carLocationZ, translateZ);
    
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
        float cameraSpeed = 2.0f;

        float distance1, distance2, distance3, distance4, distance5, distance6;

        distance1 = std::sqrt((translateX - translateXForRandomCarsF) * (translateX - translateXForRandomCarsF) +
            (translateZ - translateZForRandomCarsF) * (translateZ - translateZForRandomCarsF));

        distance2 = std::sqrt((translateX - translateXForRandomCarsS) * (translateX - translateXForRandomCarsS) +
            (translateZ - translateZForRandomCarsS) * (translateZ - translateZForRandomCarsS));

        distance3 = std::sqrt((translateX - translateXForRandomCarsT) * (translateX - translateXForRandomCarsT) +
            (translateZ - translateZForRandomCarsT) * (translateZ - translateZForRandomCarsT));

        distance4 = std::sqrt((translateX - translateXForRandomCars4) * (translateX - translateXForRandomCars4) +
            (translateZ - translateZForRandomCars4) * (translateZ - translateZForRandomCars4));

        distance5 = std::sqrt((translateX - translateXForRandomCars5) * (translateX - translateXForRandomCars5) +
            (translateZ - translateZForRandomCars5) * (translateZ - translateZForRandomCars5));


        distance6 = std::sqrt((translateX - translateXForRandomCars6) * (translateX - translateXForRandomCars6) +
            (translateZ - translateZForRandomCars6) * (translateZ - translateZForRandomCars6));


        if (window->KeyHold(GLFW_KEY_W)) {
            if (CheckInside(glm::vec3(translateX + deltaTime * cameraSpeed * cos(angularStepOy), translateY, translateZ - deltaTime * cameraSpeed * sin(angularStepOy)))) {
                if (distance1 >= 0.2f && distance2 >= 0.2f && distance3 >= 0.2f && distance4 >= 0.2f && distance5 >= 0.2f && distance6 >= 0.2f) {
                    camera->MoveForward(deltaTime * cameraSpeed);
                    translateZ -= deltaTime * cameraSpeed * sin(angularStepOy);
                    translateX += deltaTime * cameraSpeed * cos(angularStepOy);
                }
            }
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            if (distance1 >= 0.2f && distance2 >= 0.2f && distance3 >= 0.2f && distance4 >= 0.2f && distance5 >= 0.2f && distance6 >= 0.2f) {
                angularStepOy += deltaTime;
                camera->RotateThirdPerson_OY(deltaTime);
            }
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            if (CheckInside(glm::vec3(translateX + deltaTime * cameraSpeed * cos(angularStepOy), translateY, translateZ - deltaTime * cameraSpeed * sin(angularStepOy)))) {
                if (distance1 >= 0.2f && distance2 >= 0.2f && distance3 >= 0.2f && distance4 >= 0.2f && distance5 >= 0.2f && distance6 >= 0.2f) {
                    camera->MoveForward(-deltaTime * cameraSpeed);
                    translateZ += deltaTime * cameraSpeed * sin(angularStepOy);
                    translateX -= deltaTime * cameraSpeed * cos(angularStepOy);
                }
            }
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            if (distance1 >= 0.2f && distance2 >= 0.2f && distance3 >= 0.2f && distance4 >= 0.2f && distance5 >= 0.2f && distance6 >= 0.2f) {
                angularStepOy -= deltaTime;
                camera->RotateThirdPerson_OY(-deltaTime);

            }
        }
}


void Tema2::OnKeyPress(int key, int mods)
{
  
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
