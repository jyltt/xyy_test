#ifndef PLAYER_H_
#define PLAYER_H_

#include "NpcPlayer.h"

class Player :
	public NpcPlayer
{
public:	
	Player(int playerid, int npccardid = -1);
	~Player();

	virtual int  getCardNum()const { return m_HandCardID.size(); }
	virtual void pushHandCard(int cardid)override;
	virtual void popHandCard(int cardid)override;
	virtual void clearHandCard()override;
};
#endif // !PLAYER_H_
