#include "transform.h"
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

namespace egc {

    mat3 translate(const vec2 translateArray)
    {
        mat3 matrix;

        matrix.matrixData[0] = 1;
        matrix.matrixData[1] = 0;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = 0;
        matrix.matrixData[4] = 1;
        matrix.matrixData[5] = 0;
        matrix.matrixData[6] = translateArray.x;
        matrix.matrixData[7] = translateArray.y;
        matrix.matrixData[8] = 1;

        return matrix;
    }

    mat3 translate(float tx, float ty)
    {
        return translate(vec2(tx, ty));
    }        

    mat3 scale(const vec2 scaleArray)
    {
        mat3 matrix;

        matrix.matrixData[0] = scaleArray.x;
        matrix.matrixData[1] = 0;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = 0;
        matrix.matrixData[4] = scaleArray.y;
        matrix.matrixData[5] = 0;
        matrix.matrixData[6] = 0;
        matrix.matrixData[7] = 0;
        matrix.matrixData[8] = 1;

        return matrix;
    }

    mat3 scale(float sx, float sy)
    {
        return scale(vec2(sx, sy));
    }

    mat3 rotate(float angle)
    {
        mat3 matrix;
        
        float radians = angle * PI / 180.0;
        float sinAngle = sin(radians);
        float cosAngle = cos(radians);

        const float epsilon = 1e-6;
        if (fabs(cosAngle) < epsilon)
            cosAngle = 0.0;
        if (fabs(sinAngle) < epsilon)
            sinAngle = 0.0;

        matrix.matrixData[0] = cosAngle;
        matrix.matrixData[1] = sinAngle;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = sinAngle * -1;
        matrix.matrixData[4] = cosAngle;
        matrix.matrixData[5] = 0;
        matrix.matrixData[6] = 0;
        matrix.matrixData[7] = 0;
        matrix.matrixData[8] = 1;

        return matrix;
    }

    mat4 translate(const vec3 translateArray)
    {
        mat4 matrix;

        matrix.matrixData[0] = 1;
        matrix.matrixData[1] = 0;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = 0;

        matrix.matrixData[4] = 0;
        matrix.matrixData[5] = 1;
        matrix.matrixData[6] = 0;
        matrix.matrixData[7] = 0;

        matrix.matrixData[8] = 0;
        matrix.matrixData[9] = 0;
        matrix.matrixData[10] = 1;
        matrix.matrixData[11] = 0;

        matrix.matrixData[12] = translateArray.x;
        matrix.matrixData[13] = translateArray.y;
        matrix.matrixData[14] = translateArray.z;
        matrix.matrixData[15] = 1;

        return matrix;
    }

    mat4 translate(float tx, float ty, float tz)
    {
        return translate(vec3(tx, ty, tz));
    }

    mat4 scale(const vec3 scaleArray)
    {
        mat4 matrix;

        matrix.matrixData[0] = scaleArray.x;
        matrix.matrixData[1] = 0;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = 0;

        matrix.matrixData[4] = 0;
        matrix.matrixData[5] = scaleArray.y;
        matrix.matrixData[6] = 0;
        matrix.matrixData[7] = 0;

        matrix.matrixData[8] = 0;
        matrix.matrixData[9] = 0;
        matrix.matrixData[10] = scaleArray.z;
        matrix.matrixData[11] = 0;

        matrix.matrixData[12] = 0;
        matrix.matrixData[13] = 0;
        matrix.matrixData[14] = 0;
        matrix.matrixData[15] = 1;

        return matrix;
    }

    mat4 scale(float sx, float sy, float sz)
    {
        return scale(vec3(sx, sy, sz));
    }

    mat4 rotateX(float angle)
    {
        mat4 matrix;
        float radians = angle * PI / 180.0;
        float sinAngle = sin(radians);
        float cosAngle = cos(radians);

        const float epsilon = 1e-6;
        if (fabs(cosAngle) < epsilon)
            cosAngle = 0.0;
        if (fabs(sinAngle) < epsilon)
            sinAngle = 0.0;

        matrix.matrixData[0] = 1;
        matrix.matrixData[1] = 0;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = 0;

        matrix.matrixData[4] = 0;
        matrix.matrixData[5] = cosAngle;
        matrix.matrixData[6] = sinAngle;
        matrix.matrixData[7] = 0;

        matrix.matrixData[8] = 0;
        matrix.matrixData[9] = -sinAngle;
        matrix.matrixData[10] = cosAngle;
        matrix.matrixData[11] = 0;

        matrix.matrixData[12] = 0;
        matrix.matrixData[13] = 0;
        matrix.matrixData[14] = 0;
        matrix.matrixData[15] = 1;

        return matrix;
    }
    mat4 rotateY(float angle)
    {
        mat4 matrix;
        float radians = angle * PI / 180.0;
        float sinAngle = sin(radians);
        float cosAngle = cos(radians);

        const float epsilon = 1e-6;
        if (fabs(cosAngle) < epsilon)
            cosAngle = 0.0;
        if (fabs(sinAngle) < epsilon)
            sinAngle = 0.0;

        matrix.matrixData[0] = cosAngle;
        matrix.matrixData[1] = 0;
        matrix.matrixData[2] = -sinAngle;
        matrix.matrixData[3] = 0;

        matrix.matrixData[4] = 0;
        matrix.matrixData[5] = 1;
        matrix.matrixData[6] = 0;
        matrix.matrixData[7] = 0;

        matrix.matrixData[8] = sinAngle;
        matrix.matrixData[9] = 0;
        matrix.matrixData[10] = cosAngle;
        matrix.matrixData[11] = 0;

        matrix.matrixData[12] = 0;
        matrix.matrixData[13] = 0;
        matrix.matrixData[14] = 0;
        matrix.matrixData[15] = 1;

        return matrix;
    }

    mat4 rotateZ(float angle)
    {
        mat4 matrix;
        float radians = angle * PI / 180.0;
        float sinAngle = sin(radians);
        float cosAngle = cos(radians);

        const float epsilon = 1e-6;
        if (fabs(cosAngle) < epsilon)
            cosAngle = 0.0;
        if (fabs(sinAngle) < epsilon)
            sinAngle = 0.0;

        matrix.matrixData[0] = cosAngle;
        matrix.matrixData[1] = sinAngle;
        matrix.matrixData[2] = 0;
        matrix.matrixData[3] = 0;

        matrix.matrixData[4] = -sinAngle;
        matrix.matrixData[5] = cosAngle;
        matrix.matrixData[6] = 0;
        matrix.matrixData[7] = 0;

        matrix.matrixData[8] = 0;
        matrix.matrixData[9] = 0;
        matrix.matrixData[10] = 1;
        matrix.matrixData[11] = 0;

        matrix.matrixData[12] = 0;
        matrix.matrixData[13] = 0;
        matrix.matrixData[14] = 0;
        matrix.matrixData[15] = 1;

        return matrix;
       
    }

}