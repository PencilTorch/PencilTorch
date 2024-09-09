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
    std::wstring rpEmoticons = L"[\U0001F600-\U0001F64F]+|"; //emoticons
    std::wstring rpSimPict = L"[\U0001F300-\U0001F5FF]+|"; //symbols & pictographs
    std::wstring rpTransMaps = L"[\U0001F680-\U0001F6FF]+|"; //transport & map symbols
    std::wstring rpFlags = L"[\U0001F1E0-\U0001F1FF]+|"; //flags (iOS)
    std::wstring rpChines = L"[\U00002500-\U00002BEF]+|"; //chinese char
    std::wstring rpArrows = L"[\u2194-\u2199\u21A9\u21AA\u23EA\u23EB\u23EC\u23ED\u23EE\u23EF]+|"; //arrows
    std::wstring rpOver1 = L"[\U00002702-\U000027B0]+|";
    std::wstring rpOver2 = L"[\U000024C2-\U0001F251]+|";
    std::wstring rpOver3 = L"[\U0001f926-\U0001f937]+|";
    std::wstring rpOver4 = L"[\U00010000-\U0010ffff]+|";
    std::wstring rpOver5 = L"[\u2640-\u2642]+|";
    std::wstring rpOver6 = L"[\u2600-\u2B55]+|";
    std::wstring rpOver7 = L"[\u200d\u23cf\u23e9\u231a\ufe0f\u3030\u23F0\u23F3\u231B\u2328\u203C\u2049\u00A9\u00AE\u2122]+";
    std::wstring rpSum = L"(" + rpEmoticons + rpSimPict + rpTransMaps + rpFlags + rpChines + rpArrows +
            rpOver1 + rpOver2 + rpOver3 + rpOver4 + rpOver5 + rpOver6 + rpOver7 + L")";
    std::wregex regPattern (rpSum);
    std::wstring wstr;
    while(1) {
        std::wcout << L"введи символ:" << std::endl;
        std::wcin >> wstr;
        std::wstring result = std::regex_replace(wstr, regPattern, L"");
        std::wcout << result << std::endl;

        /* emoji detected!
        std::wregex reg (L"(.*)([\U0001F600-\U0001F64F]+)(.*)");
        if(std::regex_match(wstr, reg)) {
            std::wcout << L"да, детка!" << std::endl;
        }
        else {
            std::wcout << L"что-то не так..." << std::endl;
        }
        */
        wstr.clear();
    }



    //Ѐ \U+400 \U000400
    //wchar_t wch{ U'\U00000400' };
    //std::wcout << wch << std::endl;

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
