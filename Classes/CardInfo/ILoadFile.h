#pragma once
#include "iostream"
#include "Xml\tinyxml.h"

class ILoadFile
{
public:
	ILoadFile(void);
	void LoadFile(const std::string &filename);
	virtual void setParam(TiXmlNode *value) = 0;
	int setSkill(TiXmlNode *value);
	~ILoadFile(void);
};
