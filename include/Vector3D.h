#ifndef VECTOR3D_H
#define VECTOR3D_H


class Vector3D {
  public:
    Vector3D();
    Vector3D(float x, float y, float z);
    virtual ~Vector3D();

    float x, y, z;

  protected:

  private:
};

#endif // VECTOR3D_H
