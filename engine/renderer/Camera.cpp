#include "renderer/Camera.hpp"
#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp>

CameraType &Camera::GetType()
{
    return mType;
}
glm::vec3 &Camera::GetPosition()
{
    return mPosition;
}
glm::vec3 &Camera::GetDirection()
{
    return mDirection;
}
glm::vec3 &Camera::GetUp()
{
    return mUp;
}
void Camera::Rotate(const glm::vec3 &angles)
{
    mDirection.x = sin(glm::radians(angles.x)) * cos(glm::radians(angles.y));
    mDirection.y = sin(glm::radians(angles.y));
    mDirection.z = cos(glm::radians(angles.x)) * cos(glm::radians(angles.y));
}
float &Camera::GetFov()
{
    return mFov;
}
float &Camera::GetAspectRatio()
{
    return mAspectRatio;
}
float &Camera::GetNearPlane()
{
    return mNearPlane;
}
float &Camera::GetFarPlane()
{
    return mFarPlane;
}
glm::mat4 &Camera::GetViewMatrix()
{
    return mViewMatrix;
}
glm::mat4 &Camera::GetProjectionMatrix()
{
    return mProjectionMatrix;
}

void Camera::CalculateMatrices()
{
    mViewMatrix = glm::lookAt(mPosition, mDirection + mPosition, mUp);
    if (mType == PERSPECTIVE)
        mProjectionMatrix = glm::perspective(glm::radians(mFov), mAspectRatio, mNearPlane, mFarPlane);
}

void OrbitalCamera::rotate(const glm::vec3 &angles)
{
    mPosition.x = sin(glm::radians(angles.x)) * cos(glm::radians(angles.y));
    mPosition.y = sin(glm::radians(angles.y));
    mPosition.z = cos(glm::radians(angles.x)) * cos(glm::radians(angles.y));
    mPosition = glm::normalize(mPosition) * mZoom;
}

void OrbitalCamera::CalculateMatrices()
{
    mViewMatrix = glm::lookAt(mPosition, mDirection, mUp);
    if (mType == PERSPECTIVE)
        mProjectionMatrix = glm::perspective(glm::radians(mFov), mAspectRatio, mNearPlane, mFarPlane);
}
