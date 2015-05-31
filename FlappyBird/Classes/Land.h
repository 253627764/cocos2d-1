#pragma once
#include "cocos2d.h"
#include "Pipe.h"

USING_NS_CC;

class Land : public Layer 
{
public:
	Land(void);
	~Land(void);

	virtual bool init();
	CREATE_FUNC(Land);

	//���濪ʼ����
	void landMove(float);
	//����ֹͣ����
	void landStop();

private:
	Sprite *land1;
	Sprite *land2;
	
};

