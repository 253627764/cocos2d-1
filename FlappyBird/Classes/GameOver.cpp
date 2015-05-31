#include "GameOver.h"

USING_NS_CC;

GameOver::GameOver(void)
{
}


GameOver::~GameOver(void)
{
}


bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}
	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	//�Ʒְ�
	panel = Sprite::createWithSpriteFrameName("score_panel.png");
	panel->setPosition(Point(origin.x+visibleSize.width/2,origin.y-visibleSize.height/2));
	this->addChild(panel);

	//�Ʒְ嶯��
	auto moveto = MoveTo::create(0.6f,Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.5));
	auto callback = CallFuncN::create(CC_CALLBACK_0(GameOver::callBack,this));
	auto sequence = Sequence::create(moveto,callback,NULL);
	panel->runAction(sequence);

	//gameover����
	auto gameover = Sprite::createWithSpriteFrameName("text_game_over.png");
	gameover->setPosition(Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height+gameover->getContentSize().height/2));

	//gameover����ҲҪִ����ͬ�Ķ������������Ǵ��ϵ����˶�
	auto moveto2 = MoveTo::create(0.6f,Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.7));

	gameover->runAction(moveto2);
	this->addChild(gameover);

	return true;
}

void GameOver::callBack()
{
	//����������һ�ΰ�ť
	//�Ʒְ��gameover����ִ���궯���󣬳��ְ�ť
	auto again = Sprite::createWithSpriteFrameName("button_play.png");
	auto menuAgain = MenuItemSprite::create(again,again,CC_CALLBACK_0(GameOver::gameAgain,this));

	auto rank = Sprite::createWithSpriteFrameName("button_score.png");
	auto menuRank = MenuItemSprite::create(rank,rank,CC_CALLBACK_0(GameOver::getRank,this));

	//������ť������趨
	int l = (visibleSize.width-again->getContentSize().width*2)/3;

	menuAgain->setPosition(Point(origin.x+l+again->getContentSize().width/2,origin.y+visibleSize.height*0.3));
	menuRank->setPosition(Point(origin.x+visibleSize.width-l-again->getContentSize().width/2,origin.y+visibleSize.height*0.3));

	//�Ѱ�ť�ŵ��˵���ȥ
	auto menu = Menu::create(menuAgain,menuRank,NULL);
	menu->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//������ʾ
	scores = 0;
	auto str = __String::createWithFormat("%d",scores);
	numberLabel = Label::createWithBMFont("D:\\hello\\Bird\\Resources\\num2.fnt",str->getCString());
	numberLabel->setPosition(Point(origin.x+visibleSize.width/2+65,origin.y+visibleSize.height*0.5+10));
	this->addChild(numberLabel);

	//���ý���
	int l2 = (visibleSize.width-panel->getContentSize().width)/2;
	Sprite * medals;
	medals = Sprite::createWithSpriteFrameName("medals_1.png");
	medals->setPosition(Point(origin.x+l2+54,origin.y+visibleSize.height*0.49));
	this->addChild(medals);
}

//�л�����Ϸ����
void GameOver::gameAgain()
{
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f,GameScene::createScene()));
}

//������Ϸ
void GameOver::getRank()
{
	Director::getInstance()->end();
}
