#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Score : public Layer
{
public:
	Score(void);
	~Score(void);

	virtual bool init();
	CREATE_FUNC(Score);

	//�ӷ�
	void addScore();
	//���÷���,ͬʱ�Ƴ���������
	void resetScore();
	//��ȡ����
	int getScore();
	////��õ�������
	static Score *getInstance();

private:
	
	int score;
	LabelBMFont *label;

};

