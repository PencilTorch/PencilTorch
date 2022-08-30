#include <windows.h>
#include <wininet.h>
#pragma comment(lib,"wininet")

#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    bool ok = false;

    // инициализируем WinInet
    HINTERNET hInternet =
        ::InternetOpen(
            TEXT("WinInet Test"),
            INTERNET_OPEN_TYPE_PRECONFIG,
            NULL, NULL,
            0);

    if (hInternet != NULL) {
        // открываем HTTP сессию
        HINTERNET hConnect =
            ::InternetConnect(
                hInternet,
                TEXT("news.mail.ru"),
                INTERNET_DEFAULT_HTTP_PORT,
                NULL, NULL,
                INTERNET_SERVICE_HTTP,
                0,
                1u);

        if (hConnect != NULL) {
            // открываем запрос
            HINTERNET hRequest =
                ::HttpOpenRequest(
                    hConnect,
                    TEXT("GET"),
                    TEXT("/society/52829545/"),
                    NULL,
                    NULL,
                    0,
                    INTERNET_FLAG_KEEP_CONNECTION,
                    1);

            if (hRequest != NULL) {
                // посылаем запрос
                BOOL bSend = ::HttpSendRequest(hRequest, NULL, 0, NULL, 0);
                if (bSend) {
                    // создаём выходной файл
                    ofstream fnews("news.html", ios::out | ios::binary);
                    if (fnews.is_open()) for (;;) {
                        // читаем данные
                        char  szData[1024];
                        DWORD dwBytesRead;
                        BOOL bRead =
                            ::InternetReadFile(
                                hRequest,
                                szData, sizeof(szData) - 1,
                                &dwBytesRead);

                        // выход из цикла при ошибке или завершении
                        if (bRead == FALSE || dwBytesRead == 0)
                            break;

                        // сохраняем результат
                        szData[dwBytesRead] = 0;
                        fnews << szData;

                        ok = true;
                    }
                }
                // закрываем запрос
                ::InternetCloseHandle(hRequest);
            }
            // закрываем сессию
            ::InternetCloseHandle(hConnect);
        }
        // закрываем WinInet
        ::InternetCloseHandle(hInternet);
    }

    // для полного счастья, запускаем считанную страничку
    if (ok)
        system("start news.html");

    return 0;
}