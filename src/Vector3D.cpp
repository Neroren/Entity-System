#include "Vector3D.h"

Vector3D::Vector3D() {
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}

Vector3D::Vector3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::~Vector3D() {
}
