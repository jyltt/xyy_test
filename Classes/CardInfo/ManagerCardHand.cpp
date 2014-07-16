#include "ManagerCardHand.h"
#include "Card.h"

HandCardManager::HandCardManager()
{
	LoadFile("data//HandCard.xml");
	setList(mHandNum);
}

void HandCardManager::setParam(TiXmlNode *value)
{
	TiXmlNode *pParam = value->FirstChild();
	CardHand *card = new CardHand();
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
			card->setType((CardHand::TYPE)atoi(pParam->FirstChild()->Value()));
		}
		if(memcmp(pParam->Value(),"Number",sizeof("Number")) == 0)
		{
			mHandNum[card->getID()] = atoi(pParam->FirstChild()->Value());
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
				card->setSkill(setSkill(buff));
				buff = buff->NextSibling();
			}
		}
		pParam = pParam->NextSibling();
	}
	mHandCard[card->getID()] = card;
}

CardHand *HandCardManager::findCard(int cardId)
{
	auto card = mHandCard.find(cardId);
	if (card == mHandCard.end())
		return nullptr;
	else
		return card->second;
}

HandCardManager::~HandCardManager()
{

}