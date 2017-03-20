#ifndef GAMELIGHTS_H
#define GAMELIGHTS_H

#include <osgVirtualEnvironment/LightManager.h>
#include <string>
using std::string;


#include "ObjectRegistry.h"
class ObjectRegistry;

class GameLights
{
public:
	GameLights(LightManager* lm);
	~GameLights();

	void enableLighting();
	void disableLighting();
	osg::LightSource* create();	

	void set_object_registry(ObjectRegistry& registry);
private:
	ObjectRegistry* _object_registry;
	LightManager* lightManager;
};
#endif
