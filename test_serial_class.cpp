#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "sqlite3.h"
//#include <sqlite3.h>
using namespace std;

sqlite3* db = 0; // хэндл объекта соединение к БД
char* err = 0;
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

std::string str;

static int callback2(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        str += std::string(azColName[i]) + " = " + std::string(argv[i]) + "\n";
    }
    str += "\n";

    return 0;
}

const char* SQL1 = "CREATE TABLE IF NOT EXISTS logfile (id INTEGER, name TEXT NOT NULL, quest INT DEFAULT 0, passage BLOB, PRIMARY KEY(id AUTOINCREMENT));";
const char* SQL2 = "INSERT INTO logfile(name, quest, passage) VALUES(\'Jack\', 25, \'black\');";
const char* SQL3 = "SELECT * FROM logfile;";

struct TestPassage {
    int test_id;
    std::vector<std::pair<int, bool>> vPassage;
};


class LogFile {
public:
    LogFile(int id, string lname) {
        autirize_id = id;
        login_name = lname;
    }
    LogFile() {
        autirize_id = 0;
        login_name = "";
    }
    void Print() {
        cout << "autirize_id = " << autirize_id << endl;
        cout << "login_name = " << login_name << endl;
    }
    // возможно кривая сериализация, проверить без sql
    // Методы записи / чтения текущих данных(сериализации)
    void SaveToFile() {
        std::ostringstream oss;
        oss.str(login_name);
        int len = login_name.length();
        oss.write((char*)&len, sizeof(int));
        for (int i = 0; i < login_name.length(); i++)
            oss.write((char*)&login_name[i], sizeof(login_name[i]));
        oss.write((char*)&autirize_id, sizeof(int));
        string SQL = "INSERT INTO logfile(name, quest, passage) VALUES(\'Jack\', 25, \'" + oss.str() + "\');";
        int rc = sqlite3_exec(db, SQL.c_str(), callback, 0, &err);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", err);
            sqlite3_free(err);
        }
        else {
            fprintf(stdout, "INSERT in table successfully\n");
        }
    }

    // Чтение массива из файла и запись в текущий экземпляр
    bool ReadFromFile(const char* filename) {
        // 1. Создать экземпляр класса ifstream
        ifstream inF(filename, ios::in | ios::binary);
        // 2. Проверка, открыт ли файл успешно
        if (!inF.is_open()) return false;
        // 3. Чтение полей объекта
        // 3.1. Поле login_name
        // 3.1.1. Считать количество элементов в поле login_name
        int len;
        inF.read((char*)&len, sizeof(int));
        // 3.1.2. Считать строку в цикле
        char c;
        login_name = "";
        for (int i = 0; i < len; i++) {
            inF.read((char*)&c, sizeof(c));
            login_name += c;
        }
        // 3.3. Поле autirize_id типа int
        inF.read((char*)&autirize_id, sizeof(int));
        // Закрыть файл
        inF.close();
        // Код возврата
        return true;
    }

private:
    int autirize_id;
    std::string login_name;
    //TestPassage _tp;
};


bool insert_request(const string& name, const int quest, const string& passage) {
    string statistic_query = string("INSERT INTO logfile(name, quest, passage) VALUES (\'" + name + "\', " + std::to_string(quest) + ", \'" + passage + "\');");
    int request_status = sqlite3_exec(db, statistic_query.c_str(), callback, 0, &err);
    if (request_status != SQLITE_OK) {
        fprintf(stderr, "Ошибка SQL: %sn", err);
        sqlite3_free(err);
        return false;
    }
    else {
        fprintf(stdout, "INSERT in table successfully\n");
        return true;
    }
}

int main() {
    // открываем соединение
    int rc;
    rc = sqlite3_open("my_cosy_database.db3", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
    rc = sqlite3_exec(db, SQL1, callback, 0, &err);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    }
    else {
        fprintf(stdout, "Create table successfully\n");
    }
    
    // //insert_request("Shir", 100, "preshes");
    
    rc = sqlite3_exec(db, SQL2, callback, 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    }
    else {
        fprintf(stdout, "INSERT in table successfully\n");
    }

    rc = sqlite3_exec(db, SQL3, callback2, 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    }
    else {
        fprintf(stdout, "SELECT from table successfully\n");
    }
    // закрываем соединение
    sqlite3_close(db);

    std::cout << str;


    // 1. Создать объект типа BOOK
    LogFile obj1(20, "Doktor Dre");

    // 2. Сохранить объект obj1
    //obj1.Print();

    // 3. Записать в файл obj1 => "obj1.bin"
    obj1.SaveToFile();

    // 4. Создать другой объект типа BOOK
    //LogFile obj2;

    // 5. Считать данные из файла obj1.bin в объект obj2
    // "obj1.bin" => obj2
    //obj2.ReadFromFile("obj1.bin");

    // 6. Вывести прочитанный объект
    //obj2.Print();

    return 0;
}