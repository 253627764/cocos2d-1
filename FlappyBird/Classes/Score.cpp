#include "Score.h"

USING_NS_CC;
//Ψһ��̬��������WelcomeScene
static Score *instance = NULL;

Score::Score(void)
{
}
Score::~Score(void)
{
}

Score *Score::getInstance()
{
	//�ж���������Ƿ����
	if (instance==NULL)
	{
		//��������ڣ��Ǿʹ���
		Score *temp=new Score();
		//Ȼ���ʼ��
		temp->init();
		instance=temp;
	}
	//����Ѿ������ˣ��Ǿ�ֱ�ӷ���
	return instance;
}

bool Score::init()
{
	auto origin=Director::getInstance()->getVisibleOrigin();
    auto visibleSize=Director::getInstance()->getVisibleSize();
	//һ��ʼ��ʾ0
	score = 0;
	auto str=__String::createWithFormat("%d",score);
	label = LabelBMFont::create(str->getCString(),"D:\\hello\\Bird\\Resources\\num.fnt");
	label->setPosition(Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.85));
	this->addChild(label);

	return true;
}


void Score::addScore()
{
	++score;
	auto str=__String::createWithFormat("%d",score);
	label->setString(str->getCString());
}

void Score::resetScore()
{
	score = 0;
	auto str=__String::createWithFormat("%d",score);
	label->setString(str->getCString());
}

int Score::getScore()
{
	return score;
}