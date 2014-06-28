#ifndef SKILL_H_
#define SKILL_H_

#include "head.h"

class Skill
{
public:
	SET_GET(int , ID);
	SET_GET_N(char , Test,200);
	SET_GET_N(char , Name,10);
	SET_GET(bool , Initiative);
	SET_GET(STATUS , Status);
};
#endif