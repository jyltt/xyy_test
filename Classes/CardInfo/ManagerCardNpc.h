#ifndef MANAGERCARDNPC_H_
#define MANAGERCARDNPC_H_

#include "ILoadFile.h"
#include "IShuffle.h"
#include "Singleton.h"
#include <map>

class CardNpc;

class CardNpcManager:
	public IShuffle,
	ILoadFile
{
	Singleton(CardNpcManager);
public:
	CardNpc *findCard(int npcid);
protected:
	virtual void setParam(TiXmlNode *value)override;
	std::map<int , Card*> mNpcList;
};
#endif