//из списка через ; в список с новой строки каждый элемент списка
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define SOURSE "stop_words.txt"
#define OUTPUT "output.txt"

void fillVSW(std::vector<std::string>& v, std::string sourse);
void convertVerticalList(std::string sourse, std::string output);
void clearRepid(std::vector<std::string>& v);
void fromVectorToFile(std::vector<std::string>& v, std::string output);

int main() {
    std::vector<std::string> vsw;
    //convertVerticalList(SOURSE, OUTPUT);
    fillVSW(vsw, OUTPUT);
    clearRepid(vsw);
    std::sort(vsw.begin(), vsw.end());
    fromVectorToFile(vsw, OUTPUT);

  return 0;
}

void fillVSW(std::vector<std::string>& v, std::string sourse) {
    std::ifstream fin(sourse);
    if (fin.is_open()) {
        std::string stmp;
        while(std::getline(fin, stmp))
            v.push_back(stmp);
    }
}

void convertVerticalList(std::string sourse, std::string output) {
    std::vector<std::string> vstr;
    std::ifstream fin(sourse);
    if (fin.is_open()) {
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
        for(auto &it : vstr){
            fout << it + '\n';
        }
    }
    fout.close();
}

void clearRepid(std::vector<std::string>& v) {
    for(size_t it = 0; it < v.size(); ++it){
        for(size_t pos = it; pos < v.size(); ++pos){
            if (v[it] == v[pos]) {
                v.erase(v.begin() + pos);
            }
        }

    }
}

void fromVectorToFile(std::vector<std::string>& v, std::string output) {

}
