#include "Land.h"


Land::Land(void)
{
}
Land::~Land(void)
{
}

bool Land::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto origin=Director::getInstance()->getVisibleOrigin();
	auto visibleSize=Director::getInstance()->getVisibleSize();

	//����2��land��ʵ�ֹ���Ч��
	land1 = Sprite::createWithSpriteFrameName("land.png");
	land1->setPosition(Point(origin.x+land1->getContentSize().width/2,origin.y+land1->getContentSize().height/2));
	//��������ӿ��Ƿ�ֹ�����������ʱ���ֺڱ�
	land1->getTexture()->setAliasTexParameters();
	auto land1_body = PhysicsBody::create();
	auto land1_shape = PhysicsShapeBox::create(land1->getContentSize());
	land1_body->addShape(land1_shape);
	land1_body->setDynamic(false);//����Ϊ��̬����
	land1_body->setGravityEnable(false);//��������Ӱ��
	land1_body->setCategoryBitmask(1);  
	land1_body->setCollisionBitmask(-1);
	land1_body->setContactTestBitmask(-1);
	land1_body->setLinearDamping(0.7f);//��������
	land1->setPhysicsBody(land1_body); //��land1��lan1_body
	addChild(land1);

	
    land2 = Sprite::createWithSpriteFrameName("land.png");
	land2->setPosition(Point(origin.x+land1->getPositionX()+land1->getContentSize().width-2,land1->getPositionY()));
	land2->getTexture()->setAliasTexParameters();
	auto land2_body = PhysicsBody::create();
	auto land2_shape = PhysicsShapeBox::create(land2->getContentSize());
	land2_body->addShape(land2_shape);
	land2_body->setDynamic(false);
	land2_body->setGravityEnable(false);
	land2_body->setCategoryBitmask(1);  
	land2_body->setCollisionBitmask(-1);
	land2_body->setContactTestBitmask(-1);
	land2_body->setLinearDamping(0.7f);
	land2->setPhysicsBody(land2_body);
	addChild(land2);

	schedule(schedule_selector(Land::landMove), 1/60);//������ʱ��

	return true;
}

void Land::landMove(float)
{
	land1->setPositionX(land1->getPositionX()-2);
	land2->setPositionX(land1->getPositionX()+land1->getContentSize().width-2);
	if (land2->getPositionX()==land2->getContentSize().width/2)
	{
		land1->setPositionX(land2->getContentSize().width/2);
	}

}

void Land::landStop()
{
	unschedule(schedule_selector(Land::landMove));
}