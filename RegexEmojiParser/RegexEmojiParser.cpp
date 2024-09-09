// Вытаскивание utf-кодов эмодзи из файла
//
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

//#define PATH "utf-kody-emoji.html"

//https://symbl.cc/en/unicode-table/#cyrillic 
//https://ru.wikipedia.org/wiki/%D0%AD%D0%BC%D0%BE%D1%82%D0%B8%D0%BA%D0%BE%D0%BD%D1%8B_(%D0%B1%D0%BB%D0%BE%D0%BA_%D0%AE%D0%BD%D0%B8%D0%BA%D0%BE%D0%B4%D0%B0)
//https://gist.github.com/slowkow/7a7f61f495e3dbb7e3d767f97bd7304b

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    //Ѐ \U+400 \U000400
    wchar_t wch{ U'\U00000400' };

    std::wcout << wch << std::endl;

    return 0;
}

/*
парс html-файла на нужные участки и сохранение этого в файл

std::ifstream fin(PATH);
    std::string str;
    std::string strAll;
    if (fin.is_open()) {
        while (std::getline(fin, str)) {
            strAll = strAll + str;
            str.clear();
        }
    }
    fin.close();
    //
    std::regex regular("<div class=\"UTF\"><code>(.*?)</code>"); //всё, что между
    //итераторы по строке
    std::regex_iterator<std::string::iterator> it_begin(strAll.begin(), strAll.end(), regular);
    std::regex_iterator<std::string::iterator> it_end;
    if (it_begin == it_end)
        std::cout << "Regular not work! Nothing else matters..\n";
    std::string resp;
    while (it_begin != it_end) {
        std::smatch m;
        std::string ss = it_begin->str();
        std::regex_search(ss, m, regular);
        resp += m[1];
        resp += '\n';
        it_begin++;
    }
    //write in file
    std::ofstream fout("utf-emodzi.txt");
    if (fout.is_open()) {
        fout << resp;
        std::cout << "all good" << std::endl;
    }
    fout.close();
*/