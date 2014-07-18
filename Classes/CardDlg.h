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
	static CardDlg* create(Card *card,const std::string &picBackPath);
	virtual bool init() override;
	void exInit(Card *card,const std::string &picBackPath);
	
	//*********
	//是否显示，false为背面，true为正面。
	void setShow(bool show);

	//是否被选择，true为选择
	void setSelect(bool select);

	//获得卡牌id
	SET_GET(int, nCardID);

	//获得卡牌描述信息
	SET_GET(std::string, strDescribe);

	//获得卡牌名字
	SET_GET(std::string, strName);

	//获得卡牌的高和宽
	float Wide(){ return m_spCard->getBoundingBox().size.width; }
	float Hight(){ return m_spCard->getBoundingBox().size.height; }

	//判断是否被按住
	bool isTouch(const cocos2d::Point &point);
protected:
	const int m_nMoveHeight;
	bool m_bShow;
	bool m_bSelect;
	cocos2d::Sprite *m_spCard;    //卡牌精灵
	cocos2d::Sprite *m_spCardBk;  //卡牌背面精灵
};
#endif