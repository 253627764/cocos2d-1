#pragma once

#include "cocos2d.h"
#include "Score.h"
#include "GameScene.h"

USING_NS_CC;

class GameOver:public cocos2d::Layer
{
public:
	GameOver();
	~GameOver();
	bool init();
	//�ص�����
	void callBack();
	//����һ��
	void gameAgain();
	//��ȡ����
	void getRank();
	//��ʾ����
	void showScore(float);
	CREATE_FUNC(GameOver);

private:

	Size visibleSize;
	Point origin;

	Sprite *panel ;

	Label * numberLabel;
	//���ڳ�ʼ������
	int scores;
	
};
