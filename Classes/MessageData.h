#ifndef MESSAGEDATA_H_
#define MESSAGEDATA_H_
enum class MsgType
{
	sys,
	game,
};

enum GameMsg_C2S		//Client to Sever
{
	GetHandCard_C2S,
	EquipArms_C2S,
	EquipArmor_C2S,

};

enum GameMsg_S2C		//Sever to Client
{
	GetHandCard_S2C,
};

struct BaseMsg
{
	int size;
	MsgType type;
	int msgname;     //GameMsg_c2s or GameMsg_s2c
};

#define GAMEMSG(_msgname_) struct Game_##_msgname_:public BaseMsg

GAMEMSG(GetHandCard_C2S)
{
	int playerid;
};

GAMEMSG(GetHandCard_S2C)
{
	int playerid;
	int handcardid;
};
#endif