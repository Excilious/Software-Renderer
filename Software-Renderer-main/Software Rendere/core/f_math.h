#ifndef abs 
#define abs(x) ((x)<0?-(x): (x))
#endif

#ifndef max
#define max(a,b) (((a)>(b))?(a):(b))
#endif

#ifndef min
#define min(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MATHS_HEADER
#define MATHS_HEADER

typedef struct Matrix 
{
    float matrix[4][4];
} Matrix4x4;

typedef struct Vector2
{
    float x;
    float y;
} Vector2f;

typedef struct Vector3
{
    float x;
    float y;
    float z;
} Vector3f;

typedef struct Vector4
{
    float x;
    float y; 
    float z;
    float w;
} Vector4f;


Matrix4x4 BuildProjectionMatrix(Matrix4x4 Matrix,int Near,int Far,int AspectRatio,int Fov);
Matrix4x4 MatrixMultiplication(Matrix4x4 MatrixA,Matrix4x4 MatrixB);

#endif