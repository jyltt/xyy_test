#include "GameScene.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CardInfo/ManagerCardEvent.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/ManagerSkill.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

#include "CardInfo/Card.h"

cocos2d::Scene *GameScene::createScene()
{
	auto layer = GameScene::create();
	auto scene = cocos2d::Scene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	auto layer = GUIReader::getInstance()->widgetFromJsonFile("gameScene.json");
	addChild(layer);
	
	auto playerlayer = (Widget*)layer->getChildByName("player");
	if (playerlayer)
	{
		m_PlayerName[0] = (Text *)playerlayer->getChildByName("npcname");
		m_PlayerBlood[0] = (Text *)playerlayer->getChildByName("blood");
		m_PlayerAttack[0] = (Text *)playerlayer->getChildByName("attack");
		m_PlayerHit[0] = (Text *)playerlayer->getChildByName("hit");
		m_PlayerEquip[0] = (Text *)playerlayer->getChildByName("equip");
		m_PlayerPetList[0] = (ListView*)playerlayer->getChildByName("petview");
		m_PlayerCardList = (ListView*)playerlayer->getChildByName("cardview");
	}

	auto player1layer = (Widget*)layer->getChildByName("player1");
	if (player1layer)
	{
		m_PlayerName[1] = (Text *)player1layer->getChildByName("npcname");
		m_PlayerBlood[1] = (Text *)player1layer->getChildByName("blood");
		m_PlayerAttack[1] = (Text *)player1layer->getChildByName("attack");
		m_PlayerHit[1] = (Text *)player1layer->getChildByName("hit");
		m_PlayerEquip[1] = (Text *)player1layer->getChildByName("equip");
		m_PlayerPetList[1] = (ListView*)player1layer->getChildByName("petview");
	}

	auto player2layer = (Widget*)layer->getChildByName("player2");
	if (player2layer)
	{
		m_PlayerName[2] = (Text *)player2layer->getChildByName("npcname");
		m_PlayerBlood[2] = (Text *)player2layer->getChildByName("blood");
		m_PlayerAttack[2] = (Text *)player2layer->getChildByName("attack");
		m_PlayerHit[2] = (Text *)player2layer->getChildByName("hit");
		m_PlayerEquip[2] = (Text *)player2layer->getChildByName("equip");
		m_PlayerPetList[2] = (ListView*)player2layer->getChildByName("petview");
	}


	auto player3layer = (Widget*)layer->getChildByName("player3");
	if (player3layer)
	{
		m_PlayerName[3] = (Text *)player3layer->getChildByName("npcname");
		m_PlayerBlood[3] = (Text *)player3layer->getChildByName("blood");
		m_PlayerAttack[3] = (Text *)player3layer->getChildByName("attack");
		m_PlayerHit[3] = (Text *)player3layer->getChildByName("hit");
		m_PlayerEquip[3] = (Text *)player3layer->getChildByName("equip");
		m_PlayerPetList[3] = (ListView*)player3layer->getChildByName("petview");
	}
	
	m_PetExample = (Widget*)layer->getChildByName("pet_example");
	m_CardExample = (Widget*)layer->getChildByName("card_example");

	m_Describe = (Text*)layer->getChildByName("text");

	for (int i = 0; i < 4;i++)
	{
		updatePetList(i);
	}
	return true;
}

void GameScene::updatePetList(int id)
{
	if (m_PlayerPetList[id]->getItems().size() == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			auto pet = m_PetExample->clone();
			auto pic = (Image*)pet->getChildByName("attrpic");
			pet->setVisible(true);
			m_PlayerPetList[id]->pushBackCustomItem(pet);
		}
	}
	else
	{
		for (auto iter:m_PlayerPetList[id]->getItems())
		{
			auto pic = (ImageView*)iter->getChildByName("attrpic");
			//pic->loadTexture(PETPIC);
			auto text = (Text*)iter->getChildByName("peiname");
			//text->setText(PETNAME);
			//iter->setUserData(PETDATA);
		}
	}
}

void GameScene::updatePlayerData(int id)
{
	//获取对应玩家对象
	switch (id)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		return;
	}
	//m_PlayerName[id]->setText();
	//m_PlayerBlood[id]->setText();
	//m_PlayerAttack[id]->setText();
	//m_PlayerHit[id]->setText();
	//m_PlayerEquip[id]->setText();
	//m_PlayerArmor[id]->setText();
	//m_PlayerCardNum[id]->setText();
}

void GameScene::updateCardList()
{
	m_PlayerCardList->removeAllItems();
	//for (auto &card : playercard)
	//{
		auto carditem = m_CardExample->clone();
		auto pic = (ImageView*)carditem->getChildByName("cardpic");
		//pic->loadTexture(CARDPIC);
		//pic->setUserData(&card);
		carditem->setTouchEnabled(true);
		carditem->addTouchEventListener(this, toucheventselector(GameScene::onChoseCardButtonDown));
		m_PlayerCardList->pushBackCustomItem(carditem);
	//}
}

void GameScene::onChoseCardButtonDown(Ref *item, TouchEventType type)
{
	m_CardChoose = (Widget*)item;
	//updateDescribe();
}

void GameScene::updateDescribe(const char* describe)
{
	m_Describe->setText(describe);
}