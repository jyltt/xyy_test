#ifndef SMSGMANAGER_H_
#define SMSGMANAGER_H_

#include "CardInfo\Singleton.h"
#include "MessageData.h"

class SMsgManager
{
	Singleton(SMsgManager);
public:
	void sendMessage(BaseMsg *msg, int size);
	void recvMessgae(BaseMsg *msg, int size);
private:
	void GetHandCard(Game_GetHandCard_C2S *msg);
};

#endif // !SMSGMANAGER_H_
