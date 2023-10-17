#include <Windows.h>
#include <iostream>

const unsigned int idle_milliseconds = 60 * 4 * 1000;


int main() {
    HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
    ShowWindow(hConsole, SW_HIDE);//собственно прячем оконо консоли

    // main loop to check if user has been idle long enough
    for (;;) {
        keybd_event(VK_F15, 0, 0, 0);
        keybd_event(VK_F15, 0, KEYEVENTF_KEYUP, 0);
        Sleep(idle_milliseconds);
    }

    return 0;
}
