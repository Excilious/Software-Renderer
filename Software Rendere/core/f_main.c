#include "f_main.h"

LRESULT CALLBACK ProcHandler(HWND WHandle,UINT UMsg,WPARAM WParam,LPARAM LParam)
{
    switch (UMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(WHandle,UMsg,WParam,LParam);
}

int WINAPI WinMain(HINSTANCE HInstance,HINSTANCE HPrevInstance,LPSTR CMDLine,int SCMD)
{
    Matrix4x4 Dude;
    WNDCLASS WndClass = {0};
    WndClass.lpfnWndProc = ProcHandler;
    WndClass.hInstance = HInstance;
    WndClass.lpszClassName = "Fusion Renderer";
    RegisterClass(&WndClass);

    HWND WMHandle = CreateWindowEx(0,WndClass.lpszClassName,"Fusion Engine",WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,Width,Height,0,0,HInstance,0);
    MSG HMsg = {0};
    uint32_t* Buffer = malloc(Width*Height*sizeof(uint32_t));

    //Cube
    Vector3f PointA = {200,200,0};
    Vector3f PointB = {200,50,0};
    Vector3f PointC = {400,50,0};

    DrawTriangle(Buffer,PointA,PointB,PointC,Width,Height,0x00FF00);
    
    while (HMsg.message != WM_QUIT)
    {

        if (PeekMessage(&HMsg,NULL,0,0,PM_REMOVE))
        {
            TranslateMessage(&HMsg);
            DispatchMessage(&HMsg);
        }

        HDC Hdc = GetDC(WMHandle);
        BITMAPINFO BMI = {0};
        BMI.bmiHeader.biSize = sizeof(BITMAPINFO);
        BMI.bmiHeader.biWidth = Width;
        BMI.bmiHeader.biHeight = -Height;
        BMI.bmiHeader.biPlanes = 1;
        BMI.bmiHeader.biBitCount = 32;       
        BMI.bmiHeader.biCompression = BI_RGB;

        StretchDIBits(Hdc,0,0,Width,Height,0,0,Width,Height,Buffer,&BMI,DIB_RGB_COLORS,SRCCOPY);
        ReleaseDC(WMHandle,Hdc);
    }

    free(Buffer);
    return 0;
}
   