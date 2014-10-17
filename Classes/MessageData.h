#ifndef MESSAGEDATA_H_
#define MESSAGEDATA_H_
enum class MsgType
{
	sys,
	game,
};

enum GameMsg_C2S		//Client to Sever
{
	EquipArms_C2S,
	EquipArmor_C2S,
	ChoseCard_C2S,
	NextRound_C2S,
	UsingHandCard_C2S,
	GiveupHandCard_C2S,
	UsingSpecialSkill_C2S,

};

enum GameMsg_S2C		//Sever to Client
{
	GetHandCard_S2C,
	EquipArms_S2C,
	EquipArmor_S2C,
	ChoseCard_S2C,
	NextRound_S2C,
	UsingHandCard_S2C,
	GiveupHandCard_S2C,
	UsingSpecialSkill_S2C,
};

struct BaseMsg
{
	int size;
	MsgType type;
	int msgname;     //GameMsg_c2s or GameMsg_s2c
};

#define GAMEMSG(_msgname_) struct Game_##_msgname_:public BaseMsg

#pragma region Client to Sever
GAMEMSG(EquipArms_C2S)
{
	int playerid;
	int cardid;
	int equipPos;
};

GAMEMSG(EquipArmor_C2S)
{
	int playerid;
	int cardid;
	int equipPos;
};

GAMEMSG(ChoseCard_C2S)
{
	int playerid;
	int cardid;
};

GAMEMSG(NextRound_C2S)
{
	int playerid;
	int roundid;
};

GAMEMSG(UsingHandCard_C2S)
{
	int playerid;
	int cardid;
	int playerconst;
	int *playerlist;
};

GAMEMSG(GiveupHandCard_C2S)
{
	int playerid;
	int cardid;
};

GAMEMSG(UsingSpecialSkill_C2S)
{
	int playerid;
	int cardid;
	int playerconst;
	int *playerlist;
};
#pragma endregion

#pragma region Sever to Client
GAMEMSG(GetHandCard_S2C)
{
	int playerid;
	int cardconst;
	int *handcardid;
};

GAMEMSG(EquipArms_S2C)
{
	int playerid;
	int cardid;
	int equipPos;
};

GAMEMSG(EquipArmor_S2C)
{
	int playerid;
	int cardid;
	int equipPos;
};

GAMEMSG(ChoseCard_S2C)
{
	int playerid;
	int cardconst;
	int *cardlist;
};

GAMEMSG(NextRound_S2C)
{
	int playerid;
	int roundid;
};

GAMEMSG(UsingHandCard_S2C)
{
	int playerid;
	// TODO : 
};

#pragma endregion
#endif