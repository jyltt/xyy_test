#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"
#include "GameScene.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

class GameScene :
	public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init() override;
	CREATE_FUNC(GameScene);
	
	void updatePetList(int id);
	void updatePlayerData(int id);
	void updateCardList();
	void updateDescribe(const char* describe);

	void onChoseCardButtonDown(cocos2d::Ref *item, cocos2d::ui::TouchEventType type);
private:
	cocos2d::ui::Widget *m_PetExample;
	cocos2d::ui::Widget *m_CardExample;
	cocos2d::ui::Widget *m_CardChoose;
	cocos2d::ui::ListView *m_PlayerCardList;
	cocos2d::ui::ListView *m_PlayerPetList[4];
	cocos2d::ui::Text *m_PlayerName[4];
	cocos2d::ui::Text *m_PlayerBlood[4];
	cocos2d::ui::Text *m_PlayerAttack[4];
	cocos2d::ui::Text *m_PlayerHit[4];
	cocos2d::ui::Text *m_PlayerEquip[4];
	cocos2d::ui::Text *m_PlayerArmor[4];
	cocos2d::ui::Text *m_PlayerCardNum[4];
	cocos2d::ui::Text *m_Describe;

};
#endif