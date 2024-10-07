//из списка через ; в список с новой строки каждый элемент списка
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

const char* SOURSE = "sourse.txt";
const char* OUTPUT = "output.txt";

void fillVSW(std::vector<std::string>& v, const char* sourse) {
    std::ifstream fin(sourse);
    if (fin.is_open()) {
        std::string stmp;
        while(std::getline(fin, stmp))
            v.push_back(stmp);
    }
}
void convertVerticalList(const char* sourse, const char* output) {
    std::vector<std::string> vstr;
    std::ifstream fin(sourse);
    if (fin.is_open()) {
        std::cout << "open sourse in convertVerticalList(...)" << std::endl;
        std::string str;
        while(std::getline(fin, str)){
            size_t it1 = 0;
            size_t it2 = str.find_first_of(';', 0);
            while(it2 != std::string::npos){
                std::string tmp = str.substr(it1, it2 - it1);
                vstr.push_back(tmp);
                it1 = it2 + 1;
                it2 = str.find_first_of(';', it1);
            }
        }
    }
    fin.close();
    std::ofstream fout(output, std::ios::app);
    if (fout.is_open()) {
        std::cout << "open output in convertVerticalList(...)" << std::endl;
        for(auto &it : vstr){
            fout << it + '\n';
        }
    }
    fout.close();
}
void clearRepid(std::vector<std::string>& v) {
    for(std::vector<std::basic_string<char>>::iterator it1 = v.begin(); it1 != v.end() - 1; ++it1){
        for(std::vector<std::basic_string<char>>::iterator it2 = it1 + 1; it2 != v.end(); ++it2){
            if(*it1 == *it2)
                it2 = v.erase(it2) - 1;
        }
    }
}
void fromVectorToFile(std::vector<std::string>& v, const char* output) {
    std::ofstream fout(output, std::ios::app);
    if (fout.is_open()) {
        std::cout << "open output in fromVectorToFile(...)" << std::endl;
        for(auto &it : v){
            fout << it + '\n';
        }
    }
    fout.close();
}

int main() {
    std::vector<std::string> vsw;
    convertVerticalList(SOURSE, OUTPUT);
    fillVSW(vsw, OUTPUT);
    clearRepid(vsw);
    std::sort(vsw.begin(), vsw.end());
    fromVectorToFile(vsw, "stop_words.txt");

  return 0;
}



