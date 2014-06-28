#include "IShuffle.h"

IShuffle::IShuffle():heat(0)
{
	srand((unsigned)time_t(NULL));
}

void IShuffle::setList(std::map<int ,int> &list)
{
	for(std::map<int ,int>::iterator i = list.begin();
		i != list.end();i++)
	{
		for(int j = 0;j < i->second;j++)
			this->mShowCardList.push_back(i->first);
	}
	std::random_shuffle(mShowCardList.begin(), mShowCardList.end(),[](int i){return rand()%i;});
}



int IShuffle::getOne()
{
	if(heat < mShowCardList.size())
		return mShowCardList[heat++];
	return -1;
}

int IShuffle::getSurplus()
{
	return mShowCardList.size();
}