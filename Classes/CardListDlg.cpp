#include "CardListDlg.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/Card.h"
#include "CardDlg.h"

CardListDlg *CardListDlg::create(Model model)
{
	auto dlg = new CardListDlg();
	if (dlg != nullptr
		&& dlg->init())
	{
		dlg->setModel(model);
		dlg->setVisible(false);
		dlg->autorelease();
		return dlg;
	}
	else
	{
		delete dlg;
		return nullptr;
	}
}

CardListDlg::CardListDlg() :
m_eModel(Model::single),
m_nCardDist(10),
m_nTopDist(0),
m_nBottonDist(0),
m_nSelectCardID(-1)
{

}

bool CardListDlg::init()
{
	// TODO: 添加初始化内容
	return true;
}

void CardListDlg::addCard(int cardID)
{
	Card *card = nullptr;
	do{
		card = dynamic_cast<Card*>(CardMonsterManager::getSingleton().findCard(cardID));
		if (card)
		{
			break;
		}
		card = dynamic_cast<Card*>(CardNpcManager::getSingleton().findCard(cardID));
		if (card)
		{
			break;
		}
		card = dynamic_cast<Card*>(HandCardManager::getSingleton().findCard(cardID));
		if (card)
		{
			break;
		}
		return;
	} while (0);
	addCard(card);
}

void CardListDlg::addCard(Card *card)
{
	// TODO: 添加sprite
	auto sprite = CardDlg::create(card, CARDBKPATH);
	sprite->setUserData(card);
	addChild(sprite);
	m_vCardList.push_back(sprite);
	m_vChoseCardList.push_back(card->getID());
	updateCardList();
}

void CardListDlg::updateCardList()
{
	int cont = m_vCardList.size();
	auto wide = m_vCardList[0]->Wide();
	auto hight = m_vCardList[0]->Hight();

	int num = 0;
	for (auto iter:m_vCardList)
	{
		iter->setPosition((m_nCardDist + wide)*num, 0);
		num++;
	}
}