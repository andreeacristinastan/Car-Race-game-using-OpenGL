#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"


namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };
    public:
        Tema2();
        ~Tema2();

        void Init() override;
        bool CheckInside(glm::vec3 myPoint);
        

    private:
        void FrameStart() override;
        void RouteRandomCars(size_t* countPoints, std::vector<VertexFormat> verticesForCar, float deltaTimeSeconds,
            float* translateXForRandomCars, float* translateZForRandomCars, float* timeSpentBetweenPoints, float* angleForCars);
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix) override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderScene(float deltaTimeSeconds);

    protected:
        implemented::Camera* camera;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;
        bool projectionTypeOrtho;
        GLenum polygonMode;

        // TODO(student): If you need any other class variables, define them here.

        float carX = -5.57f;
        float carY = 0.0f;
        float carZ = 3.93f;
        float angularStepOy, angularStepOz;
        std::vector<VertexFormat> verticesRoad;
        std::vector<VertexFormat> vertices;
        std::vector<VertexFormat> verticesForCarFirst, verticesForCarSecond, verticesForCarThird;
        std::vector<VertexFormat> verticesTriangle;
        std::vector<unsigned int> indicesTriangle;
        std::vector<unsigned int> indicesRoad;

        ViewportArea miniViewportArea;
        glm::vec3 distance;
        std::vector<glm::vec3> distances;
        glm::vec3 P1, P2, P, randomPoint;
        glm::vec3 externalPointForTrees, internalPointForTrees, internalPointForRandomCarFirst, internalPointForRandomCarSecond, internalPointForRandomCarsThird;
        glm::vec3 firstPoint;
        float translateX, translateY, translateZ, translateXForRandomCarsF, translateZForRandomCarsF, translateXForRandomCarsS, translateZForRandomCarsS,
            translateXForRandomCarsT, translateZForRandomCarsT, translateXForRandomCars4, translateZForRandomCars4, translateXForRandomCars5, translateZForRandomCars5, translateXForRandomCars6, translateZForRandomCars6;
        float timeSpentBetweenPointsF = 0.0f, angleForCars, timeSpentBetweenPointsS = 0.0f, timeSpentBetweenPointsT = 0.0f, timeSpentBetweenPoints4 = 0.0f, timeSpentBetweenPoints5 = 0.0f, timeSpentBetweenPoints6 = 0.0f;
        size_t countPoints1, countPoints2, countPoints3, countPoints4, countPoints5, countPoints6;
        float right;
        float left;
        float bottom;
        float top;
        float fov;
        float resetCameraX, resetCameraY, resetCameraZ;

    };
}   // namespace m1
