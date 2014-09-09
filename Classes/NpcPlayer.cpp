#include "NpcPlayer.h"
#include "CardInfo/ManagerCardEvent.h"
#include "CardInfo/ManagerCardHand.h"
#include "CardInfo/ManagerCardMonster.h"
#include "CardInfo/ManagerCardNpc.h"
#include "CardInfo/ManagerSkill.h"

NpcPlayer::NpcPlayer(int playerid,int npccardid /* = -1 */)
	:PlayerShowPort(playerid,npccardid)
{
	m_PetCardID.push_back(-1);
	m_PetCardID.push_back(-1);
	m_PetCardID.push_back(-1);
	m_PetCardID.push_back(-1);
	m_PetCardID.push_back(-1);
	if (npccardid != -1)
		setNpcCardID(npccardid);
}

NpcPlayer::~NpcPlayer()
{

}

void NpcPlayer::setHP(int hp)
{
	if (hp < m_NpcCard->getHp())
		m_HP = hp;
	else
		m_HP = m_NpcCard->getHp();
}

void NpcPlayer::changeHP(int change)
{
	m_HP += change;
	if (m_HP > m_NpcCard->getHp())
		m_HP = m_NpcCard->getHp();
	if (m_HP < 0)
		m_HP = 0;
}

void NpcPlayer::setNpcCardID(int npccardid)
{
	m_NpcCardID = npccardid;
	if (m_NpcCardID != -1)
	{
		m_NpcCard = CardNpcManager::getSingleton().findCard(npccardid);
		setHP(m_NpcCard->getHp());
		m_Attack = m_NpcCard->getAttack();
		m_Hit = m_NpcCard->getHit();
	}
	else
		m_NpcCard = nullptr;
}

void NpcPlayer::changeCardNum(int change)
{
	m_CardNum += change;
	if (m_CardNum < 0)
		m_CardNum = 0;
}

void NpcPlayer::setCardNum(int cardnum)
{
	m_CardNum = cardnum;
	if (m_CardNum < 0)
		m_CardNum = 0;
}

void NpcPlayer::pushPet(int cardid, CardMonster::TYPE type)
{
	if (cardid < 0)
		return;
	m_PetCardID[(int)type] = cardid;
}

void NpcPlayer::popPet(CardMonster::TYPE type)
{
	m_PetCardID[(int)type] = -1;
}

void NpcPlayer::popPet(int cardid)
{
	for (auto i = m_PetCardID.begin(); i < m_PetCardID.end(); i++)
	{
		if (*i == cardid)
			*i = -1;
	}
}

void NpcPlayer::clearPet()
{
	for (int i = 0; i < m_PetCardID.size(); i++)
		m_PetCardID[i] = -1;
}

void NpcPlayer::pushEquipID(int cardid,int oldcardid)
{
	if (oldcardid == -1)
		m_EquipCardID.push_back(cardid);
	else
	{
		for (auto i = 0; i < m_EquipCardID.size(); i++)
		{
			if (m_EquipCardID[i] == oldcardid)
			{
				m_EquipCardID[i] = cardid;
				break;
			}
		}
	}
}

void NpcPlayer::popEquipID(int cardid)
{
	for (auto i = m_EquipCardID.begin(); i < m_EquipCardID.end(); i++)
	{
		if ((*i) == cardid)
		{
			m_EquipCardID.erase(i);
			break;
		}
	}
}

void NpcPlayer::clearEquip()
{
	m_EquipCardID.clear();
}

void NpcPlayer::pushArmorID(int cardid,int oldcardid/* = -1*/)
{
	if (oldcardid == -1)
		m_ArmorCardID.push_back(cardid);
	else
	{
		for (auto i = 0; i < m_ArmorCardID.size(); i++)
		{
			if (m_ArmorCardID[i] == oldcardid)
			{
				m_ArmorCardID[i] = cardid;
				break;
			}
		}
	}
}

void NpcPlayer::popArmorID(int cardid)
{
	for (auto i = m_ArmorCardID.begin(); i < m_ArmorCardID.end(); i++)
	{
		if ((*i) == cardid)
		{
			m_ArmorCardID.erase(i);
			break;
		}
	}
}

void NpcPlayer::clearArmor()
{
	m_ArmorCardID.clear();
}
