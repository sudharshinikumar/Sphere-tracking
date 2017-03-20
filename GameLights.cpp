#include "GameLights.h"

GameLights::GameLights(LightManager* lm)
: lightManager(NULL)
	
{
	lightManager = lm;
	
}

GameLights::~GameLights()
{
}

void GameLights::enableLighting()
{
	lightManager->enableLighting();
}

void GameLights::disableLighting()
{
	lightManager->disableLighting();
}


osg::LightSource* GameLights::create()
	 {
		 return lightManager->createLightSource();
      }

void GameLights::set_object_registry(ObjectRegistry &registry)
{
	_object_registry = &registry;
}