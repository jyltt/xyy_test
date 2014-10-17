#include "msgManager.h"
#include "PlayerList.h"
#include "NpcPlayer.h"

#include "Sever/SMsgManager.h"

MsgManager::MsgManager()
{

}

MsgManager::~MsgManager()
{

}

void MsgManager::sendMessage(BaseMsg *msg, int size)
{
	SMsgManager::getSingleton().recvMessgae(msg, size);
}

void MsgManager::recvMessgae(BaseMsg *msg, int size)
{
	if (msg == 0 || msg->size != size)
		return;

	switch (msg->type)
	{
	case MsgType::sys:
		break;
	case MsgType::game:
		switch (msg->msgname)
		{
		case GameMsg_S2C::GetHandCard_S2C:
			GetHandCard((Game_GetHandCard_S2C*)msg);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void MsgManager::GetHandCard(Game_GetHandCard_S2C *msg)
{
	auto player = PlayerList::getSingleton().getPlayerFromID(msg->playerid);
	if (!player)
		return;
}
