//из списка через ; в список с новой строки каждый элемент списка
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vstr;
  std::ifstream fin("stop_words.txt");
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

  std::ofstream fout("output.txt", std::ios::app);
  if (fout.is_open()) {
      for(auto &it : vstr){
          fout << it + '\n';
      }
  }
  fout.close();


  return 0;
}
