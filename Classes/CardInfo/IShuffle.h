#pragma once
#include "vector"
#include "map"
#include <algorithm>

class Card;

class IShuffle
{
public:
	IShuffle();
/*
* @remarks
	设置牌的随机序列
* @param
	传入牌的列表
	error!!!
*/
void setList(const std::map<int ,Card*> &list)
{
	for(auto i = list.begin(); i != list.end();i++)
	{
		this->mShowCardList.push_back(i->first);
	}
	std::random_shuffle(mShowCardList.begin(), mShowCardList.end(),[](int i){return rand()%i;});
}
/*
* @remarks
	设置牌的随机序列
* @param
	传入牌的列表
*/
	void setList(std::map<int ,int > &list);
/*
* @return 
	返回非零值，若为零，则已取完所有数
*/
	int getOne();
/*
* @return 
	返回剩余牌堆卡牌数
*/
	int getSurplus();
protected:
	int heat;
	std::vector<int> mShowCardList;
};