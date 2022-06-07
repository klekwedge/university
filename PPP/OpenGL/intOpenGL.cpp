#include "framework.h"
#include "intOpenGL.h"
#include <math.h>



HDC hDC;
HGLRC hGLRC;
HWND hWnd;


#define MAX_LOADSTRING 100


HINSTANCE hInst;                               
WCHAR szTitle[MAX_LOADSTRING];                 
WCHAR szWindowClass[MAX_LOADSTRING];          


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_INTOPENGL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_INTOPENGL));

	MSG msg;

	
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_INTOPENGL));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_INTOPENGL);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; 

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_SUPPORT_OPENGL |
		PFD_DRAW_TO_WINDOW |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0,0,0,0,0,0,
		0,
		0,
		0,
		0,0,0,0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0,0,0,
	};

	hDC = GetDC(hWnd);

	int pixelFormat = ChoosePixelFormat(hDC, &pfd);
	
	SetPixelFormat(hDC, pixelFormat, &pfd);
	
	hGLRC = wglCreateContext(hDC);
	
	wglMakeCurrent(hDC, hGLRC);


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		
		glClearColor(0, 0, 0, 0);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glPushMatrix();
		glColor3f(0, 0, 1);     
		glBegin(GL_POINTS); 
		for (GLdouble ax = -100.0; ax < 100.0; ax += 0.05)
		{
			for (GLdouble bx = -100.0; bx < 100.0; bx += 0.05)
			{
				glVertex2d(ax, bx);
			}
		}
		glEnd();

		
		glColor3f(1, 1, 1);  
		glBegin(GL_LINES);
		glVertex2f(-0.95f, 0); 
		glVertex2f(0.95f, 0); 
		glVertex2f(0, -0.95f);
		glVertex2f(0, 0.95f); 
		glVertex2f(0.93f, 0.05f);
		glVertex2f(0.95f, 0);
		glVertex2f(0.93f, -0.05f);
		glVertex2f(0.95f, 0);
		glVertex2f(0.03f, 0.9f);
		glVertex2f(0, 0.95f);
		glVertex2f(-0.03f, 0.9f);
		glVertex2f(0, 0.95f);
		glEnd();

	
		glScalef(0.05, 1, 1);
		glScalef(1, 0.10, 1);

		
		glBegin(GL_LINE_STRIP);
		for (float i = -200; i < 200; i += 0.05)
		{
			glColor3f(1, 0, 0); 
			glVertex2f(i, -cbrt((i - 3)*(i * i - 6 * i + 6)));
		}
		glEnd();

	
		glBegin(GL_LINE_STRIP);
		for (float i = -200; i < 200; i += 0.05)
		{
			glColor3f(0, 0, 1);     
			glVertex2f(i, cbrt(i*i*((i - 4) * (i - 4))));
		}
		glEnd();


		
		SwapBuffers(hDC);
		EndPaint(hWnd, &ps);
		break;

	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;

}