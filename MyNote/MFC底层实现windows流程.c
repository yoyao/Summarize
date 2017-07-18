#include <windows.h> //底层实现窗口头文件

// 6、处理消息（窗口过程）
// CALLBACK 代表 __stdcall 参数传递顺序 从右往左 依次入栈 ，并且在函数返回前自动清空 堆栈内容

LRESULT CALLBACK WindowProc(
	HWND hwnd,  //消息所属窗口句柄
	UINT uMsg,  // 具体消息名称 WM_XXX
	WPARAM wParam,  // 键盘附加消息
	LPARAM lParam   //鼠标附加消息
	)
{
	
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd); //触发 WM_DESTROY  约定俗成一个事情： 函数名 xxxWindow消息，不会放到消息队列中，而是直接执行
		break;
	case WM_DESTROY:
		PostQuitMessage(0); //发送退出消息
		break;
	case WM_LBUTTONDOWN: //鼠标左键按下消息
	{
		int xPos;
		int yPos;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		//打印操作 通常同MessageBox

		TCHAR buf[1024];
		wsprintf(buf, TEXT(" x = %d,y = %d"), xPos, yPos);
		// 所属窗口  显示内容   标题内容  关联按键类型
		MessageBox(hwnd, buf, TEXT("鼠标按下"), MB_OK);
	}
		break;
	case WM_KEYDOWN: //键盘消息

		MessageBox(hwnd, TEXT("键盘按下"), TEXT("键盘消息"), MB_OK);
		break;

	case  WM_PAINT: //绘图消息
	{
		PAINTSTRUCT ps; //绘图结构体
		HDC hdc = BeginPaint(hwnd, &ps);
		//绘制文字
		TextOut(hdc, 100, 100, TEXT("helloworld"), strlen("helloworld"));
		EndPaint(hwnd, &ps);
	}
		break;
	default:
		break;
	}


	//默认方式处理
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



// WINAPI 代表 __stdcall 参数传递顺序 从右往左 依次入栈 ，并且在函数返回前自动清空 堆栈内容
// WinMain函数入口
int WINAPI WinMain(
	HINSTANCE hInstance, // 应用程序实例句柄
	HINSTANCE hPrevInstance,  // 前一个应用程序实例句柄，在win32环境下，基本值NULL，不起作用
	LPSTR lpCmdLine,  // char * argv[] 命令行参数数组
	int nShowCmd)   // 窗口显示命令  最大化最小化..
{
	//实现底层窗口  6步骤

	// 1、设计窗口类
	// 2、注册窗口类
	// 3、创建窗口类
	// 4、显示和更新窗口
	// 5、通过循环取消息
	// 6、处理消息（窗口过程）


	//1、 设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0; //类额外的内存 通常为0
	wc.cbWndExtra = 0; //窗口额外的内存，通常为0
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //设置背景
	wc.hCursor = LoadCursor(NULL, IDC_HAND);//设置光标 如果第一个参数为NULL，代表使用系统提供的默认光标
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);  //设置图标 如果第一个参数为NULL，代表使用系统提供的默认图标
	wc.hInstance = hInstance;//当前实例句柄，WinMain函数中形参即可
	wc.lpfnWndProc = WindowProc; //窗口过程函数  回调函数 名称可以随机起
	wc.lpszClassName = TEXT("WINDOW");//指定窗口类名
	wc.lpszMenuName = NULL;//菜单名  没有填NULL
	wc.style = 0; // 0代表默认风格

	//2、 注册窗口类
	RegisterClass(&wc);

	//3、创建窗口
	/*
	lpClassName,  类名
	lpWindowName, 窗口名
	dwStyle,   显示风格 WS_OVERLAPPEDWINDOW
	x, y,\     创建窗口起始坐标   CW_USEDEFAULT
	nWidth, nHeight,  创建窗口默认宽高  CW_USEDEFAULT
	hWndParent,  父窗口  NULL
	hMenu,     菜单   NULL
	hInstance,   实例句柄   hInstance
	lpParam 其他参数 NULL
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("TEXT WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//4、 显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);


	//5、通过循环取消息
	/*
	HWND        hwnd;  //主窗口
	UINT        message; //消息名称 WM_XXXX （WINDOW MESSAGE）
	WPARAM      wParam; // 附加消息 键盘
	LPARAM      lParam; // 附加消息 鼠标 左右键
	DWORD       time;   // 消息产生时间
	POINT       pt;     // 附加消息  鼠标  x y坐标
	*/
	MSG  msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		/*
		参数
		_Out_ LPMSG lpMsg,  消息结构体
		_In_opt_ HWND hWnd, NULL 捕获所有窗口消息
		_In_ UINT wMsgFilterMin,  过滤最小消息数量
		_In_ UINT wMsgFilterMax); 过滤最大消息数量   0 都写0 代表捕获所有消息
		*/
		//if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		//{
		//	break;
		//}

		//翻译消息
		TranslateMessage(&msg);

		//分发消息
		DispatchMessage(&msg);

	}


	return 0;
}


//函数入口