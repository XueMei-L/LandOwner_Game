#include "LandOwner.h"          //如果在.h里定义了librerias那么这里就不用再定义
#include <algorithm>

LandOwner::LandOwner()
{
    SetNickName("默认地主");
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    std::cout << "LandOwner()" << std::endl;
    InitCards();
    ShowCards(packCards);
}

LandOwner::LandOwner(std::string nickName): m_NickName(nickName)
{
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    InitCards();
}

LandOwner::LandOwner(std::string nickName, std::string sex, int gold, long exp):m_NickName(nickName), m_Sex(sex), m_Gold(gold), m_Exp(exp)
{
    std::cout << "LandOwner(std::string nickName, std::string sex, int gold, long exp)" << std::endl;
    InitCards();
}

void LandOwner::ShowInfo()
{
    std::cout << "昵称" << GetNickName() << std::endl;
    std::cout << "性别" << GetSex() << std::endl;
    std::cout << "金币" << GetGold() << std::endl;
    std::cout << "经验" << GetExp() << std::endl;
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
    //c
    /*
    for(int i = 0; i < cards.size(); i++){
        std::cout << cards[i] << ",";
    }
    std::cout << std::endl;*/

    //更专业的写法
    /*
    for(std::vector<int>::const_iterator iter = cards.begin(); iter!=cards.end(); iter++){
        std::cout << *iter << "," ;
    }
    std::cout << std::endl;
    */

    //更简便的方式 - c++ 11
    /*
    for(auto iter = cards.begin(); iter!=cards.end(); iter++){
        std::cout << *iter << "," ;
    }
    std::cout << std::endl;
    */

    //for区间遍历 - c++ 11
    SortCards(cards);
    for(auto card:cards)
    {
        std::cout << getColor(card) << getValue(card) << ",";
    }
    std::cout << std::endl;
    

    //使用算法的方式，将容器的内容复制到cout绑定的迭代器中
    //#include <iterator>
    //#include <algorithm>
    //copy(cards.cbegin(), cards.cend(), std::ostream_iterator<int>(std::cout, ","));
    //std::cout << std::endl;
    //这里是指，复制cards的数从头到尾，放到函数ostream里面去，复制给cout，用“，”分开
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
    //普通方法
    /*
    for(int i = 0; i < surplusCards.size(); i++)
    {
        if(surplusCards[i] == cardIndex[i])
        {
            return true;
        }
    }
    return false;
    */

    //使用算法查找
    /*
    std::vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    if(iter == surplusCards.end()){
        return false;
    }
    return true;
    */

    //简便++
    std::vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    return iter != surplusCards.end();
}

void LandOwner::deleteCard(std::vector<int>& cardVec, int card)
{
    //普通青年做法
    /*
    for(auto iter = cardVec.begin(); iter!= cardVec.end();)
    {
        if(*iter == card)               //如果找到，那么删除元素
        {
            iter = cardVec.erase(card);     //这里的返回值指向已删除元素的下一个元素
        }else{
            ++iter;
        }
    }*/

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