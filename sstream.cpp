// http://www.itmathrepetitor.ru/s-lekciya-9-rabota-s-potokami-v-s/
// https://pro-prof.com/forums/topic/cpp_files_io
// https://prog-cpp.ru/cpp-files/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ostringstream oss;
    string s;
    oss.str("Sample string_1.");
    s = oss.str();
    cout << s << endl;
    oss << "Sample string_2.";

    s = oss.str();
    cout << s << endl;

    return 0;
}
