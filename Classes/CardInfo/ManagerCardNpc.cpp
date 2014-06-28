#include "ManagerCardNpc.h"
#include "Card.h"

CardNpcManager::CardNpcManager()
{
	LoadFile("data//NPC.xml");
	setList(mNpcList);
}

void CardNpcManager::setParam(TiXmlNode *value)
{
	TiXmlNode *pParam = value->FirstChild();
	CardNpc *card = new CardNpc();
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
		if(memcmp(pParam->Value(),"Model",sizeof("Model")) == 0)
		{
			card->setModel((Card::MODEL)atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"HP",sizeof("HP")) == 0)
		{
			card->setHp(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Hit",sizeof("Hit")) == 0)
		{
			card->setHit(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Gender",sizeof("Gender")) == 0)
		{
			card->setGender(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Attack",sizeof("Attack")) == 0)
		{
			card->setAttack(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Hit",sizeof("Hit")) == 0)
		{
			card->setHit(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Adore",sizeof("Adore")) == 0)
		{
			TiXmlNode *buff = pParam->FirstChild();
			while(buff)
			{
				card->setAdore(atoi(buff->FirstChild()->Value()));
				buff = buff->NextSibling();
			}
		}
		if(memcmp(pParam->Value(),"Skill",sizeof("Skill")) == 0)
		{
			TiXmlNode *buff = pParam->FirstChild();
			while(buff)
			{
				card->setSkill(setSkill(buff));
				buff = buff->NextSibling();
			}
		}
		pParam = pParam->NextSibling();
	}
	mNpcList[card->getID()] = card;
}

CardNpc *CardNpcManager::findNpc(int npcid)
{
	return (CardNpc*)mNpcList[npcid];
}

CardNpcManager::~CardNpcManager()
{

}