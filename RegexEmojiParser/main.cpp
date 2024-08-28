// Вытаскивание utf-кодов эмодзи из файла
//
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

#define PATH "utf-kody-emoji.html"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::ifstream fin(PATH);
    std::string str, strAll;
    if (fin.is_open()) {
        while (std::getline(fin, str)) {
            strAll += str;
            str.clear();
          }
    }
    fin.close();
    //
    std::regex regular("<code>([.]*)</code>");
    //итераторы по строке
    std::regex_iterator<std::string::iterator> it_begin(strAll.begin(), strAll.end(), regular);
    std::regex_iterator<std::string::iterator> it_end;
    std::string resp;
    while (it_begin != it_end) {
        std::smatch m;
        std::string ss = it_begin->str();
        std::regex_search(ss, m, regular);
        resp += m[1];
        resp += '\n';
    }

    std::cout << resp << std::endl;

    return 0;
}

