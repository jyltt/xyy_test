#include "Card.h"

Card::Card():mID(-1)
{
}

CardHand::CardHand()
{
	mSkillList[0] = -1;
	mSkillList[1] = -1;
}

int CardHand::getSkill(int skill_num)
{
	if(skill_num < 2)
		return mSkillList[skill_num];
	else 
		return -1;
}

void CardHand::setSkill(int skill_id)
{
	if(mSkillList[0] < 0)
		mSkillList[0] = skill_id;
	else
		mSkillList[1] = skill_id;
}

CardMonster::CardMonster()
{
	for(auto i: mSkillList)
		i = -1;
}

int CardMonster::getSkill(CONDITION condition)
{
	return mSkillList[(int)condition];
}

void CardMonster::setSkill(CONDITION condition,int skill_id)
{
	mSkillList[(int)condition] = skill_id;
}

CardNpc::CardNpc()
{
}

void CardNpc::setAdore(int adore_id)
{
	mAdore.push_back(adore_id);
}

std::vector<int> &CardNpc::getAdore()
{
	return mAdore;
}

void CardNpc::setSkill(int skill_id)
{
	mSkillList.push_back(skill_id);
}

int CardNpc::getSkill(int skill_num)
{
	return mSkillList[skill_num];
}

CardEvent::CardEvent():mSkillId(-1)
{
}