#include <iostream>
#include <stdlib.h>
#include <windows.h> 
#include <iomanip>
using namespace std;


void gotoxy ( short x, short y )
{
  COORD coord = {x, y};
  SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
}

void MovimentaPalavra(string msg) {
    for (int j = 0; j < msg.length(); j++) {
        for (int i = 10; i <= 20; i++) {
            gotoxy(j + 5, i);
            cout << msg[j];

            if (i > 10) {
                gotoxy(j + 5, i - 1);
                cout << " ";
            }
            Sleep(100);
        }
    }
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	string palavra;
	cout << "Digite uma palavra para ser exibida";
	cin >> palavra;
	
	gotoxy(5,10);   
    cout << palavra << endl;
    MovimentaPalavra(palavra);
	
	return 0;
}
