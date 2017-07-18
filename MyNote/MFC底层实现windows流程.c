#include <windows.h> //�ײ�ʵ�ִ���ͷ�ļ�

// 6��������Ϣ�����ڹ��̣�
// CALLBACK ���� __stdcall ��������˳�� �������� ������ջ �������ں�������ǰ�Զ���� ��ջ����

LRESULT CALLBACK WindowProc(
	HWND hwnd,  //��Ϣ�������ھ��
	UINT uMsg,  // ������Ϣ���� WM_XXX
	WPARAM wParam,  // ���̸�����Ϣ
	LPARAM lParam   //��긽����Ϣ
	)
{
	
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd); //���� WM_DESTROY  Լ���׳�һ�����飺 ������ xxxWindow��Ϣ������ŵ���Ϣ�����У�����ֱ��ִ��
		break;
	case WM_DESTROY:
		PostQuitMessage(0); //�����˳���Ϣ
		break;
	case WM_LBUTTONDOWN: //������������Ϣ
	{
		int xPos;
		int yPos;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		//��ӡ���� ͨ��ͬMessageBox

		TCHAR buf[1024];
		wsprintf(buf, TEXT(" x = %d,y = %d"), xPos, yPos);
		// ��������  ��ʾ����   ��������  ������������
		MessageBox(hwnd, buf, TEXT("��갴��"), MB_OK);
	}
		break;
	case WM_KEYDOWN: //������Ϣ

		MessageBox(hwnd, TEXT("���̰���"), TEXT("������Ϣ"), MB_OK);
		break;

	case  WM_PAINT: //��ͼ��Ϣ
	{
		PAINTSTRUCT ps; //��ͼ�ṹ��
		HDC hdc = BeginPaint(hwnd, &ps);
		//��������
		TextOut(hdc, 100, 100, TEXT("helloworld"), strlen("helloworld"));
		EndPaint(hwnd, &ps);
	}
		break;
	default:
		break;
	}


	//Ĭ�Ϸ�ʽ����
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



// WINAPI ���� __stdcall ��������˳�� �������� ������ջ �������ں�������ǰ�Զ���� ��ջ����
// WinMain�������
int WINAPI WinMain(
	HINSTANCE hInstance, // Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance,  // ǰһ��Ӧ�ó���ʵ���������win32�����£�����ֵNULL����������
	LPSTR lpCmdLine,  // char * argv[] �����в�������
	int nShowCmd)   // ������ʾ����  �����С��..
{
	//ʵ�ֵײ㴰��  6����

	// 1����ƴ�����
	// 2��ע�ᴰ����
	// 3������������
	// 4����ʾ�͸��´���
	// 5��ͨ��ѭ��ȡ��Ϣ
	// 6��������Ϣ�����ڹ��̣�


	//1�� ��ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0; //�������ڴ� ͨ��Ϊ0
	wc.cbWndExtra = 0; //���ڶ�����ڴ棬ͨ��Ϊ0
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND);//���ù�� �����һ������ΪNULL������ʹ��ϵͳ�ṩ��Ĭ�Ϲ��
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);  //����ͼ�� �����һ������ΪNULL������ʹ��ϵͳ�ṩ��Ĭ��ͼ��
	wc.hInstance = hInstance;//��ǰʵ�������WinMain�������βμ���
	wc.lpfnWndProc = WindowProc; //���ڹ��̺���  �ص����� ���ƿ��������
	wc.lpszClassName = TEXT("WINDOW");//ָ����������
	wc.lpszMenuName = NULL;//�˵���  û����NULL
	wc.style = 0; // 0����Ĭ�Ϸ��

	//2�� ע�ᴰ����
	RegisterClass(&wc);

	//3����������
	/*
	lpClassName,  ����
	lpWindowName, ������
	dwStyle,   ��ʾ��� WS_OVERLAPPEDWINDOW
	x, y,\     ����������ʼ����   CW_USEDEFAULT
	nWidth, nHeight,  ��������Ĭ�Ͽ��  CW_USEDEFAULT
	hWndParent,  ������  NULL
	hMenu,     �˵�   NULL
	hInstance,   ʵ�����   hInstance
	lpParam �������� NULL
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("TEXT WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//4�� ��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);


	//5��ͨ��ѭ��ȡ��Ϣ
	/*
	HWND        hwnd;  //������
	UINT        message; //��Ϣ���� WM_XXXX ��WINDOW MESSAGE��
	WPARAM      wParam; // ������Ϣ ����
	LPARAM      lParam; // ������Ϣ ��� ���Ҽ�
	DWORD       time;   // ��Ϣ����ʱ��
	POINT       pt;     // ������Ϣ  ���  x y����
	*/
	MSG  msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		/*
		����
		_Out_ LPMSG lpMsg,  ��Ϣ�ṹ��
		_In_opt_ HWND hWnd, NULL �������д�����Ϣ
		_In_ UINT wMsgFilterMin,  ������С��Ϣ����
		_In_ UINT wMsgFilterMax); ���������Ϣ����   0 ��д0 ������������Ϣ
		*/
		//if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		//{
		//	break;
		//}

		//������Ϣ
		TranslateMessage(&msg);

		//�ַ���Ϣ
		DispatchMessage(&msg);

	}


	return 0;
}


//�������