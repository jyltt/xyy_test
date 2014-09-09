#ifndef PLAYERLIST_H_
#define PLAYERLIST_H_

#include "CardInfo/Singleton.h"

#include <vector>
#include "NpcPlayer.h"

class PlayerList
{
	Singleton(PlayerList);
public :
    //PlayerList();
    //virtual~PlayerList();
    int getCurrentPlayerSign(){ return m_CurrentPlayerSign; }
    void setPlayerNum(int num){ m_PlayerNum = num; }
    bool joinPlayer(NpcPlayer* player);
    void leavePlayer(NpcPlayer* player);
    void getPlayerFromID(int playerID);
    NpcPlayer* getPlayerfromSign(int sign) 
    {
        if(sign < m_player.size())
            return m_player[sign];
        return nullptr;
    }

private:
    std::vector<NpcPlayer*> m_player;
    int m_CurrentPlayerSign;
    int m_PlayerNum;
    
};
#endif