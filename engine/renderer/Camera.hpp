#pragma once
#include <glm/glm.hpp>

enum CameraType
{
    PERSPECTIVE,
    ORTHOGRAPHIC
};

class Camera
{
  public:
    virtual void CalculateMatrices();
    void Rotate(const glm::vec3 &angles);
    float &GetFov();
    float &GetAspectRatio();
    float &GetNearPlane();
    float &GetFarPlane();
    glm::vec3 &GetUp();
    glm::vec3 &GetPosition();
    glm::vec3 &GetDirection();
    glm::mat4 &GetViewMatrix();
    glm::mat4 &GetProjectionMatrix();
    CameraType &GetType();

  protected:
    float mFov = 90.f;
    float mAspectRatio = 1.f;
    float mNearPlane = 0.1f;
    float mFarPlane = 100.f;
    glm::vec3 mPosition = glm::vec3(0);
    glm::vec3 mDirection = glm::vec3(0, 0, 1);
    glm::vec3 mUp = glm::vec3(0, 1, 0);
    glm::mat4 mViewMatrix = glm::mat4(1.f);
    glm::mat4 mProjectionMatrix = glm::mat4(1.f);
    CameraType mType = PERSPECTIVE;
};

class OrbitalCamera : public Camera
{
  public:
    void rotate(const glm::vec3 &angle);
    void CalculateMatrices();
    float &getZoom()
    {
        return mZoom;
    }

  private:
    float mZoom = 1.0f;
};
