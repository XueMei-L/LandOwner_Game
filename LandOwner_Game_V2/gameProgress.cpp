#include "LandOwner.h"          //如果在.h里定义了librerias那么这里就不用再定义
#include <algorithm>

LandOwner::LandOwner()
{
    SetNickName("默认地主");
    SetExp(0);
    SetGold(1000);
    InitCards();
    //ShowCards(packCards);
}


void LandOwner::InitCards()
{
    //生成默认的一幅牌
    for(int i = 0; i < 54; i++) {
        packCards.push_back(i + 1);                 //默认牌数为1 - 54张
        surplusCards.push_back(packCards.at(i));    //剩下牌数是
    }
    currCards.clear();                              //当前牌数是0张
}


void LandOwner::ShowCards(std::vector<int>& cards)
{
    SortCards(cards);
    for(auto card:cards)
    {
        std::cout << getColor(card) << getValue(card) << ",";
    }
    std::cout << std::endl;
}

/* 摸牌 */
void LandOwner::TouchCard(int cardCount)
{
    //随机抽取一张牌(在剩余的牌里抽出) 添加到currCards， 然后再从suplusCards里删除
    srand(time(NULL));  //时间种子
    for(int i = 0; i < cardCount; i++)
    {
        int randIndex = rand() % 54;        //1-54之间的随机数字
        //判断，随机生成的牌是否在剩余牌集合中
        if(isContains(packCards[randIndex]))
        {
            currCards.push_back(packCards[randIndex]);      //将摸的牌放入当前手牌
            //剩余的牌中和删除
            deleteCard(surplusCards, packCards[randIndex]);
        }else{
            i--;
        }
    }
    std::cout << "<摸牌> -" << std::endl;
    ShowCards(currCards);
    std::cout << "<剩下的牌> -" << std::endl;
    ShowCards(surplusCards);
}

bool LandOwner::isContains(int cardNum)
{
    //简便++
    std::vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    return iter != surplusCards.end();
}

void LandOwner::deleteCard(std::vector<int>& cardVec, int card)
{
    //使用算法删除
    auto iter = find(cardVec.begin(), cardVec.end(), card);
    if(iter != cardVec.end()){
        cardVec.erase(iter);
    }

}

std::string LandOwner::getColor(int card)
{
    if(card == 53) return "";
    if(card == 54) return "";
    std::string colors[] = { "黑桃", "红桃", "方块", "梅花" };
    return colors[ (card-1) / 13];
}

std::string LandOwner::getValue(int card)
{
    if(card == 53) return "大王";
    if(card == 54) return "小王";
    std::string values[] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "J", "Q", "K"
    };
    return values[(card-1) % 13];
}

void LandOwner::SortCards(std::vector<int>& cards)
{
    std::sort(cards.begin(), cards.end());
}

LandOwner::~LandOwner(){}