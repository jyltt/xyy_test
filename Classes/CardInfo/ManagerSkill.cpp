#include "ManagerSkill.h"

SkillManager::SkillManager()
{

}

void SkillManager::saveSkillList(Skill *skill)
{

}

Skill &SkillManager::findSkill(int num)
{
	return *mSkillList.find(num)->second;
}

SkillManager::~SkillManager()
{

}