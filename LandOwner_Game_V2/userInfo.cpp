#include <fstream>          //for save data
#include "userInfo.hpp"

userInfo::userInfo(){
    std::string name;
    std::cout << ">> Create username:";
    std::cin >> name;
    int gold = 1000;
    int level = 1;
    std::ofstream file;
    file.open("account.txt", std::ios::app);
        if(file.is_open())
        {
            //如果已经存在。。 则出现问题
            //或者给每个用户匹配ID
            file << "Username:" << name << std::endl;
            file << "Gold:" << gold << std::endl;
            file << "Level:" << level << std::endl << std::endl;
        }
    file.close();
    SetNickName(name);
    SetExp(level);
    SetGold(gold);
}
userInfo::~userInfo(){}

userInfo::userInfo(std::string nickName): m_NickName(nickName)
{
    SetExp(0);
    SetGold(1000);
    // This part will be change
}


void userInfo::ShowInfo()
{
    std::cout << ">> Username: " << GetNickName() << std::endl;
    std::cout << ">> Gold:" << GetGold() << std::endl;
    std::cout << ">> Level:" << GetExp() << std::endl;
}