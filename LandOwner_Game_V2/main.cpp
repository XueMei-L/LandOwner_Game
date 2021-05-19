#include <iostream>
#include "LandOwner.h"

int main() {
    LandOwner* ptr_landOwner1 = new LandOwner("专业地主");
    ptr_landOwner1->ShowInfo();
    //ptr_landOwner1->ShowCards();
    ptr_landOwner1->TouchCard(20);

    delete ptr_landOwner1;

    return 0;
}