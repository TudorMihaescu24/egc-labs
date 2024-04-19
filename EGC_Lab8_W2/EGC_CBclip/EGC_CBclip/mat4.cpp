
#include "mat3.h"
#include "mat4.h"

namespace egc {

    //matrixData is stored in column-major order
//  m00  m04   m08  m12
//  m01  m05   m09  m13
//  m02  m06   m10  m14
//  m03  m07   m11  m15
    mat4& mat4::operator =(const mat4& srcMatrix){
        for (int i = 0; i < 16; i++)
        {
            matrixData[i] = srcMatrix.matrixData[i];
        }
        return *this;
    }

    mat4 mat4::operator *(float scalarValue) const{
        mat4 auxiliarMatrix;

        for (int i = 0; i < 16; i++)
        {
            auxiliarMatrix.matrixData[i] = scalarValue * matrixData[i];
        }
        return auxiliarMatrix;
    }

    mat4 mat4::operator *(const mat4& srcMatrix) const{
        mat4 result;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                float sum = 0.0;
                for (int k = 0; k < 4; k++) {
                    sum += srcMatrix.matrixData[i * 4 + k] * matrixData[k * 4 + j];
                }
                result.matrixData[i * 4 + j] = sum;
            }
        }

        return result;
    }

    vec4 mat4::operator *(const vec4& srcVector) const{
        vec4 result;

        float x = srcVector.x;
        float y = srcVector.y;
        float z = srcVector.z;
        float w = srcVector.w;

        result.x = matrixData[0] * x + matrixData[4] * y + matrixData[8] * z + matrixData[12] * w;
        result.y = matrixData[1] * x + matrixData[5] * y + matrixData[9] * z + matrixData[13] * w;
        result.z = matrixData[2] * x + matrixData[6] * y + matrixData[10] * z + matrixData[14] * w;
        result.w = matrixData[3] * x + matrixData[7] * y + matrixData[11] * z + matrixData[15] * w;

        return result;
    }

    mat4 mat4::operator +(const mat4& srcMatrix) const{
        mat4 result;

        for (int i = 0; i < 16; i++)
        {
            result.matrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
        }

        return result;
    }

    float& mat4::at(int i, int j)
    {
        return matrixData[i * 3 + j];
    }

    const float& mat4::at(int i, int j) const {
        return matrixData[i * 3 + j];
    }

    float mat4::determinant() const {
        float det = 0.0f;

        det += matrixData[0] * (
            matrixData[5] * (matrixData[10] * matrixData[15] - matrixData[11] * matrixData[14]) -
            matrixData[6] * (matrixData[9] * matrixData[15] - matrixData[11] * matrixData[13]) +
            matrixData[7] * (matrixData[9] * matrixData[14] - matrixData[10] * matrixData[13])
            );

        det -= matrixData[1] * (
            matrixData[4] * (matrixData[10] * matrixData[15] - matrixData[11] * matrixData[14]) -
            matrixData[6] * (matrixData[8] * matrixData[15] - matrixData[11] * matrixData[12]) +
            matrixData[7] * (matrixData[8] * matrixData[14] - matrixData[10] * matrixData[12])
            );

        det += matrixData[2] * (
            matrixData[4] * (matrixData[9] * matrixData[15] - matrixData[11] * matrixData[13]) -
            matrixData[5] * (matrixData[8] * matrixData[15] - matrixData[11] * matrixData[12]) +
            matrixData[7] * (matrixData[8] * matrixData[13] - matrixData[9] * matrixData[12])
            );

        det -= matrixData[3] * (
            matrixData[4] * (matrixData[9] * matrixData[14] - matrixData[10] * matrixData[13]) -
            matrixData[5] * (matrixData[8] * matrixData[14] - matrixData[10] * matrixData[12]) +
            matrixData[6] * (matrixData[8] * matrixData[13] - matrixData[9] * matrixData[12])
            );

        return det;
    }


    mat4 mat4::inverse() const {
        mat4 result;

        float det = this->determinant();
        if (det == 0.0f) {
            return result;
        }
        mat4 adjugate;

  
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                
                mat3 minor;
                int minorRow = 0;
                for (int row = 0; row < 4; ++row) {
                    if (row == i) continue;
                    int minorCol = 0;
                    for (int col = 0; col < 4; ++col) {
                        if (col == j) continue;
                        minor.matrixData[minorRow * 3 + minorCol] = matrixData[row * 4 + col];
                        ++minorCol;
                    }
                    ++minorRow;
                }

                // Calculate the determinant of the minor matrix
                float minorDet = minor.determinant();

                // Calculate the cofactor using the determinant of the minor and the sign (-1)^(i+j)
                float cofactor = ((i + j) % 2 == 0 ? 1 : -1) * minorDet;

                // Assign the cofactor to the adjugate matrix
                adjugate.matrixData[j * 4 + i] = cofactor;
            }
        }

        // Transpose the adjugate matrix to get the inverse
        result = adjugate.transpose();

        // Divide each element by the determinant to get the final result
        det = 1.0 / det;
        result = result * det;

        return result.transpose();
    }




    mat4 mat4::transpose() const {
        mat4 result;

        result.matrixData[0] = matrixData[0];
        result.matrixData[4] = matrixData[1];
        result.matrixData[8] = matrixData[2];
        result.matrixData[12] = matrixData[3];

        result.matrixData[1] = matrixData[4];
        result.matrixData[5] = matrixData[5];
        result.matrixData[9] = matrixData[6];
        result.matrixData[13] = matrixData[7];

        result.matrixData[2] = matrixData[8];
        result.matrixData[6] = matrixData[9];
        result.matrixData[10] = matrixData[10];
        result.matrixData[14] = matrixData[11];

        result.matrixData[3] = matrixData[12];
        result.matrixData[7] = matrixData[13];
        result.matrixData[11] = matrixData[14];
        result.matrixData[15] = matrixData[15];
      

        return result;
    }


}