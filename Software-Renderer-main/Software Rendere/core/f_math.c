#include "f_math.h"

Matrix4x4 BuildProjectionMatrix(Matrix4x4 Matrix,int Near,int Far,int AspectRatio,int Fov)
{
    Matrix.matrix[0][0] = AspectRatio*Fov;
    Matrix.matrix[1][1] = Fov;
    Matrix.matrix[2][2] = Far/(Far-Near);
    Matrix.matrix[3][2] = (-Far*Near)/(Far-Near);
    Matrix.matrix[2][3] = 1.0f;
    Matrix.matrix[3][3] = 0.0f;
    return Matrix4x4;
}

Matrix4x4 VectorMatrixMultiplication(Matrix4x4 MatrixA,Vector4f VectorB)
{}