#include "RoleInfoDlg.h"
#include "CardDlg.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/head.h"

RoleInfoDlg::RoleInfoDlg()
{

}

void RoleInfoDlg::setRole(int cardid)
{
	m_CardInfo = CardNpcManager::getSingleton().findCard(cardid);
	updateRole();
}

void RoleInfoDlg::setRole(CardNpc *card)
{
	m_CardInfo = card;
	updateRole();
}

void RoleInfoDlg::updateRole()
{
	m_NPC = CardDlg::create((Card*)m_CardInfo, CARDBKPATH);
	addChild(m_NPC);
	// TODO: 更新人物信息
}