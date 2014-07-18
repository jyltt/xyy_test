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
	setTouchEnabled(true);
	setTouchMode(cocos2d::Touch::DispatchMode::ONE_BY_ONE);
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

bool CardListDlg::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto point = touch->getStartLocation();
	bool flg = false;
	for (auto iter:m_vCardList)
	{
		if (iter->isTouch(point))
		{
			flg = true;
			switch (m_eModel)
			{
			case CardListDlg::Model::single:
				m_nSelectCardID = (m_nSelectCardID != iter->getnCardID()) ? iter->getnCardID() : -1;
			case CardListDlg::Model::multiple:
				/*for (auto i = m_vChoseCardList.begin(); i < m_vChoseCardList.end();i++)
				{
					if ((*i) == iter->getnCardID())
					{
						m_vChoseCardList.erase(i);
						break;
					}
				}
				m_vChoseCardList.push_back(iter->getnCardID());*/
				break;
			case CardListDlg::Model::sort:
				break;
			case CardListDlg::Model::sort_giveup:
				break;
			default:
				break;
			}
		}
	}

	//更新状态
	for (auto iter:m_vCardList)
	{
		switch (m_eModel)
		{
		case CardListDlg::Model::single:
				iter->setSelect(iter->getnCardID() == m_nSelectCardID);
			break;
		case CardListDlg::Model::multiple:
			break;
		case CardListDlg::Model::sort:
			break;
		case CardListDlg::Model::sort_giveup:
			break;
		default:
			break;
		}
	}
	return flg;
}

void CardListDlg::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

}