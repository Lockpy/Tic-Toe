#include <Windows.h>
#include<tchar.h>
#include<ctime>

#define ID_BUTTON1 1001
#define ID_BUTTON2 1002
#define ID_BUTTON3 1003
#define ID_BUTTON4 1004
#define ID_BUTTON5 1005
#define ID_BUTTON6 1006
#define ID_BUTTON7 1007
#define ID_BUTTON8 1008
#define ID_BUTTON9 1009
#define ID_NEWGAME 2001
#define ID_PCFIRST 2002
#define ID_EDIT1 4001
#define ID_ABOUT 5001
#define ID_DIF 5002
#define ID_SIMPLE 5003
#define ID_IMP 5004

namespace myglobal
{
	HWND but_group[10], hEdit1;
	HANDLE O_img, X_img;
	HMENU hMainMenu;
	int i = 1, y = 0, f = 0, step = 0, mas[10]{ 0 };
	bool run = 0, lev = 0;
}

int PC_logik()
{
	using namespace myglobal;
	for (i = 1; i < 8; i += 3)//proverka na 3 iksa = return 2
	{
		if (mas[i] == 1 && mas[i + 1] == 1 && mas[i + 2] == 1) return 2;
	}

	for (i = 1; i < 4; i++)
	{
		if (mas[i] == 1 && mas[i + 3] == 1 && mas[i + 6] == 1) return 2;
	}
	if (mas[1] == 1 && mas[5] == 1 && mas[9] == 1) return 2;
	if (mas[3] == 1 && mas[5] == 1 && mas[7] == 1) return 2;


	for (y = 2; y > 0; y--)//proverka na 2 iksa = return 0, i 2 nulia = return 1
	{
		for (i = 1; i < 8; i += 3)
		{
			if (mas[i] == y && mas[i + 1] == y && !mas[i + 2])
			{

				SendMessage(but_group[i + 2], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
				mas[i + 2] = 2;
				return y - 1;
			}
			if (mas[i + 1] == y && mas[i + 2] == y && !mas[i])
			{

				SendMessage(but_group[i], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
				mas[i] = 2;
				return y - 1;
			}
			if (mas[i + 2] == y && mas[i] == y && !mas[i + 1])
			{

				SendMessage(but_group[i + 1], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
				mas[i + 1] = 2;
				return y - 1;
			}
		}

		for (i = 1; i < 4; i++)
		{
			if (mas[i] == y && mas[i + 3] == y && !mas[i + 6])
			{

				SendMessage(but_group[i + 6], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
				mas[i + 6] = 2;
				return y - 1;
			}
			if (mas[i + 3] == y && mas[i + 6] == y && !mas[i])
			{

				SendMessage(but_group[i], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
				mas[i] = 2;
				return y - 1;
			}
			if (mas[i + 6] == y && mas[i] == y && !mas[i + 3])
			{

				SendMessage(but_group[i + 3], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
				mas[i + 3] = 2;
				return y - 1;
			}
		}
		if (mas[1] == y && mas[5] == y && !mas[9])
		{

			SendMessage(but_group[9], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[9] = 2;
			return y - 1;
		}
		if (mas[5] == y && mas[9] == y && !mas[1])
		{

			SendMessage(but_group[1], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[1] = 2;
			return y - 1;
		}
		if (mas[9] == y && mas[1] == y && !mas[5])
		{

			SendMessage(but_group[5], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[5] = 2;
			return y - 1;
		}

		if (mas[3] == y && mas[5] == y && !mas[7])
		{

			SendMessage(but_group[7], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[7] = 2;
			return y - 1;
		}
		if (mas[5] == y && mas[7] == y && !mas[3])
		{

			SendMessage(but_group[3], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[3] = 2;
			return y - 1;
		}
		if (mas[7] == y && mas[3] == y && !mas[5])
		{

			SendMessage(but_group[5], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[5] = 2;
			return y - 1;
		}
	}

	if (lev)
	{
		if (!mas[5])//zanimaem centr esli pusto
		{

			SendMessage(but_group[5], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[5] = 2;
			return 0;
		}

		if (!mas[1])//zanimaem ugol 1 esli pusto
		{

			SendMessage(but_group[1], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[1] = 2;
			return 0;
		}

		if (!mas[3])//zanimaem ugol 3 esli pusto
		{

			SendMessage(but_group[3], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[3] = 2;
			return 0;
		}

		if (!mas[7])//zanimaem ugol 7 esli pusto
		{

			SendMessage(but_group[7], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[7] = 2;
			return 0;
		}

		if (!mas[9])//zanimaem ugol 9 esli pusto
		{

			SendMessage(but_group[9], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[9] = 2;
			return 0;
		}
	}

	for (i = 1; i < 10; i++)//zanimaem lubuyu pustuyu kletku
		if (!mas[i])
		{

			SendMessage(but_group[i], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
			mas[i] = 2;
			return 0;
		}
	return 3; //nichia

}

void FillWindow(HWND hWnd)
{
	using namespace myglobal;

	int id = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			but_group[id + 1] = CreateWindow(TEXT("button"), NULL, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_ICON, 10 + (80 * i), 10 + (80 * j), 70, 70, hWnd, (HMENU)(1001 + id), 0, 0);
			id++;
		}
	}
	O_img = LoadImage(NULL, L"O_img.ico", IMAGE_ICON, 70, 70,
		LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);


	X_img = LoadImage(NULL, TEXT("X_img.ico"), IMAGE_ICON, 70, 70,
		LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	hEdit1 = CreateWindowEx(WS_EX_CONTROLPARENT, TEXT("edit"),
		TEXT(""),
		WS_VISIBLE | WS_CHILD | ES_CENTER |
		ES_MULTILINE | ES_READONLY,
		10, 260, 230, 30, hWnd, (HMENU)ID_EDIT1, 0, 0);

	hMainMenu = CreateMenu();
	HMENU hPopMenuGame = CreatePopupMenu();
	HMENU hPopMenuSet = CreatePopupMenu();
	AppendMenu(hMainMenu, MF_STRING | MF_POPUP, (UINT)hPopMenuGame, L"Игра");
	AppendMenu(hPopMenuGame, MF_STRING, ID_NEWGAME, L"Начать новую игру");
	AppendMenu(hPopMenuGame, MF_STRING, ID_ABOUT, L"Об игре");

	AppendMenu(hMainMenu, MF_STRING | MF_POPUP, (UINT)hPopMenuSet, L"Настройки");
	AppendMenu(hPopMenuSet, MF_STRING | MF_UNCHECKED, ID_PCFIRST, L"Компютер ходит первым");

	HMENU hPopMenuDif = CreatePopupMenu();
	AppendMenu(hPopMenuSet, MF_STRING | MF_POPUP, (UINT)hPopMenuDif, L"Уровень Сложности");
	AppendMenu(hPopMenuDif, MF_STRING | MF_CHECKED, ID_SIMPLE, L"Обычный");
	AppendMenu(hPopMenuDif, MF_STRING | MF_UNCHECKED, ID_IMP, L"Нереально");

	SetMenu(hWnd, hMainMenu);
	SetMenu(hWnd, hPopMenuGame);
	SetMenu(hWnd, hPopMenuSet);
	SetMenu(hWnd, hPopMenuDif);
}

void RunGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	using namespace myglobal;
	for (i = 1; i < 10; i++)
	{
		if (((HWND)lParam == but_group[i]) && (HIWORD(wParam) == BN_CLICKED) && !mas[i])
		{
			SendMessage(but_group[i], BM_SETIMAGE, IMAGE_ICON, (LPARAM)X_img);
			f = mas[i] = 1;
			break;
		}
	}
	if (f)
	{
		f = PC_logik();
		if (f == 1) {
			SetWindowText(hEdit1, TEXT("Вы проиграли")); run = 0;
		}
		if (f == 2) {
			SetWindowText(hEdit1, TEXT("Вы выиграли")); run = 0;
		}
		if (f == 3) { SetWindowText(hEdit1, TEXT("Ничья.")); run = 0; }
		if (!f)
		{
			for (i = 1; i < 10; i++)
				if (!mas[i]) break;
			if (i == 10)
			{
				SetWindowText(hEdit1, TEXT("Ничья.")); run = 0;
			}
		}
	}
}

void ClearButtons()
{
	using namespace myglobal;
	for (i = 1; i < 10; i++)
	{
		SendMessage(but_group[i], BM_SETIMAGE, IMAGE_ICON, 0);
		mas[i] = 0;
	}
	f = 0;
}

LRESULT CALLBACK WndProc
(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	using namespace myglobal;

	switch (message)
	{
	case WM_CREATE://vikonuetsia odin raz pri zapusku
	{
		FillWindow(hWnd);
	}
	break;

	case WM_COMMAND:
	{
		if (run) RunGame(hWnd, wParam, lParam);

		switch (LOWORD(wParam))
		{
		case ID_PCFIRST:
		{
			if (BN_CLICKED == HIWORD(wParam))
			{

				if (CheckMenuItem(hMainMenu, ID_PCFIRST, MF_BYCOMMAND | MF_UNCHECKED) == MF_CHECKED) {
					step = 0;
					break;
				}
				else {
					if (CheckMenuItem(hMainMenu, ID_PCFIRST, MF_BYCOMMAND | MF_CHECKED) == MF_UNCHECKED)
						step = 1;
					else step = 0;
				}
			}
		}
		break;

		case ID_SIMPLE:
		{
			if (BN_CLICKED == HIWORD(wParam))
			{
				if (CheckMenuItem(hMainMenu, ID_SIMPLE, MF_BYCOMMAND | MF_CHECKED) == MF_UNCHECKED) {
					CheckMenuItem(hMainMenu, ID_IMP, MF_BYCOMMAND | MF_UNCHECKED);
					lev = 0;
				}
				else  lev = 1;
			}
		}
		break;

		case ID_IMP:
		{
			if (BN_CLICKED == HIWORD(wParam))
			{
				if (CheckMenuItem(hMainMenu, ID_IMP, MF_BYCOMMAND | MF_CHECKED) == MF_UNCHECKED) {
					CheckMenuItem(hMainMenu, ID_SIMPLE, MF_BYCOMMAND | MF_UNCHECKED);
					lev = 1;
				}
				else   lev = 0;
			}
		}break;

		case ID_NEWGAME:
		{

			if (BN_CLICKED == HIWORD(wParam))
			{
				ClearButtons();
				if (step)
				{
					SendMessage(but_group[5], BM_SETIMAGE, IMAGE_ICON, (LPARAM)O_img);
					mas[5] = 2;
				}

				run = 1;
				SetWindowText(hEdit1, TEXT("Ваш ход."));
			}
		}break;


		case ID_ABOUT:
		{
			if (BN_CLICKED == HIWORD(wParam)) {
				MessageBox(NULL, L"Крестики-Нолики v.1.0 by KhomenkoGames\n\t\t2017", L"Об игре", MB_OK | MB_ICONASTERISK);
			}
		}break;
		}
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

class ClassWin
{
protected:
	LPCWSTR Name;
	WNDCLASSEX wc;
public:
	ClassWin(HINSTANCE, LPCWSTR, WNDPROC);
	LPCWSTR get_name() { return Name; }
};
ClassWin::ClassWin(HINSTANCE hinst, LPCWSTR cName, WNDPROC wProc)
{
	wc = { 0 };
	Name = cName;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hinst;
	wc.lpfnWndProc = wProc;
	wc.lpszClassName = Name;
	wc.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	wc.hCursor = LoadCursor(NULL, IDC_HAND);

	if (!RegisterClassEx(&wc))
		MessageBox(NULL, L"Klass ne zareestrovano!", L"Error", MB_SYSTEMMODAL);
}
INT WINAPI WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstace, LPSTR kpCmdLine, int nCmdShow)
{
	ClassWin MyWin(hInstance, L"MyClWin", WndProc);

	HWND hForm = CreateWindow(MyWin.get_name(), L"Крестики нолики by KhomenkoGames", WS_OVERLAPPEDWINDOW,
		50, 60, 265, 360, 0, 0, hInstance, 0);

	if (!hForm)
	{
		MessageBox(NULL, L"Window not created!", L"Error", MB_SYSTEMMODAL);
		return 2;
	}

	//vikno upravlenie
	ShowWindow(hForm, SW_SHOW);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (INT)msg.wParam;
}
