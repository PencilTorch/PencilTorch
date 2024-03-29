// MakeMD5.cpp : хэширование в MD5 и сохранение в файл
//
#include <iostream>
#include <fstream>
#include <string>
#include "MD5.h"


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::string str = "Enter word for make MD5 hashing:";
    std::cout << str << std::endl;
    std::cin >> str;
    std::string pwd = md5(str);
    std::cout << pwd << std::endl;
    std::ofstream fout("md5-hash_word");
    if (fout.is_open()) {
        fout << pwd;
        std::cout << "the file with md5-hash word was created successfully!" << std::endl;
    }
    fout.close();

    return 0;
}
