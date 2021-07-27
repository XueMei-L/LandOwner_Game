#include "callLandlord.hpp"

pickLandlord::pickLandlord(/* args */){}

pickLandlord::~pickLandlord(){}

/**
 * Function that call landlord
 * 叫/不叫地主
*/
void pickLandlord::callLandlord() {
    int pick;
    std::cout << ">> 1. Call Landlord\n"
              << ">> 2. Dont call";
    std::cin >> pick;
    while((pick != 1) && (pick != 2)) {
        std::cout << "Please choose another option:";
        std::cin >> pick;
    }
}

/**
 * Funcion that rob Landlord
 * 强/不强地主
*/
void pickLandlord::robLandlord() {
    int pick;
    std::cout << ">> 1. Rob Landlord\n"
              << ">> 2. Dont Rob";
    std::cin >> pick;
    while((pick != 1) && (pick != 2)) {
        std::cout << "Please choose another option:";
        std::cin >> pick;
    }
}