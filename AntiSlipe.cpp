#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>

// do something after 4 minutes of user inactivity
static const unsigned int idle_milliseconds = 60 * 1 * 1000;

void moveMouse(int x, int y) {
    int step = 10;
    for (int i = 0; i < 30; i++) {
        Sleep(100);
        SetCursorPos(x += step, y);
    }
    for (int i = 0; i < 30; i++) {
        Sleep(100);
        SetCursorPos(x, y += step);
    }
    for (int i = 0; i < 30; i++) {
        Sleep(100);
        SetCursorPos(x -= step, y);
    }
    for (int i = 0; i < 30; i++) {
        Sleep(100);
        SetCursorPos(x, y -= step);
    }
}

int main() {
    HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
    ShowWindow(hConsole, SW_HIDE);//собственно прячем оконо консоли

    DWORD currentTime = GetTickCount();

    LASTINPUTINFO last_input;
    last_input.cbSize = sizeof(LASTINPUTINFO);
    int Height = GetSystemMetrics(SM_CYSCREEN);
    int Width = GetSystemMetrics(SM_CXSCREEN);

    // main loop to check if user has been idle long enough
    for (;;) {
        if (!GetLastInputInfo(&last_input)) {
            std::cerr << "WinAPI failed!" << std::endl;
            return 0;
        }
        last_input.dwTime = last_input.dwTime - currentTime;
        if (last_input.dwTime < idle_milliseconds) {
            // user hasn't been idle for long enough
            Sleep(1000);
            continue;
        }
        // set mouse at center screen
        SetCursorPos(Width / 2, Height / 2);
        // user has been idle at least 4 minutes
        moveMouse(Width / 2, Height / 2);
        // done. Wait before doing the next loop.
        Sleep(idle_milliseconds);
    }




    return 0;
}
