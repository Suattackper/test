#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
char Bua[7][30] = {"       __   __   __     ",
				"     /'::/..../':::\\    ",
				"  /./.../..../..../.|   ",
				"(.(....(....(..../.)...)",
				" \\................\\//../",
				"  \\.................../ ",
				"   \\.................(  "};

char Keo[9][30] = { "      _         __   ",
				"    |:::|     /:::/  ",
				"    |:::|    /:::/   ",
				"  _ |:::|   /:::/    ",
				"(:::|:::|::(:::(:::\\ ",
				"|:::|:::|::|:::|::::)",
				"|:::::::::::::::::::/",
				" \\:::::::::::::::::/ ",
				"  \\:::::::::::::::/  " };

char Bao[9][30] = { "         /'\\",
				"     /'\\|:::|/'\\",
				" /'\\|:::|:::|:::|:\\",
				"|:::[:::]:::|:::|::\\",
				"|:::|:::|:::|:::|:::\\",
				"|:~:~::~::~:|::::|::)",
				"|:::::::::::::::::::/",
				" \\:::::::::::::::::/",
				"  \\:::::::::::::::/" };
char Win[9][40] = { "\\:\\    /:/\\:\\    /:/",
				" \\:\\  /:/  \\:\\  /:/   ",
				"  \\:\\/:/    \\:\\/:/      ",
				"         |:|",
				"         |:|",
				"         |:|",
				"     |:|\\:\\  |:|",
				"     |:| \\:\\ |:|",
				"     |:|  \\:\\|:|" };
char Loss[18][40] = { " |:|",
					" |:|",
					" |:|",
					" \\:\\:|:|:|:|",
					"    /:/:|:|:\\:\\",
					"   |:|       |:|",
	                "   |:|       |:|",
					"    \\:\\:|:|:/:/",
					"/:/:|:|:|:|",
					"|:|",
					"\\:\\:|:|:\\:\\",
					"         |:|",
					"|:|:|:|:/:/",
					"   /:/:|:|:|:|",
					"   |:|",
					"   \\:\\:|:|:\\:\\",
					"            |:|",
					"   |:|:|:|:/:/" };
char Draw[16][40] = { "    |:|::|::|::\\:\\",
					"    |:|         |:|",
					"    |:|         |:|",
					"    |:|::|::|::/:/",
					"     |:|::|::\\:\\",
					"     |:|      |:|",
					"     |:|::|::/:/",
					"     |:|     \\:\\",
					"     |:|      \\:\\ ",
					"       /:/:\\:\\",
					"      /:/   \\:\\",
					"     /:/:|:|:\\:\\",
					"    /:/       \\:\\",
					"\\:\\    /:/\\:\\    /:/",
					" \\:\\  /:/  \\:\\  /:/   ",
					"  \\:\\/:/    \\:\\/:/      " };
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
void ToMau(int x, int y, char* a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
//Hàm vẽ búa
void VeBua(int x, int y) {
	textcolor(6);
	for (int i = 0; i < 7; i++) {
		gotoxy(x, y);
		printf("%s", Bua[i]);
		y++;
	}
}
//Hàm vẽ kéo
void VeKeo(int x, int y) {
	textcolor(10);
	for (int i = 0; i < 9; i++) {
		gotoxy(x, y);
		printf("%s", Keo[i] );
		y++;
	}
}
//Hàm vẽ bao
void VeBao(int x, int y) {
	textcolor(12);
	for (int i = 0; i < 9; i++) {
		gotoxy(x, y);
		printf("%s", Bao[i]);
		y++;
	}
}
//Vẽ win
void VeWin(int x, int y) {
	textcolor(14);
	for (int i = 0; i < 9; i++) {
		gotoxy(x, y);
		printf("%s", Win[i]);
		y++;
	}
}
//Vẽ loss
void VeLoss(int x, int y) {
	textcolor(14);
	for (int i = 0; i < 18; i++) {
		gotoxy(x, y);
		printf("%s", Loss[i]);
		y++;
	}
}
//Vẽ draw
void VeDraw(int x, int y) {
	textcolor(14);
	for (int i = 0; i < 16; i++) {
		gotoxy(x, y);
		printf("%s", Draw[i]);
		y++;
	}
}