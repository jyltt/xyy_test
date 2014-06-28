#include "ILoadFile.h"
#include "ManagerSkill.h"

ILoadFile::ILoadFile(void)
{
}

void ILoadFile::LoadFile(const std::string &filename)
{
	TiXmlDocument *doc = new TiXmlDocument(filename.c_str());

	if(doc->LoadFile())
	{
		TiXmlElement *rootnode = doc->RootElement();
		TiXmlNode *pCard = rootnode->FirstChild();
		while (pCard)
		{
			this->setParam(pCard);
			pCard = pCard->NextSibling();
		}
	}
	else
	{
		char str[100];
		sprintf(str,"¶ÁÈ¡%sÎÄ¼þÊ§°Ü",filename.c_str());
	}
}

int ILoadFile::setSkill(TiXmlNode *value)
{
	TiXmlNode *child = value;
	Skill *skill = new Skill();
	skill->setName(child->Value());
	child = child->FirstChild();
	while(child)
	{
		if(memcmp(child->Value(),"Text",sizeof("Text")) == 0)
		{
			skill->setTest(child->FirstChild()->Value());
		}
		if(memcmp(child->Value(),"Sign",sizeof("Sign")) == 0)
		{
			skill->setID( atoi(child->FirstChild()->Value()));
		}
		if(memcmp(child->Value(),"Status",sizeof("Status")) == 0)
		{
			skill->setStatus((STATUS) atoi(child->FirstChild()->Value()));
		}
		if(memcmp(child->Value(),"Initiative",sizeof("Initiative")) == 0)
		{
			skill->setInitiative( atoi(child->FirstChild()->Value()));
		}
		child = child->NextSibling();
	}
	SkillManager::getSingleton().saveSkillList(skill);
	return skill->getID();
}

ILoadFile::~ILoadFile(void)
{
}
