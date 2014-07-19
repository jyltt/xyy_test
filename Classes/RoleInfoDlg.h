#ifndef ROLEINFODLG_H_
#define ROLEINFODLG_H_

#include "cocos2d.h"
#include "CardInfo/Card.h"

class CardDlg;

class RoleInfoDlg
	:public cocos2d::Layer
{
	CREATE_FUNC(RoleInfoDlg);
public:
	RoleInfoDlg();
	void setRole(int cardid);
	void setRole(CardNpc *card);
	const CardNpc *getRole()const { return m_CardInfo; }
	const int getRoleID()const { return m_CardInfo->getID(); }
protected:
	void updateRole();
	CardDlg *m_NPC;
	CardNpc* m_CardInfo;
private:
};
#endif