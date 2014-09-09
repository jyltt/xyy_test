#include "player.h"

Player::Player(int playerid ,int npccardid /* = -1 */)
	:NpcPlayer(playerid,npccardid)
{

}

Player::~Player()
{

}

void Player::pushHandCard(int cardid)
{
	m_HandCardID.push_back(cardid);
}

void Player::popHandCard(int cardid)
{
	for (auto i = m_HandCardID.begin(); i < m_HandCardID.end(); i++)
	{
		if ((*i) == cardid)
		{
			m_HandCardID.erase(i);
			break;
		}
	}
}

void Player::clearHandCard()
{
	m_HandCardID.clear();
}