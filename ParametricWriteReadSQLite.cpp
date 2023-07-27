// https://metanit.com/c/database/1.5.php
// https://russianblogs.com/article/1931575077/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include "sqlite3.h"

using namespace std;

sqlite3* db = nullptr; // хэндл объекта соединение к БД
char* err = nullptr;

const char* SQL1 = "CREATE TABLE IF NOT EXISTS logfile (id INTEGER, name TEXT NOT NULL, quest INT DEFAULT 0, passage BLOB, PRIMARY KEY(id AUTOINCREMENT));";
const char* SQL2 = "INSERT INTO logfile(name, quest, passage) VALUES(\'Jack\', 25, \'black\');";
const char* SQL3 = "SELECT * FROM logfile;";

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


struct TestPassage {
    int test_id;
    std::vector<std::pair<int, bool>> vPassage;
};

class LogFile {
private:
    int autirize_id;
    std::string login_name;
    std::vector<TestPassage> _vTP;
public:
    LogFile(int id, string lname) {
        autirize_id = id;
        login_name = lname;
    }
    LogFile() {
        autirize_id = 0;
        login_name = "";
    }
    void addToVector(const TestPassage &tp) {
        _vTP.push_back(tp);
    }
    void Print() {
        cout << "autirize_id = " << autirize_id << endl;
        cout << "login_name = " << login_name << endl;
        for (size_t i = 0; i < _vTP.size(); ++i) {
            cout << "Test # " << _vTP[i].test_id << endl;
            for (size_t j = 0; j < _vTP[i].vPassage.size(); ++j) {
                cout << "Question #" << _vTP[i].vPassage[j].first << " answer: " << _vTP[i].vPassage[j].second << endl;
            }
            cout << endl;
        }
    }
    void Print(int test_num) {
        auto it = _vTP.end();
        it = std::find_if(_vTP.begin(), _vTP.end(), [&](const TestPassage& s) { return s.test_id == test_num; });
        if (it != _vTP.end()) {
            cout << "Test # " << it->test_id << endl;
            for (size_t i = 0; i < it->vPassage.size(); ++i)
                cout << "Question #" << it->vPassage[i].first << " answer: " << it->vPassage[i].second << endl;
        }
        else
            cout << "not this test number\n";
    }

    void SaveToBD(string nm, int qn) {
        std::ostringstream oss;
        oss.setf(ios_base::binary | ios_base::app);
        oss.unsetf(ios_base::showpos);
        oss.write(reinterpret_cast<const char*>(&autirize_id), sizeof(size_t));
        size_t len = login_name.length();
        oss.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
        oss.write(login_name.c_str(), len);
        len = _vTP.size();
        oss.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
        for (size_t i = 0; i < _vTP.size(); ++i) {
            oss.write(reinterpret_cast<const char*>(&_vTP[i].test_id), sizeof(int));
            len = _vTP[i].vPassage.size();
            oss.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
            for (size_t j = 0; j < _vTP[i].vPassage.size(); ++j) {
                oss.write(reinterpret_cast<const char*>(&_vTP[i].vPassage[j].first), sizeof(int));
                oss.write(reinterpret_cast<const char*>(&_vTP[i].vPassage[j].second), sizeof(bool));
            }
        }
        string tmp = oss.str();
        oss.clear();
        // параметрическая запись
        const char* SQL = "INSERT INTO logfile(name, quest, passage) VALUES(?, ?, ?);";
        sqlite3_stmt* stmtInsert = nullptr;
        int rc = sqlite3_prepare_v2(db, SQL, strlen(SQL), &stmtInsert, 0);
        sqlite3_bind_text(stmtInsert, 1, nm.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmtInsert, 2, qn);
        sqlite3_bind_blob(stmtInsert, 3, tmp.c_str(), tmp.size(), SQLITE_STATIC);
        int step = sqlite3_step(stmtInsert);
        if (step != SQLITE_DONE) {
            fprintf(stderr, "SQL error: %s\n", err);
            sqlite3_free(err);
        }
        else {
            fprintf(stdout, "INSERT in table successfully\n");
        }
        sqlite3_finalize(stmtInsert);
    }

