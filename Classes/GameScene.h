#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"

class GameScene :
	public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init() override;
	CREATE_FUNC(GameScene);
	
};
#endif