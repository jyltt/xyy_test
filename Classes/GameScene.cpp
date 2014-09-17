#include "GameScene.h"
#include "ChoseCardDlg.h"
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
	if (!Layer::init())
		return false;
	auto layer = GUIReader::getInstance()->widgetFromJsonFile("gameScene.ExportJson");
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
		m_PlayerCardNum[0] = (Text*)playerlayer->getChildByName("cardnum");
		m_PlayerCardList = (ListView*)playerlayer->getChildByName("cardview");
	}

	auto player1layer = (Widget*)layer->getChildByName("player1");
	if (player1layer)
	{
		m_PlayerName[1] = (Text*)m_PlayerName[0]->clone();
		m_PlayerName[1]->setPosition(getChildPosition(player1layer,"npcname"));
		m_PlayerBlood[1] = (Text *)m_PlayerBlood[0]->clone();
		m_PlayerBlood[1]->setPosition(getChildPosition(player1layer, "blood"));
		m_PlayerAttack[1] = (Text *)m_PlayerAttack[0]->clone();
		m_PlayerAttack[1]->setPosition(getChildPosition(player1layer, "attack"));
		m_PlayerHit[1] = (Text *)m_PlayerHit[0]->clone();
		m_PlayerHit[1]->setPosition(getChildPosition(player1layer, "hit"));
		m_PlayerEquip[1] = (Text *)m_PlayerEquip[0]->clone();
		m_PlayerEquip[1]->setPosition(getChildPosition(player1layer, "equip"));
		m_PlayerArmor[1] = (Text *)m_PlayerArmor[0]->clone();
		m_PlayerArmor[1]->setPosition(getChildPosition(player1layer, "armor"));
		m_PlayerPetList[1] = (ListView*)m_PlayerPetList[0]->clone();
		m_PlayerPetList[1]->setPosition(getChildPosition(player1layer, "petview"));
		m_PlayerPic[1] = (ImageView*)m_PlayerPic[0]->clone();
		m_PlayerPic[1]->setPosition(getChildPosition(player1layer, "npccard"));
		m_PlayerCardNum[1] = (Text*)m_PlayerCardNum[0]->clone();
		m_PlayerCardNum[1]->setPosition(getChildPosition(player1layer, "cardnum"));
		player1layer->addChild(m_PlayerName[1]);
		player1layer->addChild(m_PlayerBlood[1]);
		player1layer->addChild(m_PlayerAttack[1]);
		player1layer->addChild(m_PlayerHit[1]);
		player1layer->addChild(m_PlayerEquip[1]);
		player1layer->addChild(m_PlayerArmor[1]);
		player1layer->addChild(m_PlayerPetList[1]);
		player1layer->addChild(m_PlayerPic[1]);
		player1layer->addChild(m_PlayerCardNum[1]);
	}

	auto player2layer = (Widget*)layer->getChildByName("player2");
	if (player2layer)
	{
		m_PlayerName[2] = (Text*)m_PlayerName[0]->clone();
		m_PlayerName[2]->setPosition(getChildPosition(player2layer,"npcname"));
		m_PlayerBlood[2] = (Text *)m_PlayerBlood[0]->clone();
		m_PlayerBlood[2]->setPosition(getChildPosition(player2layer, "blood"));
		m_PlayerAttack[2] = (Text *)m_PlayerAttack[0]->clone();
		m_PlayerAttack[2]->setPosition(getChildPosition(player2layer, "attack"));
		m_PlayerHit[2] = (Text *)m_PlayerHit[0]->clone();
		m_PlayerHit[2]->setPosition(getChildPosition(player2layer, "hit"));
		m_PlayerEquip[2] = (Text *)m_PlayerEquip[0]->clone();
		m_PlayerEquip[2]->setPosition(getChildPosition(player2layer, "equip"));
		m_PlayerArmor[2] = (Text *)m_PlayerArmor[0]->clone();
		m_PlayerArmor[2]->setPosition(getChildPosition(player2layer, "armor"));
		m_PlayerPetList[2] = (ListView*)m_PlayerPetList[0]->clone();
		m_PlayerPetList[2]->setPosition(getChildPosition(player2layer, "petview"));
		m_PlayerPic[2] = (ImageView*)m_PlayerPic[0]->clone();
		m_PlayerPic[2]->setPosition(getChildPosition(player2layer, "npccard"));
		m_PlayerCardNum[2] = (Text*)m_PlayerCardNum[0]->clone();
		m_PlayerCardNum[2]->setPosition(getChildPosition(player2layer, "cardnum"));
		player2layer->addChild(m_PlayerName[2]);
		player2layer->addChild(m_PlayerBlood[2]);
		player2layer->addChild(m_PlayerAttack[2]);
		player2layer->addChild(m_PlayerHit[2]);
		player2layer->addChild(m_PlayerEquip[2]);
		player2layer->addChild(m_PlayerArmor[2]);
		player2layer->addChild(m_PlayerPetList[2]);
		player2layer->addChild(m_PlayerPic[2]);
		player2layer->addChild(m_PlayerCardNum[2]);
	}


	auto player3layer = (Widget*)layer->getChildByName("player3");
	if (player3layer)
	{
		m_PlayerName[3] = (Text*)m_PlayerName[0]->clone();
		m_PlayerName[3]->setPosition(getChildPosition(player3layer,"npcname"));
		m_PlayerBlood[3] = (Text *)m_PlayerBlood[0]->clone();
		m_PlayerBlood[3]->setPosition(getChildPosition(player3layer, "blood"));
		m_PlayerAttack[3] = (Text *)m_PlayerAttack[0]->clone();
		m_PlayerAttack[3]->setPosition(getChildPosition(player3layer, "attack"));
		m_PlayerHit[3] = (Text *)m_PlayerHit[0]->clone();
		m_PlayerHit[3]->setPosition(getChildPosition(player3layer, "hit"));
		m_PlayerEquip[3] = (Text *)m_PlayerEquip[0]->clone();
		m_PlayerEquip[3]->setPosition(getChildPosition(player3layer, "equip"));
		m_PlayerArmor[3] = (Text *)m_PlayerArmor[0]->clone();
		m_PlayerArmor[3]->setPosition(getChildPosition(player3layer, "armor"));
		m_PlayerPetList[3] = (ListView*)m_PlayerPetList[0]->clone();
		m_PlayerPetList[3]->setPosition(getChildPosition(player3layer, "petview"));
		m_PlayerPic[3] = (ImageView*)m_PlayerPic[0]->clone();
		m_PlayerPic[3]->setPosition(getChildPosition(player3layer, "npccard"));
		m_PlayerCardNum[3] = (Text*)m_PlayerCardNum[0]->clone();
		m_PlayerCardNum[3]->setPosition(getChildPosition(player3layer, "cardnum"));
		player3layer->addChild(m_PlayerName[3]);
		player3layer->addChild(m_PlayerBlood[3]);
		player3layer->addChild(m_PlayerAttack[3]);
		player3layer->addChild(m_PlayerHit[3]);
		player3layer->addChild(m_PlayerEquip[3]);
		player3layer->addChild(m_PlayerArmor[3]);
		player3layer->addChild(m_PlayerPetList[3]);
		player3layer->addChild(m_PlayerPic[3]);
		player3layer->addChild(m_PlayerCardNum[3]);	
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

	m_BtnNextCard = (Button*)layer->getChildByName("nextstate");
	m_BtnNextCard->addTouchEventListener(this, toucheventselector(GameScene::onBtnNextState));
	m_BtnPushCard = (Button*)layer->getChildByName("pushcard");
	m_BtnPushCard->addTouchEventListener(this, toucheventselector(GameScene::onBtnPushCard));
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
	sprintf(text, "cardnum:%d", player->getCardNum());
	m_PlayerCardNum[id]->setText(text);
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
		carditem->setVisible(true);
		m_PlayerCardList->pushBackCustomItem(carditem);
	}
}

void GameScene::onBtnNextState(Ref* ref, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		auto layer = ChoseCardDlg::create();
		layer->addCard(HandCardManager::getSingleton().getOne(),
			HandCardManager::getSingleton().getOne(),
			HandCardManager::getSingleton().getOne(),
			HandCardManager::getSingleton().getOne());
		addChild(layer);
	}
}

void GameScene::onBtnPushCard(Ref* ref, TouchEventType type)
{

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
