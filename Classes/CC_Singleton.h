#ifndef CC_SINGLETON_H_
#define CC_SINGLETON_H_

#include "cocos2d.h"

class LayerSingleton:public cocos2d::Layer
{
public:
	static LayerSingleton &getSingleton()
	{
		if (single == nullptr)
			single = new LayerSingleton();
		cocos2d::Director::getInstance()->getRunningScene()->addChild(single);
		return *single;
	}
	void CloseLayer()
	{
		single->removeFromParent();
		single = nullptr;
	}
	
	~LayerSingleton();
private:
	static LayerSingleton *single ;
	LayerSingleton();
	
	CC_DISALLOW_COPY_AND_ASSIGN(LayerSingleton);
};
#endif