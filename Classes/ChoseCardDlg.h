#ifndef CHOSECARDDLG_H_
#define CHOSECARDDLG_H_

#include "cocos2d.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

class ChoseCardDlg:
	public cocos2d::Layer
{
public:
	CREATE_FUNC(ChoseCardDlg);
	virtual bool init()override;
	void addCard(int cardid1,int cardid2,int cardid3,int cardid4);
protected:
	void addCard(int cardid);
private:
	void updateDescribe(const char* describe);
	void onChoseCardButtonDown(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type);
	void onBtnSure(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type);
	cocos2d::ui::Text *m_Text;
	cocos2d::ui::Widget *m_CardExample;
	cocos2d::ui::Widget *m_ChoseCard;
	cocos2d::ui::ListView *m_CardList;
};
#endif // !CHOSECARDDLG_H_
