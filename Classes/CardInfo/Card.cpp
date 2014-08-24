#include "Card.h"

Card::Card(CARDTYPE type) :m_ID(-1), m_CardTpye(type)
{
}

CardHand::CardHand():
Card(Card::CARDTYPE::Hand)
{
	m_SkillList[0] = -1;
	m_SkillList[1] = -1;
}

int CardHand::getSkill(int skill_num)
{
	if(skill_num < 2)
		return m_SkillList[skill_num];
	else 
		return -1;
}

void CardHand::setSkill(int skill_id)
{
	if(m_SkillList[0] < 0)
		m_SkillList[0] = skill_id;
	else
		m_SkillList[1] = skill_id;
}

CardMonster::CardMonster()
	:Card(Card::CARDTYPE::Monster)
{
	for(auto i: m_SkillList)
		i = -1;
}

int CardMonster::getSkill(CONDITION condition)
{
	return m_SkillList[(int)condition];
}

void CardMonster::setSkill(CONDITION condition,int skill_id)
{
	m_SkillList[(int)condition] = skill_id;
}

CardNpc::CardNpc()
	:Card(Card::CARDTYPE::Npc)
{
}

void CardNpc::setAdore(int adore_id)
{
	m_Adore.push_back(adore_id);
}

std::vector<int> &CardNpc::getAdore()
{
	return m_Adore;
}

void CardNpc::setSkill(int skill_id)
{
	m_SkillList.push_back(skill_id);
}

int CardNpc::getSkill(int skill_num)
{
	if (skill_num >= m_SkillList.size())
		return -1;
	return m_SkillList[skill_num];
}

CardEvent::CardEvent() :m_SkillId(-1), Card(Card::CARDTYPE::Event)
{
}