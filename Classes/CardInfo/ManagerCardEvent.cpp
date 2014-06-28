#include "ManagerCardEvent.h"
#include "Card.h"

CardEventManager::CardEventManager()
{
	LoadFile("data//Event.xml");
	setList(mEventNum);
}

void CardEventManager::setParam(TiXmlNode *value)
{
	TiXmlNode *pParam = value->FirstChild();
	CardEvent *card = new CardEvent();
	card->setName(value->Value());
	while(pParam)
	{
		if(memcmp(pParam->Value(),"Sign",sizeof("Sign")) == 0)
		{
			card->setID(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"PictureName",sizeof("PictureName")) == 0)
		{
			card->setPicturePath(pParam->FirstChild()->Value());
		}
		if(memcmp(pParam->Value(),"Number",sizeof("Number")) == 0)
		{
			mEventNum[card->getID()] = atoi(pParam->FirstChild()->Value());
		}
		if(memcmp(pParam->Value(),"Test",sizeof("Test")) == 0)
		{
			card->setTest(pParam->FirstChild()->Value());
		}
		if(memcmp(pParam->Value(),"Skill",sizeof("Skill")) == 0)
		{
			card->setSkillId(setSkill(pParam));
		}
		pParam = pParam->NextSibling();
	}
	mEventCard[card->getID()] = card;
}

CardEvent *CardEventManager::findEvent(int eventid)
{
	return mEventCard[eventid];
}

CardEventManager::~CardEventManager()
{

}