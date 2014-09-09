#include "PlayerLIst.h"
#include "NpcPlayer.h"

PlayerList::PlayerList() 
	:m_CurrentPlayerSign(0)
	, m_PlayerNum(4)
{

}

PlayerList::~PlayerList()
{

}

bool PlayerList::joinPlayer(NpcPlayer* player)
{
    if(m_player.size() >= m_PlayerNum)
        return false;
    for(auto i = 0; i < m_player.size();++i)
    {
        if(m_player[i]->getPlayerID() == player->getPlayerID())
            return false;
    }
    m_player.push_back(player);
    return true;
}

void PlayerList::leavePlayer(NpcPlayer *player)
{
    for(auto i = 0; i < m_player.size();++i)
    {
        if(m_player[i]->getPlayerID() == player->getPlayerID())
            m_player.erase(m_player.begin() + i);
    }
}