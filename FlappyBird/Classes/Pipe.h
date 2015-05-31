#pragma once
#include "cocos2d.h"
#include <cstdlib>

USING_NS_CC;
using namespace std;

class Pipe : public Layer
{
public:
	Pipe(void);
	~Pipe(void);

	virtual bool init();
	CREATE_FUNC(Pipe);

	//��ӹ���
	void addPipe();
	//�ƶ����ӣ�����Land�������moveLand
	void movePipe(float t);
	//ֹͣ�ƶ�����
	void stopPipe();
	//��ȡ����߶�
	int getRandomHeight();

private:
	
	//��������pipe����
	 vector<Node *> pips;

};

