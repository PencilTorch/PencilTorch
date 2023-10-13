
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>

// do something after 4 minutes of user inactivity
static const unsigned int idle_milliseconds = 60 * 4 * 1000;

void moveMouse(int x, int y) {
    // set mouse at center screen
    SetCursorPos(x / 2, y / 2);
    Sleep(1);
    SetCursorPos((x / 2) + 10, (y / 2) + 10);
}

int main() {
    HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
    ShowWindow(hConsole, SW_HIDE);//собственно прячем оконо консоли
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