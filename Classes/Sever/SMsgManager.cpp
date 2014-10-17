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
		case GameMsg_C2S::GetHandCard_C2S:
			GetHandCard((Game_GetHandCard_C2S*)msg);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void SMsgManager::GetHandCard(Game_GetHandCard_C2S *msg)
{

}
