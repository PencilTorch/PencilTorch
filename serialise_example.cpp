




#include <iostream>
#include <fstream>

class Kunde {
public:
    std::string familename;
    std::string vorname;
    int jhre;

    friend std::ostream& operator<<(std::ostream & os, const Kunde& kunde) {
    
        os << kunde.familename << " " << kunde.vorname << " " << kunde.jhre;
        return os;
    }

    friend std::ifstream& operator>>(std::ifstream& is, Kunde& kunde) {
    
        is >> kunde.familename >> kunde.vorname>> kunde.jhre;
        return is;
    }

};

int main()
{
    Kunde erstekunde;
    erstekunde.familename = "Muller";
    erstekunde.vorname = "Greta";
    erstekunde.jhre = 25;
    // Сериализация объекта в файл
    std::ofstream outFile("kunden.dat");
    outFile << erstekunde;
    outFile.close();
    // Десериализация объекта из файла
    Kunde zweitekunde;
    std::ifstream inFile("kunden.dat");
    inFile >> zweitekunde;
    inFile.close();

    std::cout << "\n\n\t\tResult > "<< zweitekunde.familename<<", "<< zweitekunde.vorname << ", " << zweitekunde.jhre<<"\n\n";
    system("pause");
    return 0;
}







