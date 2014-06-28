#include "CardDlg.h"

CardDlg *CardDlg::create(void )
{
	auto dlg = new CardDlg();
	if (dlg && dlg->init())
	{
		dlg->autorelease();
		dlg->exInit();
		return dlg;
	}
	else
	{
		delete dlg;
		dlg = nullptr;
		return nullptr;
	}
}

bool CardDlg::init()
{
	return true;
}

void CardDlg::exInit(void )
{
	auto CardPic = cocos2d::Sprite::create(m_strPicPath);
	addChild(CardPic);
	CardPic->setPosition(0, 0);
	CardPic->setAnchorPoint(cocos2d::Point(0,0));
}