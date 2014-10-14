#ifndef MSGMANAGER_H_
#define MSGMANAGER_H_

#include "CardInfo\Singleton.h"
#include "MessageData.h"

class MsgManager
{
	Singleton(MsgManager);
public:
	void sendMessage(BaseMsg *msg, int size);
	void recvMessgae(BaseMsg *msg, int size);
private:
	void GetHandCard(Game_GetHandCard_S2C *msg);
};

#endif // !MSGMANAGER_H_
