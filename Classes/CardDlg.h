#ifndef CARDDLG_H_
#define CARDDLG_H_

#include "cocos2d.h"
#include "CardInfo\head.h"

class Card;
class CardDlg :
	public cocos2d::Node
{
public:
	CardDlg();
	~CardDlg();

	//*********
	//Param : card 卡牌信息
	//		: picBackPath  卡牌背面图片地址
	static CardDlg* create(Card *card, std::string &picBackPath);
	virtual bool init() override;
	void exInit(Card *card, std::string &picBackPath);
	
	//*********
	//是否显示，false为背面，true为正面。
	void setShow(bool show);

	//获得卡牌id
	SET_GET(int, nCardID);

	//获得卡牌描述信息
	SET_GET(std::string, strDescribe);

	//获得卡牌名字
	SET_GET(std::string, strName);

private:
	bool m_bShow;
	cocos2d::Sprite *m_spCard;    //卡牌精灵
	cocos2d::Sprite *m_spCardBk;  //卡牌背面精灵
};
#endif