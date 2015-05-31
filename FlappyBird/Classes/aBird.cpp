#include "aBird.h"

USING_NS_CC;

bool aBird::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	visibleSize=Director::getInstance()->getVisibleSize();
	origin=Director::getInstance()->getVisibleOrigin();
	
	//����С�񶯻�
	auto bird_animation = Animation::create();
	bird_animation->setDelayPerUnit(0.1f);
	bird_animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird0_0.png"));
	bird_animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird0_1.png"));
	bird_animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird0_2.png"));

	auto bird_animate = Animate::create(bird_animation);
	auto repeat = RepeatForever::create(bird_animate);

    bird = Sprite::createWithSpriteFrameName("bird0_0.png");
	bird->setPosition(visibleSize.width/2,visibleSize.height/2);
	bird->runAction(repeat);

	//����С��Body
	auto bird_body = PhysicsBody::create();
	auto bird_shape = PhysicsShapeCircle::create(15);
	bird_body->addShape(bird_shape);
	bird_body->setDynamic(true);
	bird_body->setGravityEnable(false);
	bird_body->setLinearDamping(0.7f);
	bird_body->setCategoryBitmask(1);
	bird_body->setCollisionBitmask(-1);
	bird_body->setContactTestBitmask(-1);
	bird->setPhysicsBody(bird_body);
	bird->setPosition(Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.6));
	addChild(bird);

	//��ӵ���¼�
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);
	listener->onTouchBegan = [this](Touch *t, Event *e)
	{
		return true;//���true,�������µ�touch����
	};

	listener->onTouchEnded = [this](Touch *t, Event *e)
	{
		//ÿ���һ�����Ϸ�
		bird->getPhysicsBody()->setVelocity(Point(0,260));	
	};

	//������ʱ������,��ֹС��ɳ��߽�
	this->scheduleUpdate();
	
	return true;
}


aBird* aBird::createBird()
{
	aBird *temp = new aBird();
	temp->init();
	return temp;
}

void aBird::stateChange(birdState st)
{
	switch (st)
	{
	case IDLE:
		idle();break;
	case FLY:
		fly();break;
	case DIE:
		die();break;
	default:
		break;
	}
}

void aBird::idle()
{
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,bird);
	bird->getPhysicsBody()->setGravityEnable(false);
}

void aBird::fly()
{
	bird->getPhysicsBody()->setGravityEnable(true);
}

void aBird::die()
{
	//�رն�ʱ��
	this->unscheduleUpdate();
	//�Ƴ��������
	_eventDispatcher->removeEventListener(listener);
	//����������Ӧ����Ϊ���������������.....��
	bird->getPhysicsBody()->setGravityEnable(true);
	//ֹͣС������ж���
	bird->stopAllActions();
	//���ýǶȣ�ͷ����...
	bird->setRotation(90);
}

void aBird::update(float)
{
	//��ֹ�ɳ��߽�
	if (bird->getPositionY()>(origin.y+visibleSize.height))
	{
		bird->setPositionY(origin.y+visibleSize.height);
	}
	//С��ķ���ͷ���ĽǶȣ����ݷ��е�Y���ٶȾ���
	bird->setRotation(bird->getPhysicsBody()->getVelocity().y*-0.1);

}