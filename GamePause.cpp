

#include "GamePause.h"
#include "SimpleAudioEngine.h"
#include "SetObject.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;

USING_NS_CC;

Scene* GamePause::createScene()
{
	// 'scene' is an autorelease object

	//ÉèÖÃÎïÀíÊÀ½ç
	auto scene = Scene::create();
// 'layer' is an autorelease object
	auto layer = GamePause::create();
// add layer as a child to scene
	scene->addChild(layer);
// return the scene
	return scene;
}

// on "init" you need to initialize your instance


bool GamePause::init()
{
//////////////////////////////
// 1. super init first
if (!LayerColor::initWithColor(Color4B(0,0,0,150)))
{
return false;
}

visibleSize = Director::getInstance()->getVisibleSize();
origin = Director::getInstance()->getVisibleOrigin();

goOnButton = MenuItemImage::create(
	"oppopause.jpg",
	"oppopause.jpg",
	CC_CALLBACK_1(GamePause::goOn, this));

goOnButton->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y));
menu = Menu::create(goOnButton, NULL);
menu->setPosition(Vec2::ZERO);
this->addChild(menu, 1);
return true;


}
void GamePause::goOn(Ref*pSender)
{
		_eventDispatcher->dispatchCustomEvent("goOnGame");
	
	
}

