#include "userInfo.hpp"

userInfo::userInfo(){
    std::string name;
    std::cout << ">> Create username:";
    std::cin >> name;
    SetNickName(name);
    SetExp(1);
    SetGold(1000);
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