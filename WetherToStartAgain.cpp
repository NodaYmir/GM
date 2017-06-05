
/*???????????????????????????????????????????????????????????
#include "WetherToStartAgain.h"
#include "SimpleAudioEngine.h"
#include "GameMenu.h"
USING_NS_CC;

Scene* WetherToStartAgain::createScene()
{
	// 'scene' is an autorelease object

	//������������
	auto scene = Scene::createWithPhysics();

	PhysicsWorld *world = scene->getPhysicsWorld();
	//��������Ϊ��
	world->setGravity(Vec2::ZERO);

	// 'layer' is an autorelease object
	auto layer = WetherToStartAgain::create();



	// add layer as a child to scene
	scene->addChild(layer);



	// return the scene
	return scene;
}

// on "init" you need to initialize your instance


bool WetherToStartAgain::init()
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
		CC_CALLBACK_1(WetherToStartAgain::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width / 1.5, visibleSize.height / 3 + origin.y));

	auto continueItem = MenuItemImage::create(
		"continue.jpg",
		"continue.jpg",
		CC_CALLBACK_1(WetherToStartAgain::menuContinueCallback, this));

	continueItem->setPosition(Vec2(origin.x + visibleSize.width / 1.8, visibleSize.height / 3 + origin.y));
	// create menu, it's an autorelease object
	auto menu1 = Menu::create(closeItem, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);

	auto menu2 = Menu::create(continueItem, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 1);

	// add "WetherToStartAgain" splash screen"
	auto sprite1 = Sprite::create("WetherToStartAgain.jpg");                                                  //��Ϊ�Լ���ͼƬ

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


	return true;


}

void WetherToStartAgain::menuContinueCallback(Ref* pSender)
{
	auto director = Director::getInstance();
	CCScene *scene = GameMenu::createScene();
	auto transition = TransitionCrossFade::create(0.5f, scene);
	director->replaceScene(transition);
}
void WetherToStartAgain::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application

	Director::getInstance()->end();


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);

/*????????????????????????????????????????????
}

?????????????????????????????????????*/