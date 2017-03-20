#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <osgVirtualEnvironment/VirtualEnvironment.h>
#include <osgVirtualEnvironment/PluginInterface.h>
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

#include "ObjectRegistry.h"
class ObjectRegistry;

class CollisionManager
{
public:
	static CollisionManager* instance();
	CollisionManager();
	void set_object_registry(ObjectRegistry& registry);

	void update();
	void checkCameraCollision(osg::Vec3d cameraPosition);
	void setHeadTrackerData(TrackerData* trackerData);
	void setLeftHandTrackerData(TrackerData* trackerData);
	void setRightHandTrackerData(TrackerData* trackerData);
	void setWaistTrackerData(TrackerData* trackerData);

private:
	ObjectRegistry* _object_registry;

	TrackerData* headTrackerData;
	TrackerData* waistTrackerData;
	TrackerData* leftHandTrackerData;
	TrackerData* rightHandTrackerData;	
};

#endif