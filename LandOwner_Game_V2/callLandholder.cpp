#include "pickLandlord.hpp"

pickLandlord::pickLandlord(/* args */){}

pickLandlord::~pickLandlord(){}

void pickLandlord::callLandholder() {
    int pick;
    std::cout << ">> 1. Call landholder\n"
              << ">> 2. Dont call";
    std::cin >> pick;
    while((pick != 1) && (pick != 2)) {
        std::cout << "Vuelva a eligir una opcion:";
        std::cin >> pick;
    }
}

void pickLandlord::robLandholder() {
    int pick;
    std::cout << ">> 1. Rob Landholder\n"
              << ">> 2. Dont Rob";
    std::cin >> pick;
    while((pick != 1) && (pick != 2)) {
        std::cout << "Vuelva a eligir una opcion:";
        std::cin >> pick;
    }
}