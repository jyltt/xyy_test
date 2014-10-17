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
	void ChoseCard(Game_ChoseCard_C2S *msg);
};

#endif // !SMSGMANAGER_H_
