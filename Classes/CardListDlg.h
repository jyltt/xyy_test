#ifndef CARDLISTDLG_H_
#define CARDLISTDLG_H_

#include "cocos2d.h"
#include "CC_Singleton.h"
#include "CardInfo/head.h"

class Card;
class CardDlg;

class CardListDlg:
	public cocos2d::Layer
{
public:
	enum class Model
	{
		single,			//单选一个
		multiple,		//多选
		sort,			//排序
		sort_giveup,	//排序，有放弃部分
	};
	
	//创建后回自动隐，请在添加完卡牌后，再调用显示函数，避免出现不必要的卡顿效果
	static CardListDlg *create(Model model);
	CardListDlg();
	virtual bool init()override;

	// TODO: 添加按下响应函数

	////////////

	//设置列表类型，默认为单选
	CC_SYNTHESIZE(Model, m_eModel, Model);

	//设置列表上方高度
	CC_SYNTHESIZE(float, m_nTopDist, TopDist);

	//设置列表下方高度
	CC_SYNTHESIZE(float, m_nBottonDist, BottonDist);

	//设置卡牌之间距离
	CC_SYNTHESIZE(float, m_nCardDist, CardDist);

	//向列表框中添加卡牌
	//param ： cardID 卡牌id
	void addCard(int cardID);
	void addCard(Card *card);

	//获得选择单个卡牌id，仅适用single模式，其他模式则返回最后一个点选的卡牌
	//return ： 卡牌id,若没有选择返回-1
	int  getSelectCard(){ return m_nSelectCardID; }

	//获得选择卡牌列表id
	//return ： 若为multiple，返回选择的列表
	//			若为sort，返回排序后的列表
	//			若为sort_giveup 返回选择部分的列表
	std::vector<int> &getChoseCardList(){ return m_vChoseCardList; }

	//获得放弃部分的卡牌id， 仅适用于sort_giveup模式，其他模式返回空列表。
	//return ： 卡牌id列表
	std::vector<int> &getGiveupCardList(){ return m_vGiveupCardList; }

protected:
	//更新卡牌序列
	void updateCardList();

protected:
	std::vector<CardDlg*> m_vCardList;		//卡牌列表
	std::vector<int> m_vChoseCardList;		//选择卡牌列表
	std::vector<int> m_vGiveupCardList;		//放弃卡牌列表
	int   m_nSelectCardID;					//选择的卡牌id
};
#endif