#ifndef HEAD_H_
#define HEAD_H_

#include <iostream>

#define SET_GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
											public:const __type__ &get##__func__()const {return m_##__name__;}\
											public:void set##__func__(const __type__ &var){m_##__name__ = var;}

#define SET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:void set##__func__(const __type__ &var){m_##__name__ = var;}

#define GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:const __type__ &get##__func__()const {return m_##__name__;}

#define SET_GET(__type__,__name__) SET_GET_FUNC(__type__,__name__,__name__)

#define SET(__type__,__name__) SET_FUNC(__type__,__name__,__name__)

#define GET(__type__,__name__) GET_FUNC(__type__,__name__,__name__) 

#define SET_GET_FUNC_N(__type__,__name__,__num__,__func__) \
	protected:__type__ m_##__name__[__num__];\
	public:__type__ *get##__func__(){return m_##__name__;}\
	public:void set##__func__(const __type__ *var){strcpy(m_##__name__,var);}

#define SET_FUNC_N(__type__,__name__,__num__,__func__) protected:__type__ m_##__name__[__num__];\
										public:void set##__func__(const __type__ &var){strcpy(m_##__name__,var);}

#define GET_FUNC_N(__type__,__name__,__num__,__func__) protected:__type__ m_##__name__[__num__];\
										public:__type__ *get##__func__(){return m_##__name__;}

#define SET_GET_N(__type__,__name__,__num__) SET_GET_FUNC_N(__type__,__name__,__num__,__name__)

#define SET_N(__type__,__name__,__num__) SET_FUNC_N(__type__,__name__,__num__,__name__)

#define GET_N(__type__,__name__,__num__) GET_FUNC_N(__type__,__name__,__num__,__name__) 

#define V_SET_GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
											public:__type__ get##__func__();\
											public:void set##__func__(const __type__ &var);

#define V_SET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:void set##__func__(const __type__ &var);

#define V_GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:__type__ get##__func__();

#define V_SET_GET(__type__,__name__) V_SET_GET_FUNC(__type__,__name__,__name__)

#define V_SET(__type__,__name__) V_SET_FUNC(__type__,__name__,__name__)

#define V_GET(__type__,__name__) V_GET_FUNC(__type__,__name__,__name__) 

enum class STATUS{openning,	//开局			0
		bout,				//回合			1	
		events,				//事件			2
		skill_begin,		//技牌			3
		skill,				//技牌			4
		skill_end,			//技牌			5
		fight_round_end,	//战斗（翻取怪牌后）6
		fight,				//战牌			7
		settlement,			//结算			8
		pickup,				//补牌			9
		IV,					//弃牌			10
		bout_end,			//回合结束		11
		ending,				//结束			12
		die,				//死亡			13
		reply,				//补血			14
		hurt,				//扣血			15
		show_card,			//出牌			16
		whenever,			//任何时候		17
		fight_round_begin,	//战斗（翻取怪牌前）18
};
#endif