   void ReadFromBD(const int id) {
        string SQL = "";
        if (id)
            SQL = "SELECT name, quest, passage FROM logfile  WHERE id = " + std::to_string(id) + ";";
        else
            SQL = "SELECT name, quest, passage FROM logfile;";
        cout << SQL << endl;
        sqlite3_stmt* res = nullptr;  // указатель на скомпилированное выражение (то, что вернет база)
        int rc = sqlite3_prepare_v2(db, SQL.c_str(), SQL.size(), &res, 0);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", err);
            sqlite3_free(err);
        }
        else {
            fprintf(stdout, "SELECT table successfully\n");
            while (sqlite3_step(res) == SQLITE_ROW) {
                printf("name: %s\t", sqlite3_column_text(res, 0));
                printf("quest num: %d\t", sqlite3_column_int(res, 1));
                int bytes = sqlite3_column_bytes(res, 2); //размер записи в байтах
                std::stringstream ss; // stream as buffer
                ss.write(reinterpret_cast<const char*>(sqlite3_column_blob(res, 2)), bytes);
                // парсим поток в экземпляр класса
                ss.read(reinterpret_cast<char*>(&autirize_id), sizeof(size_t));
                size_t len;
                ss.read(reinterpret_cast<char*>(&len), sizeof(size_t));
                // копирование строки через чаровый массив
                char* tmp = new char[len + 1]{ '\0' };
                ss.read(tmp, len);
                login_name.assign(tmp, len);
                delete[] tmp;
                ss.read(reinterpret_cast<char*>(&len), sizeof(size_t));
                _vTP.resize(len);
                for (size_t i = 0; i < _vTP.size(); ++i) {
                    ss.read(reinterpret_cast<char*>(&_vTP[i].test_id), sizeof(int));
                    ss.read(reinterpret_cast<char*>(&len), sizeof(size_t));
                    _vTP[i].vPassage.resize(len);
                    for (size_t j = 0; j < _vTP[i].vPassage.size(); ++j) {
                        ss.read(reinterpret_cast<char*>(&_vTP[i].vPassage[j].first), sizeof(int));
                        ss.read(reinterpret_cast<char*>(&_vTP[i].vPassage[j].second), sizeof(bool));
                    }
                }
                ss.clear();
            }
        }
        // удаляем скомпилированное выражение
        sqlite3_finalize(res);
    }
   //перегрузка оператора присваивания (тут не используется)
   LogFile& operator=(const LogFile& rhs) {
       this->autirize_id = rhs.autirize_id;
       this->login_name = rhs.login_name;
       this->_vTP.clear();
       this->_vTP.resize(rhs._vTP.size());
       for (size_t i = 0; i < rhs._vTP.size(); ++i) {
           this->_vTP[i].test_id = rhs._vTP[i].test_id;
           this->_vTP[i].vPassage.resize(rhs._vTP[i].vPassage.size());
           for (size_t j = 0; j < rhs._vTP[i].vPassage.size(); ++j) {
               this->_vTP[i].vPassage[j].first = rhs._vTP[i].vPassage[j].first;
               this->_vTP[i].vPassage[j].second = rhs._vTP[i].vPassage[j].second;
           }
       }
       return *this;
   }

};


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

    rc = sqlite3_exec(db, SQL3, callback, 0, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    }
    else {
        fprintf(stdout, "SELECT from table successfully\n");
    }

    // 1. Создать объект
    LogFile obj1(100500, "Doktor Pidor");
    LogFile obj2;
    TestPassage tp1;
    tp1.test_id = 33;
    tp1.vPassage.emplace_back(1, true);
    tp1.vPassage.emplace_back(2, true);
    tp1.vPassage.emplace_back(3, false);
    obj1.addToVector(tp1);

    TestPassage tp2;
    tp2.test_id = 55;
    tp2.vPassage.emplace_back(1, false);
    tp2.vPassage.emplace_back(2, true);
    tp2.vPassage.emplace_back(3, false);
    obj1.addToVector(tp2);
    
    
    //obj1.SaveToBD("Jo Dasen", 555);

    // читаем запись из базы с id=26 в пустой экземпляр класса
    obj2.ReadFromBD(26);
    obj2.Print();

    // закрываем соединение
    sqlite3_close(db);

    return 0;
}