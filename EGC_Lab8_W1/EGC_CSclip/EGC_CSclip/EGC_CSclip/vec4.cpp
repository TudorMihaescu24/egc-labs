#include "vec4.h"

namespace egc{
    vec4& vec4::operator =(const vec4 &srcVector)
    {
        this->x = srcVector.x;
        this->y = srcVector.y;
        this->z = srcVector.z;
        this->w = srcVector.w;
        return *this;
    }

    vec4 vec4::operator +(const vec4& srcVector) const
    {
        return vec4(x + srcVector.x, y + srcVector.y, z + srcVector.z, w + srcVector.w);
    }

    vec4& vec4::operator +=(const vec4& srcVector)
    {
        this->x += srcVector.x;
        this->y += srcVector.y;
        this->z += srcVector.z;
        this->w += srcVector.w;
        return *this;
    }
    vec4 vec4::operator *(float scalarValue) const
    {
        return vec4(x + scalarValue, y + scalarValue, z + scalarValue, w + scalarValue);
    }
    vec4 vec4::operator -(const vec4& srcVector) const
    {
        return vec4(x - srcVector.x, y - srcVector.y, z - srcVector.z, w - srcVector.w);
    }
    vec4& vec4::operator -=(const vec4& srcVector)
    {
        this->x -= srcVector.x;
        this->y -= srcVector.y;
        this->z -= srcVector.z;
        this->w -= srcVector.w;
        return *this;
    }
    vec4 vec4::operator -() const
    {
        return vec4(0 - x,0 - y,0 - z,0 - w);
    }
    float vec4::length() const
    {
        return sqrt(x * x + y * y + z * z);
    }
    vec4& vec4::normalize()
    {
        int len = length();
        this->x = x / len;
        this->y = y / len;
        this->z = z / len;
        this->w = w / len;
        return *this;
    }


}