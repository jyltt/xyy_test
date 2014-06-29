#include "GameScene.h"
#include "CardInfo/ManagerCardEvent.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/ManagerSkill.h"

#include "CardDlg.h"

cocos2d::Scene *GameScene::createScene()
{
	auto layer = GameScene::create();
	auto scene = cocos2d::Scene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{

	return true;
}