#ifndef TUTORIALWORLD_H
#define TUTORIALWORLD_H

#include <osgVirtualEnvironment/VirtualEnvironment.h>
#include <osgVirtualEnvironment/VirtualObject.h>
#include <osg/ShapeDrawable>

#include "ObjectRegistry.h"
#include "CollisionManager.h"
#include "Feedback.h"
#include "ObjectManager.h"
#include "TrackedSphere.h"

class TutorialWorld : public VirtualEnvironment
{
public:
	TutorialWorld();

protected:
	virtual const char* getName() const { return "Tutorial Project"; }
	virtual void create();
	virtual void update();
	virtual void setup();

private:
	ObjectRegistry _object_registry;
	VirtualObject* room;
	TutorialWorld(const TutorialWorld& tutorialworld);
	const TutorialWorld& operator=(const TutorialWorld& tutorialworld);
	TrackedSphere* tracker;
};
#endif
