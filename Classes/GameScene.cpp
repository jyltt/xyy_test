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

#include "CardListDlg.h"

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
	layer->setScale(0.5);
	addChild(layer);
	/*auto cardinfo = new Card(Card::CARDTYPE::Hand);
	cardinfo->setPicturePath("Equip_Card/caihuan.png");
	cardinfo->setID(2);
	auto cardlist = CardListDlg::create(CardListDlg::Model::single);
	cardlist->addCard(cardinfo);
	addChild(cardlist);

	auto cardinfo2 = new Card(Card::CARDTYPE::Hand);
	cardinfo2->setPicturePath("Equip_Card/caihuan.png");
	cardinfo2->setID(3);
	cardlist->addCard(cardinfo2);

	cardlist->setVisible(true);*/
	return true;
}