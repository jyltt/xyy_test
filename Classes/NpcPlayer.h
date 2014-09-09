#ifndef NPCPLAYER_H_
#define NPCPLAYER_H_

#include "PlayerShowPort.h"
#include "CardInfo/Card.h"

class NpcPlayer :
	public PlayerShowPort
{
public:
	NpcPlayer(int playerid,int npccardid = -1);
	virtual ~NpcPlayer();

	void setHP(int hp);
	void changeHP(int change);

	void setNpcCardID(int npccardid);
	
	virtual void changeCardNum(int change);
	void setCardNum(int cardnum);

	virtual void pushHandCard(int cardid){}
	virtual void popHandCard(int cardid){}
	virtual void clearHandCard(){}

	void pushPet(int cardid, CardMonster::TYPE type);
	void popPet(int cardid);
	void popPet(CardMonster::TYPE type);
	void clearPet();

	void pushEquipID(int cardid,int oldcardid = -1);
	void popEquipID(int cardid);
	void clearEquip();

	void pushArmorID(int cardid,int oldcardid = -1);
	void popArmorID(int cardid);
	void clearArmor();
private:

};
#endif