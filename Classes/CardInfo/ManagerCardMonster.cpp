#include "ManagerCardMonster.h"
#include "Card.h"

CardMonsterManager::CardMonsterManager()
{
	LoadFile("data//Monster.xml");
	setList(mMonsterList);
}

void CardMonsterManager::setParam(TiXmlNode *value)
{
	TiXmlNode *pParam = value->FirstChild();
	CardMonster *card = new CardMonster();
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
		if(memcmp(pParam->Value(),"Type",sizeof("Type")) == 0)
		{
			card->setType((CardMonster::TYPE)atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Attack",sizeof("Attack")) == 0)
		{
			card->setAttack(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Hit",sizeof("Hit")) == 0)
		{
			card->setHit(atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Model",sizeof("Model")) == 0)
		{
			card->setModel((Card::MODEL)atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Skill",sizeof("Skill")) == 0)
		{
			TiXmlNode *buff = pParam->FirstChild();
			while(buff)
			{
				if(memcmp(buff->Value(),"Out",sizeof("Out")) == 0)
					card->setSkill(CardMonster::CONDITION::out,setSkill(buff));
				if(memcmp(buff->Value(),"Win",sizeof("Win")) == 0)
					card->setSkill(CardMonster::CONDITION::win,setSkill(buff));
				if(memcmp(buff->Value(),"Lose",sizeof("Lose")) == 0)
					card->setSkill(CardMonster::CONDITION::lose,setSkill(buff));
				if(memcmp(buff->Value(),"Pet",sizeof("Pet")) == 0)
					card->setSkill(CardMonster::CONDITION::pet,setSkill(buff));
				buff = buff->NextSibling();
			}
		}
		pParam = pParam->NextSibling();
	}
	mMonsterList[card->getID()] = card;
}

CardMonster *CardMonsterManager::findMonster(int monsterid)
{
	return (CardMonster*)mMonsterList[monsterid];
}

CardMonsterManager::~CardMonsterManager()
{

}