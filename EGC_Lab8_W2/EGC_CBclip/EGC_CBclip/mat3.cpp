#include "mat3.h"

namespace egc {

    mat3& mat3::operator =(const mat3& srcMatrix)
    {
        for (int i = 0; i < 9; i++)
        {
           matrixData[i] = srcMatrix.matrixData[i];
        }
        return *this;
    }

    mat3 mat3::operator *(float scalarValue) const {
        mat3 auxiliarMatrix;
        
        for (int i = 0; i < 9; i++)
        {
          auxiliarMatrix.matrixData[i] = scalarValue * matrixData[i];
        }
        return auxiliarMatrix;
    }

    mat3 mat3::operator *(const mat3& srcMatrix) const {
        mat3 result;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                float sum = 0.0;
                for (int k = 0; k < 3; k++) {
                    sum += srcMatrix.matrixData[i * 3 + k] * matrixData[k * 3 + j];
                }
                result.matrixData[i * 3 + j] = sum;
            }
        }

        return result;
    }

    vec3 mat3::operator *(const vec3& srcVector) const {
        vec3 result;

        float x = srcVector.x;
        float y = srcVector.y; 
        float z = srcVector.z;

        result.x = matrixData[0] * x + matrixData[3] * y + matrixData[6] * z;
        result.y = matrixData[1] * x + matrixData[4] * y + matrixData[7] * z;
        result.z = matrixData[2] * x + matrixData[5] * y + matrixData[8] * z;

        return result;
    }

    mat3 mat3::operator +(const mat3& srcMatrix) const {
        mat3 result;
        
        for (int i = 0; i < 9; i++)
        {
            result.matrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
        }

        return result;
    }

    float& mat3::at(int i, int j)
    {
        return matrixData[i * 3 + j];
    }

    const float& mat3::at(int i, int j) const {
        return matrixData[i * 3 + j];
    }

    float mat3::determinant() const{
        float term1 = matrixData[0] * matrixData[4] * matrixData[8];
        float term2 = matrixData[1] * matrixData[5] * matrixData[6];
        float term3 = matrixData[2] * matrixData[3] * matrixData[7];


        float term4 = matrixData[2] * matrixData[4] * matrixData[6];
        float term5 = matrixData[0] * matrixData[5] * matrixData[7];
        float term6 = matrixData[1] * matrixData[3] * matrixData[8];

        float result = term1 + term2 + term3 - term4 - term5 - term6;

        return result;
    }

    mat3 mat3::inverse() const{

        mat3 result;

        float determinant = this->determinant();
        determinant = 1.0 / determinant;

        result.matrixData[0] = determinant * (matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7]);
        result.matrixData[1] = determinant * (matrixData[2] * matrixData[7] - matrixData[1] * matrixData[8]);
        result.matrixData[2] = determinant * (matrixData[1] * matrixData[5] - matrixData[2] * matrixData[4]);

        result.matrixData[3] = determinant * (matrixData[5] * matrixData[6] - matrixData[3] * matrixData[8]);
        result.matrixData[4] = determinant * (matrixData[0] * matrixData[8] - matrixData[2] * matrixData[6]);
        result.matrixData[5] = determinant * (matrixData[2] * matrixData[3] - matrixData[0] * matrixData[5]);

        result.matrixData[6] = determinant * (matrixData[3] * matrixData[7] - matrixData[4] * matrixData[6]);
        result.matrixData[7] = determinant * (matrixData[1] * matrixData[6] - matrixData[0] * matrixData[7]);
        result.matrixData[8] = determinant * (matrixData[0] * matrixData[4] - matrixData[1] * matrixData[3]);

        return result;

    }

    mat3 mat3::transpose() const{

        mat3 result;

        result.matrixData[0] = matrixData[0];
        result.matrixData[3] = matrixData[1];
        result.matrixData[6] = matrixData[2];
                            
        result.matrixData[1] = matrixData[3];
        result.matrixData[4] = matrixData[4];
        result.matrixData[7] = matrixData[5];
                               
        result.matrixData[2] = matrixData[6];
        result.matrixData[5] = matrixData[7];
        result.matrixData[8] = matrixData[8];

        return result;
    }


}