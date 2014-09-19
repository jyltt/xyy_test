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
	void addHandCard(int cardid);
protected:
private:
	void updateDescribe(const char* describe);
	void onChoseCardButtonDown(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type);
	void onBtnSure(cocos2d::Ref *ref, cocos2d::ui::TouchEventType type);
	cocos2d::ui::Text *m_Text;
	cocos2d::ui::Widget *m_CardExample;
	cocos2d::ui::Widget *m_ChoseCard;
	cocos2d::ui::ListView *m_CardList;
	cocos2d::ui::Button *m_btnSure;
};
#endif // !CHOSECARDDLG_H_
