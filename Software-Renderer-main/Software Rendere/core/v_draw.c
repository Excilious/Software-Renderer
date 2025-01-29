#include "v_draw.h"
#include "f_math.h"

float TriangleEdge(Vector3f VertexA,Vector3f VertexB,Vector3f VertexC)
{return (VertexB.x-VertexA.x)*(VertexC.y-VertexA.y)-(VertexB.y-VertexA.y)*(VertexC.x-VertexA.x);}

void DrawLine(uint32_t* FrameBuffer,int x0,int y0,int x1,int y1,int Colour,int Width,int Height)
{
    int dx = x1-x0;
    int ix = ((dx>0)-(dx<0));
    dx = abs(dx) << 1;

    int dy = y1-y0;
    int iy = ((dy>0)-(dy<0));
    dy = abs(dy) << 1;

    FrameBuffer[y0*Width+x0] = Colour;
    if (dx >= dy)
    {
        int err = (dy-(dx>>1));
        while (x0 != x1)
        {
            if ((err>=0) && (err||(ix>0)))
            {
                err-dx;
                y0+iy;
            }
            err+=dy;
            x0+=ix;
            FrameBuffer[y0*Width+x0] = Colour;
        }
    }
    else
    {
        int err = (dx-(dy>>1));
        while (y0!=y1)
        {
            if ((err>=0) && (err||(iy>0)))
            {
                err-=dy;
                x0+=ix;
            }
            err+=dx;
            y0+=iy;
            FrameBuffer[y0*Width+x0] = Colour;
        }
    }
}

void RasteriseTriangle(uint32_t* FrameBuffer,Vector3f VertexA,Vector3f VertexB,Vector3f VertexC,int Colour,int Width,int Height)
{
    for (int x = 0; x < Width; ++x)
    {
        for (int y = 0; y < Height; ++y)
        {
            Vector3f Point;
            Point.x = x;
            Point.y = y;
            Point.z = 0; 

            float ABP = TriangleEdge(VertexA,VertexB,Point);
            float BCP = TriangleEdge(VertexB,VertexC,Point);
            float CAP = TriangleEdge(VertexC,VertexA,Point);

            if (ABP >= 0 && BCP >= 0 && CAP >= 0)
            {
                FrameBuffer[y*Width+x] = Colour;
            }
        }
    }
}

void DrawTriangle(uint32_t* FrameBuffer, Vector3f VertexA,Vector3f VertexB,Vector3f VertexC,int Width,int Height,int Colour)
{
    DrawLine(FrameBuffer,VertexA.x,VertexA.y,VertexB.x,VertexB.y,Colour,Width,Height);
    DrawLine(FrameBuffer,VertexB.x,VertexB.y,VertexC.x,VertexC.y,Colour,Width,Height);
    DrawLine(FrameBuffer,VertexC.x,VertexC.y,VertexA.x,VertexA.y,Colour,Width,Height);
    RasteriseTriangle(FrameBuffer,VertexA,VertexB,VertexC,Colour,Width,Height);
}