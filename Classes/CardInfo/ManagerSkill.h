#ifndef MANAGERSKILL_H_
#define MANAGERSKILL_H_

#include "head.h"
#include "Skill.h"
#include "Singleton.h"
#include <map>

class SkillManager
{
	Singleton(SkillManager);
public:
	void saveSkillList(Skill *skill);
	Skill &findSkill(int skill_id);
	void runSkill();
protected:
	std::map<int , Skill*> mSkillList;
};
#endif