//
//  Generated by StarUML(tm) C++ Add-In
//  @ Project : 211506372
//  @ File Name : StaticData.cpp
//  @ Date : 2017/12/05
//  @ Author : lichengbin


#include "StaticData.h"
static StaticData* g_sharedStaticData = NULL;

StaticData* StaticData::sharedStaticData() {
if (g_sharedStaticData == NULL) {
		g_sharedStaticData = new StaticData();
		g_sharedStaticData->init();
	}
	return g_sharedStaticData;

}

void StaticData::purge() {
	CC_SAFE_RELEASE_NULL(g_sharedStaticData);
}

int StaticData::intValueForKey(const std::string &key) {
	return _dictionary->valueForKey(key)-> floatValue ();
}

const char* StaticData::stringValueFromKey(const std::string &key) {
	return _dictionary->valueForKey(key)->getCString();
}

float StaticData::floatValueFromKey(const std::string &key) {
	return _dictionary->valueForKey(key)->floatValue();
}

bool StaticData::booleanFromKey(const std::string &key) {
	return _dictionary->valueForKey(key)-> boolValue ();
}

cocos2d::CCPoint StaticData::pointFromKey(const std::string &key) {
	return CCPointFromString(_dictionary->valueForKey(key)->getCString());
}

cocos2d::CCRect StaticData::rectFromKey(const std::string &key) {
	return CCRectFromString(_dictionary->valueForKey(key)->getCString());

}

cocos2d::CCSize StaticData::sizeFormKey(const std::string &key) {
	return CCSizeFromString(_dictionary->valueForKey(key)->getCString());
}

bool StaticData::init() {
	_dictionary = CCDictionary::createWithContentsOfFile(_staticFileName.c_str());
	_dictionary->retain();
	return true;

}

StaticData::~StaticData() {
	CC_SAFE_RELEASE_NULL(_dictionary);
}

StaticData::StaticData() {
	_staticFileName = STATIC_DATA_FILENAME;
}


