#include "GameScene.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

#include "PlayerList.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"

GameScene::GameScene()
	:m_playerID(1)
{

}

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
		m_PlayerArmor[0] = (Text *)playerlayer->getChildByName("armor");
		m_PlayerPetList[0] = (ListView*)playerlayer->getChildByName("petview");
		m_PlayerPic[0] = (ImageView*)playerlayer->getChildByName("npccard");
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
		m_PlayerArmor[1] = (Text *)player1layer->getChildByName("armor");
		m_PlayerPetList[1] = (ListView*)player1layer->getChildByName("petview");
		m_PlayerPic[1] = (ImageView*)player1layer->getChildByName("npccard");
	}

	auto player2layer = (Widget*)layer->getChildByName("player2");
	if (player2layer)
	{
		m_PlayerName[2] = (Text *)player2layer->getChildByName("npcname");
		m_PlayerBlood[2] = (Text *)player2layer->getChildByName("blood");
		m_PlayerAttack[2] = (Text *)player2layer->getChildByName("attack");
		m_PlayerHit[2] = (Text *)player2layer->getChildByName("hit");
		m_PlayerEquip[2] = (Text *)player2layer->getChildByName("equip");
		m_PlayerArmor[2] = (Text *)player2layer->getChildByName("armor");
		m_PlayerPetList[2] = (ListView*)player2layer->getChildByName("petview");
		m_PlayerPic[2] = (ImageView*)player2layer->getChildByName("npccard");
	}


	auto player3layer = (Widget*)layer->getChildByName("player3");
	if (player3layer)
	{
		m_PlayerName[3] = (Text *)player3layer->getChildByName("npcname");
		m_PlayerBlood[3] = (Text *)player3layer->getChildByName("blood");
		m_PlayerAttack[3] = (Text *)player3layer->getChildByName("attack");
		m_PlayerHit[3] = (Text *)player3layer->getChildByName("hit");
		m_PlayerEquip[3] = (Text *)player3layer->getChildByName("equip");
		m_PlayerArmor[3] = (Text *)player3layer->getChildByName("armor");
		m_PlayerPetList[3] = (ListView*)player3layer->getChildByName("petview");
		m_PlayerPic[3] = (ImageView*)player3layer->getChildByName("npccard");
	}
	
	m_PetExample = (Widget*)layer->getChildByName("pet_example");
	m_CardExample = (Widget*)layer->getChildByName("card_example");

	m_Describe = (Text*)layer->getChildByName("text");

	for (int i = 0; i < 4;i++)
	{
		updatePetList(i);
		updatePlayerData(i);
	}
	updateCardList();
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
		int i = 0;
		for (auto iter:m_PlayerPetList[id]->getItems())
		{
			auto pic = (ImageView*)iter->getChildByName("attrpic");
			auto player = PlayerList::getSingleton().getPlayerfromSign(id);
			auto monster = CardMonsterManager::getSingleton().findCard(player->getPetCardID()[i]);
			pic->loadTexture(monster->getPicturePath());
			auto text = (Text*)iter->getChildByName("peiname");
			text->setText(monster->getName());
			iter->setUserData(monster);
		}
	}
}

void GameScene::updatePlayerData(int id)
{
	auto player = PlayerList::getSingleton().getPlayerfromSign(id);
	m_PlayerName[id]->setText(player->getNpcCard()->getName());
	m_PlayerPic[id]->loadTexture(player->getNpcCard()->getPicturePath());
	char text[100] = "";
	sprintf(text, "HP    :%d", player->getHP());
	m_PlayerBlood[id]->setText(text);
	sprintf(text, "Attack:%d", player->getAttack());
	m_PlayerAttack[id]->setText(text);
	sprintf(text, "Hit   :%d", player->getHit());
	m_PlayerHit[id]->setText(text);

	switch (player->getEquipCardID().size())
	{
	case 1:
		sprintf(text, "equip:%d", player->getEquipCardID()[0]);
		break;
	case 2:
		sprintf(text, "equip:%d/%d", player->getEquipCardID()[0],player->getEquipCardID()[1]);
		break;
	default:
		sprintf(text, "equip:nullptr");
		break;
	}
	m_PlayerEquip[id]->setText(text);

	switch (player->getArmorCardID().size())
	{
	case 1:
		sprintf(text, "Armor:%d", player->getArmorCardID()[0]);
		break;
	case 2:
		sprintf(text, "Armor:%d/%d", player->getArmorCardID()[0],player->getArmorCardID()[1]);
		break;
	default:
		sprintf(text, "Armor:nullptr");
		break;
	}
	m_PlayerArmor[id]->setText(text);
	//sprintf(text, "%d", player->getCardNum());
	//m_PlayerCardNum[id]->setText(text);
}

void GameScene::updateCardList()
{
	m_PlayerCardList->removeAllItems();
	for (auto cardid : PlayerList::getSingleton().getPlayerFromID(m_playerID)->getHandCardID())
	{
		auto card = HandCardManager::getSingleton().findCard(cardid);
		auto carditem = m_CardExample->clone();
		auto pic = (ImageView*)carditem->getChildByName("cardpic");
		pic->loadTexture(card->getPicturePath());
		carditem->setUserData(card);
		carditem->setTouchEnabled(true);
		carditem->addTouchEventListener(this, toucheventselector(GameScene::onChoseCardButtonDown));
		m_PlayerCardList->pushBackCustomItem(carditem);
	}
}

void GameScene::onChoseCardButtonDown(Ref *item, TouchEventType type)
{
	m_CardChoose = (Widget*)item;
	updateDescribe(((CardHand*)m_CardChoose->getUserData())->getName());
}

void GameScene::updateDescribe(const char* describe)
{
	m_Describe->setText(describe);
}
