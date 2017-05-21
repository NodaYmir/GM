
#include "firstScene.h"
#include "SimpleAudioEngine.h"
#include "TimeSchedule.h"
#include "Miner.h"
#include "Rope.h"

USING_NS_CC;

Scene* firstScene::createScene()
{
	// 'scene' is an autorelease object

	//������������
	auto scene = Scene::createWithPhysics();

	PhysicsWorld *world = scene->getPhysicsWorld();
	//��������Ϊ��
	world->setGravity(Vec2::ZERO);

	// 'layer' is an autorelease object
	auto layer = firstScene::create();

	//����һ���б߽�ĸ��壨��Ļ��
	Size size = Director::getInstance()->getWinSize();

	PhysicsBody *body = PhysicsBody::createEdgeBox(size);
	body->setCategoryBitmask(10);
	body->setCollisionBitmask(10);
	body->setContactTestBitmask(10);

	Node *node = Node::create();
	node->setPosition(size / 2);
	node->setPhysicsBody(body);
	scene->addChild(node);

	// add layer as a child to scene
	scene->addChild(layer);



	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool firstScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object





	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(firstScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width / 1.5, visibleSize.height / 3 + origin.y));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);



	// add "firstScene" splash screen"
	auto sprite1 = Sprite::create("background1.jpg");                                                  //��Ϊ�Լ���ͼƬ

																									   // position the sprite on the center of the screen
	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	Size mywinsize = Director::getInstance()->getWinSize();
	float winw = mywinsize.width; //��ȡ��Ļ���
	float winh = mywinsize.height;//��ȡ��Ļ�߶�
	float spx = sprite1->getTextureRect().getMaxX();
	float spy = sprite1->getTextureRect().getMaxY();
	sprite1->setScaleX(winw / spx); //���þ��������ű���
	sprite1->setScaleY(winh / spy);

	// add the sprite as a child to this layer
	this->addChild(sprite1, 0);



	//����ʱװ��60s

	TimeSchedule * m_timer = TimeSchedule::createTimer(60);
	m_timer->setPosition(650, 450);
	this->addChild(m_timer);

	auto miner = Miner::create();
	addChild(miner);



	auto rope = Rope::create();

	addChild(rope);

	rope->runShakeClaw();
	//��ӷŹ����¼�


	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event*event)
	{

		if (!rope->isRopeChanging()&& keycode== EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			rope->stopAction();
			rope->runRopeThrow();
		}
		//return true;
	};
	//�ַ��¼�
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	//������ײ���¼�������
	auto physicListener = EventListenerPhysicsContact::create();
	physicListener->onContactBegin = [=](PhysicsContact &contact)
	{
		//�����Ӷ���
		rope->runRopePull();

		return true;
	};


	//�ַ��¼�
	_eventDispatcher->addEventListenerWithSceneGraphPriority(physicListener, this);


	return true;


}

void firstScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application

	Director::getInstance()->end();


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);




}