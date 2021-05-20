#include <iostream>
#include "userInfo.hpp"          //User_Information
#include "callLandholder.hpp"     //Call_Landholder
#include "gameProgress.hpp"       //Game_Progress

//https://zhuanlan.zhihu.com/p/80835672

int main(int argc, char *argv[]) {

    int user;
    std::cout << ">> 1. Are you green hand.\n"
              << ">> 2. I have account.\n"
              << ">> Your choose is:";
    std::cin >> user;
    int a = 0;
    while(a == 0){
        if(user == 1) {
            userInfo* ptr_user = new userInfo();
            ptr_user->ShowInfo();
            a = 1;
        }else if(user == 2) {
            std::string name;
            std::cout << "What is your username:";
            std::cin >> name;
            userInfo* ptr_user = new userInfo(name);
            ptr_user->ShowInfo();
            a = 1;
        }else{
            std::cout << ">> Your option is invalid. Choose an option again:\n";
            std::cin >> user;
        }
    }


    std::cout << "\n>> Start Game\n";

    //userInfo* ptr_landOwner = new userInfo("User 1");

    //ptr_landOwner1->ShowCards();
    //ptr_landOwner1->TouchCard(20);

    return 0;
}