#include "ChoseCardDlg.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/Card.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

bool ChoseCardDlg::init()
{
	if (!Layer::init())
		return false;
	auto layer = GUIReader::getInstance()->widgetFromJsonFile("ChoseCard.ExportJson");
	addChild(layer);
	m_CardExample = layer->getChildByName("card_example");
	auto dlg = layer->getChildByName("chosecard");
	m_CardList = (ListView*)dlg->getChildByName("cardlist");
	m_Text = (Text*)dlg->getChildByName("text");
	m_btnSure = (Button*)dlg->getChildByName("btnsure");
	m_btnSure->setEnabled(false);
	m_btnSure->addTouchEventListener(this, toucheventselector(ChoseCardDlg::onBtnSure));
	return true;
}

void ChoseCardDlg::addHandCard(int cardid)
{
	auto card = HandCardManager::getSingleton().findCard(cardid);
	auto carditem = m_CardExample->clone();
	auto pic = (ImageView*)carditem->getChildByName("cardpic");
	pic->loadTexture(card->getPicturePath());
	carditem->setUserData(card);
	carditem->setTouchEnabled(true);
	carditem->addTouchEventListener(this, toucheventselector(ChoseCardDlg::onChoseCardButtonDown));
	carditem->setVisible(true);
	m_CardList->pushBackCustomItem(carditem);
}

void ChoseCardDlg::onChoseCardButtonDown(Ref *ref, TouchEventType type)
{
	m_ChoseCard = (Widget*)ref;
	m_btnSure->setEnabled(true);
	updateDescribe(((CardHand*)m_ChoseCard->getUserData())->getName());
}

void ChoseCardDlg::updateDescribe(const char* describe)
{
	m_Text->setText(describe);
}

void ChoseCardDlg::onBtnSure(Ref *ref, TouchEventType type)
{
	this->removeFromParent();
}