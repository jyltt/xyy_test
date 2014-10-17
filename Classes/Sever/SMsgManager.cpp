#include "SMsgManager.h"

#include "msgManager.h"

SMsgManager::SMsgManager()
{

}

SMsgManager::~SMsgManager()
{

}

void SMsgManager::sendMessage(BaseMsg *msg, int size)
{
	MsgManager::getSingleton().recvMessgae(msg, size);
}

void SMsgManager::recvMessgae(BaseMsg *msg, int size)
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
		case GameMsg_C2S::ChoseCard_C2S:
			ChoseCard((Game_ChoseCard_C2S*)msg);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void SMsgManager::ChoseCard(Game_ChoseCard_C2S *msg)
{
	auto sendmsg = new Game_ChoseCard_S2C;
	sendmsg->msgname = GameMsg_S2C::GetHandCard_S2C;
	sendmsg->playerid = msg->playerid;
	sendmsg->cardconst = 4;
	sendmsg->cardlist;// TODO : 
}
