/**
 * @name 斗地主小游戏
 * @author 林柚子
 * @version 1.0
 * @remarks .h 文件
*/
#ifndef LANDOWNER_H
#define LANDOWNER_H
#include <iostream>
#include <vector>

#include <iterator>
#include <algorithm>

#include <cstdlib>
#include <ctime>

LANDOWNER_H
class LandOwner
{
    private:
        std::vector<int> packCards;         //默认的一副牌，从1-54
        std::vector<int> surplusCards;      //摸牌后，剩余的牌
        std::vector<int> currCards;         //当前玩家的手牌数组
        bool isContains(int cardNum);       //剩余牌集合中是不是包含cardNum牌面
        void deleteCard(std::vector<int>&, int);    //删除集合中的牌
        std::string getColor(int);          //获得牌的花色
        std::string getValue(int);          //获得牌面
        void SortCards(std::vector<int>&);  //整理地主牌
    public:
        LandOwner();
        LandOwner(std::string);
        ~LandOwner();


        void TouchCard(int);                  //摸牌
        void ShowInfo();                      //玩家信息
        void InitCards();                     //初始化牌，如清空
        void ShowCards(std::vector<int>&);    //查看初始化牌
};


#endif //LANDOWNER_H