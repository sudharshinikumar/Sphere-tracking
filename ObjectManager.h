#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <osgVirtualEnvironment/VirtualEnvironment.h>
#include <osgVirtualEnvironment/VirtualObject.h>
#include <osg/ShapeDrawable>
#include <vector>
using std::vector;

#include "ObjectRegistry.h"
class ObjectRegistry;

class ObjectManager
{
public:
	ObjectManager(osg::Group* root);
	void set_object_registry(ObjectRegistry& registry);

	void update();
	void createObjects();
	vector<VirtualObject*>* getObjectList() const { return objectList; }

private:
	ObjectRegistry* _object_registry;

	osg::Group* objectGroup;
	vector<VirtualObject*>* objectList;

	VirtualObject* object8;
	VirtualObject* object1;
	osg::Vec3 objPosition;
	osg::Vec3 objPosition1;
};
#endif
 