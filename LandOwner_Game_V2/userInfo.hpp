#ifndef USERINFOR_HPP
#define USERINFOR_HPP

#include <iostream>
#include <string>

class userInfo
{
private:
    /* data */
    std::string m_NickName;
    int m_Gold;
    long m_Exp;

public:
    userInfo(/* args */);
    userInfo(std::string);
    ~userInfo();
    std::string GetNickName() { return m_NickName; }
    void SetNickName(std::string val) { m_NickName = val; }
    int GetGold() { return m_Gold; }
    void SetGold(int val) { m_Gold = val; }
    long GetExp() { return m_Exp; }
    void SetExp(long val) { m_Exp = val; }

    void ShowInfo();
};




#endif //USERINFOR_HPP