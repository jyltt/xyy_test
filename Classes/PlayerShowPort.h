#ifndef PLAYERSHOWPORT_H_
#define PLAYERSHOWPORT_H_
/*
***数据显示层
***仅仅用于获得玩家信息
*/
#include <vector>

class CardNpc;

class PlayerShowPort
{
public:
	PlayerShowPort(int playerid,int npccardid = -1) : m_HP(0)
		, m_PlayerID(playerid)
		, m_Attack(0)
		, m_Hit(0)
		, m_NpcCardID(npccardid)
		, m_CardNum(0)
	{}
	virtual ~PlayerShowPort(){}
	virtual int getHP()const { return m_HP; }
	virtual int getAttack()const { return m_Attack; }
	virtual int getHit()const { return m_Hit; }
	int getPlayerID() const { return m_PlayerID; }
	int getNpcCardID()const { return m_NpcCardID; }
	virtual int getCardNum()const { return m_CardNum; }
	CardNpc* getNpcCard()const { return m_NpcCard; }
	const std::vector<int> &getHandCardID()const { return m_HandCardID; }
	const std::vector<int> &getPetCardID()const { return m_PetCardID; }
	const std::vector<int> &getEquipCardID()const { return m_EquipCardID; }
	const std::vector<int> &getArmorCardID()const { return m_ArmorCardID; }
protected:
	int m_PlayerID;
	int m_HP;
	int m_Attack;
	int m_Hit;
	int m_NpcCardID;
	int m_CardNum;
	CardNpc *m_NpcCard;
	std::vector<int> m_HandCardID;
	std::vector<int> m_PetCardID;
	std::vector<int> m_EquipCardID;
	std::vector<int> m_ArmorCardID;
};
#endif