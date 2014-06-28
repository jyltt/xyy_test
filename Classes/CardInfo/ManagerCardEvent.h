#ifndef MANAGERCARDEVENT_H_
#define MANAGERCARDEVENT_H_

#include "ILoadFile.h"
#include "IShuffle.h"
#include "Singleton.h"

class CardEvent;

class CardEventManager:
	public IShuffle,
	ILoadFile
{
	Singleton(CardEventManager);
public:
	CardEvent *findEvent(int eventid);
protected:
	virtual void setParam(TiXmlNode *value)override;
	std::map<int,int> mEventNum;		//ÊÖÅÆÊý first int is handcard id,second int is handcard's number.
	std::map<int,CardEvent*> mEventCard;//ÅÆ¶ÑÊ£ÓàÊý
};
#endif