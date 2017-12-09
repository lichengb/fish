#include "AppDelegate.h"
#include "GameScene.h"
#include "GameMenuLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    
    //±³¾°
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);

    pDirector->setDisplayStats(true);

    pDirector->setAnimationInterval(1.0 / 60);

    CCScene *pScene = GameScene::create();

    pDirector->runWithScene(pScene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
