#include <cstdlib>
#include "Warehouse.h"

//parametr szablonu
//liczba całkowita albo

//dlaczego template w headerze
//bo to nie implementacja, tylko template
int main() {
    unsigned long n, m;
    std::cout << "podaj wielkosc magazynu w formacie <liczpa polek> <wysokosc polek>:\n";
    std::cin >> n >> m;

    Warehouse warehouse(n, m);

    int decision;
    std::cout << "Wybierz co chcesz zrobić:\n0 dodać nową paczkę\n1 pobrac istniejącą paczkę\n";
    std::cin >> decision;
    while (!std::cin.eof()) {
        switch (decision) {
            case 0 :{
                std::cout << "podaj nazwe pakietu\n";
                std::string tmp;
                std::cin >> tmp;
                warehouse.acceptPackage(tmp);
                break;
            }
            case 1 :{
                std::cout << "podaj nazwe pakietu, ktory chcesz wyszukac:\n";
                std::string tmp;
                std::cin >> tmp;
                try {
                    auto rec = warehouse.issuePackage(tmp);
                    std::cout << rec->getName() << '\n' << rec->getRecipient() << std::endl;
                } catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            default : {
                std::cout << "zła decyzja, podaj jescze raz\n";
                break;
            }
        }
        std::cout << "Wybierz co chcesz zrobić:\n0 dodać nową paczkę\n1 pobrac istniejącą paczkę\n";
        std::cin >> decision;
    }

    return 0;
}