#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  
	int fontColor[21] = { 4,12,4,5,13,5,1,9,1,3,11,3,2,10,2,6,14,6,15,7,0 };
	int uColor[7] = { 12,13,9,11,10,14,15 };
	
	for(int j = 0, i = 0; j < 100000000; ++j){
		system("cls");
		if (i > 21) i = 0;
		SetConsoleTextAttribute(hStdOut,fontColor[i]);
        cout << "         @" << endl;;
		SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN);
		cout << "         *" << endl;
        cout << "        ***" << endl;
        cout << "      *******" << endl;
        SetConsoleTextAttribute(hStdOut,uColor[rand()%7]);
        cout << "    $";
        SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN);
        cout << "*********";
        SetConsoleTextAttribute(hStdOut,uColor[rand()%7]);
        cout << "$" <<endl;
        SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN);
        cout << "      *******" << endl;
        cout << "    ***********" << endl;
        SetConsoleTextAttribute(hStdOut,uColor[rand()%7]);
        cout << "  $";
        SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN);
        cout << "*************";
        SetConsoleTextAttribute(hStdOut,uColor[rand()%7]);
        cout << "$" <<endl;
        SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN);
        cout << "    ***********" << endl;
        cout << "   *************" << endl;
        SetConsoleTextAttribute(hStdOut,uColor[rand()%7]);
        cout << "$";
        SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN);
        cout << "*****************";
        SetConsoleTextAttribute(hStdOut,uColor[rand()%7]);
        cout << "$" <<endl;
        SetConsoleTextAttribute(hStdOut,8);
        cout << "        ||" << endl;
		Sleep(350);	
		++i;
	}
		
    return 0;
}
