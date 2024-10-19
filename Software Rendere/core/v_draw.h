#include <stdint.h>
#include "f_math.h"

void DrawLine(uint32_t* FrameBuffer,int x0,int y0,int x1,int y1,int Colour,int Width,int Height);
void DrawTriangle(uint32_t* FrameBuffer, Vector3f VertexA,Vector3f VertexB,Vector3f VertexC,int Width,int Height,int Colour);
void RasteriseTriangle(uint32_t* FrameBuffer,Vector3f VertexA,Vector3f VertexB,Vector3f VertexC,int Colour,int Width,int Height);
float TriangleEdge(Vector3f VertexA,Vector3f VertexB,Vector3f VertexC);
