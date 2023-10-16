#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>

// do something after any minutes of user inactivity
static const unsigned int idle_milliseconds = 60 * 1 * 1000;

void moveMouse(int x, int y) {
    int count = 100;
    int movex, movey;
    float angle = 0.0f;
    // set mouse at center screen
    SetCursorPos(x / 2, y / 2);
    for (int i = 0; i <= count; i++) {
        angle = .3 * i;
        movex = (angle * cos(angle) * 2) + x / 2;
        movey = (angle * sin(angle) * 2) + y / 2;
        SetCursorPos(movex, movey);
        Sleep(1);
    }
}

int main() {
    HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
    ShowWindow(hConsole, SW_HIDE);//собственно прячем оконо консоли

    DWORD currentTime;
    LASTINPUTINFO last_input;
    last_input.cbSize = sizeof(LASTINPUTINFO);
    int Height = GetSystemMetrics(SM_CYSCREEN);
    int Width = GetSystemMetrics(SM_CXSCREEN);

    // main loop to check if user has been idle long enough
    for (;;) {
        currentTime = GetTickCount();
        if (!GetLastInputInfo(&last_input)) {
            std::cerr << "WinAPI failed!" << std::endl;
            return 0;
        }
        currentTime > last_input.dwTime ? last_input.dwTime = currentTime - last_input.dwTime : last_input.dwTime = last_input.dwTime - currentTime;
        if (last_input.dwTime < idle_milliseconds) {
            // user hasn't been idle for long enough
            Sleep(1000);
            continue;
        }
        // user has been idle at least 4 minutes
        moveMouse(Width, Height);
        // done. Wait before doing the next loop.
        Sleep(idle_milliseconds);
    }




    return 0;
}
