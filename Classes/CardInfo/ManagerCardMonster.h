#ifndef MANAGERCARDMONSTER_H_
#define MANAGERCARDMONSTER_H_

#include "ILoadFile.h"
#include "IShuffle.h"
#include "Singleton.h"
#include <map>

class CardMonster;

class CardMonsterManager:
	public IShuffle,
	ILoadFile
{
	Singleton(CardMonsterManager);
public:
	CardMonster *findCard(int monsterid);
protected:
	virtual void setParam(TiXmlNode *value)override;
	std::map<int , Card*> mMonsterList;
};
#endif