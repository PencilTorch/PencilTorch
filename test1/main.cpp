//из списка через ; в список с новой строки каждый элемент списка
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sqlite3.h>

const char* SOURSE = "sourse.txt";
const char* OUTPUT = "output.txt";
const char* MyBAZA = "AntiSpam.sqlite3";

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
void fillSQLSW(const char* sql_base, const std::vector<std::string>& vsw) {
    sqlite3* _db = nullptr;
    char* _err = nullptr;
    int rc = sqlite3_open(sql_base, &_db);
    if (rc != SQLITE_OK) {
        std::cout << "Can't open database: " << _err << std::endl << sqlite3_errmsg(_db);
        sqlite3_close(_db);
    }
    else
        std::cout << "Opened database successfully! " << std::endl;
    /*=================================================================*/
    sqlite3_stmt* _res = nullptr;
    std::string SQL = "INSERT INTO StopWords(word) VALUES (?);";
    for(auto& it : vsw) {
        rc = sqlite3_prepare_v2(_db, SQL.c_str(), (int)SQL.size(), &_res, 0);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error request to stopwords, SQL error: %s\n", _err);
            sqlite3_free(_err);
        }
        else {
            sqlite3_bind_text(_res, 1, it.c_str(), -1, SQLITE_STATIC);
            if (SQLITE_DONE != sqlite3_step(_res))
                fprintf(stderr, "Error insert into stopwords, SQL error: %s\n", _err);
        }
    }
    sqlite3_finalize(_res);
    sqlite3_close(_db);
}

int main() {
    std::vector<std::string> vsw;
    //convertVerticalList(SOURSE, OUTPUT);
    fillVSW(vsw, "stop_words.txt");
    clearRepid(vsw);
    std::sort(vsw.begin(), vsw.end());
    //fromVectorToFile(vsw, "stop_words.txt");
    fillSQLSW(MyBAZA, vsw);

  return 0;
}



