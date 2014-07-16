#include "GameScene.h"
#include "CardInfo/ManagerCardEvent.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/ManagerSkill.h"

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
	auto cardinfo = new Card();
	cardinfo->setPicturePath("Equip_Card/caihuan.jpg");
	auto cardlist = CardListDlg::create(CardListDlg::Model::single);
	cardlist->addCard(cardinfo);
	addChild(cardlist);

	auto cardinfo2 = new Card();
	cardinfo2->setPicturePath("Equip_Card/caihuan.jpg");
	cardlist->addCard(cardinfo2);

	cardlist->setVisible(true);
	return true;
}