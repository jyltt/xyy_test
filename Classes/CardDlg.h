#ifndef CARDDLG_H_
#define CARDDLG_H_

#include "cocos2d.h"

class CardDlg :
	public cocos2d::Node
{
public:
	static CardDlg* create(void );
	virtual bool init() override;

	void exInit(void);
	bool isShow()const{ return m_bShow; }
	void setShow(bool show){ m_bShow = show; }
	int getCardID()const { return m_nCardID; }
	const std::string &getDescribe()const { return m_strDescribe; }
private:
	std::string m_strPicPath;
	int m_nCardID;
	std::string m_strDescribe;
	bool m_bShow;
};
#endif