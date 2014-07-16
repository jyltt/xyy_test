#ifndef MANAGERCARDHAND_H_
#define MANAGERCARDHAND_H_

#include "ILoadFile.h"
#include "IShuffle.h"
#include "Singleton.h"
#include <map>

class CardHand;

class HandCardManager:
	public IShuffle,
	ILoadFile
{
	Singleton(HandCardManager);
public:
	CardHand *findCard(int cardId);
protected:
	virtual void setParam(TiXmlNode *value)override;
	std::map<int,int> mHandNum;		//ÊÖÅÆÊý first int is handcard id,second int is handcard's number.
	std::map<int,CardHand*> mHandCard;//ÅÆ¶ÑÊ£ÓàÊý
};

#endif