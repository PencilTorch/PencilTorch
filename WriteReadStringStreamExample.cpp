// example of reading and writing a stream

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TestPassage {
    size_t test_id;
    std::string login_name;
};


int main() {
    /*
    * example simple number
    * 
    int number = 108;
    std::stringstream ss;
    ss.write(reinterpret_cast<const char*>(&number), sizeof(int));
    cout << ss.str() << endl;
    int number2;
    ss.read(reinterpret_cast<char*>(&number2), sizeof(int));
    cout << number2 << endl;
    */

    TestPassage tp;
    tp.test_id = 100500;
    tp.login_name = "Djigurda";
    
    //write
    std::stringstream ss;
    ss.setf(ios::binary | ios::app);
    ss.unsetf(ios::showpos);
    ss.write(reinterpret_cast<const char*>(&tp.test_id), sizeof(size_t));
    int len = tp.login_name.length();
    ss.write(reinterpret_cast<const char*>(&len), sizeof(int));
    ss.write(tp.login_name.c_str(), len);
    cout << "oss: " << ss.str() << endl;

    //read
    len = 0;
    TestPassage tp_copy;
    ss.read(reinterpret_cast<char*>(&tp_copy.test_id), sizeof(size_t));
    ss.read(reinterpret_cast<char*>(&len), sizeof(int));
    char* tmp = new char[len + 1] {'\0'};
    ss.read(tmp, len);
    tp_copy.login_name.assign(tmp, len);
    delete[] tmp;
    cout << "test_id: " << tp_copy.test_id << " login_name: " << tp_copy.login_name << endl;

    return 0;
}
