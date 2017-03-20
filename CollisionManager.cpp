#include "CollisionManager.h"

CollisionManager* CollisionManager::instance()
{
	static CollisionManager* collisionManager = new CollisionManager();
	return collisionManager;
}

CollisionManager::CollisionManager()
:	headTrackerData(NULL),
	leftHandTrackerData(NULL),
	rightHandTrackerData(NULL),
	waistTrackerData(NULL),
	_object_registry(NULL)
{
}

void CollisionManager::update()
{
	osg::Vec3d trackerPosition0(0,0,0), trackerPosition1(0,0,0), trackerPosition2(0,0,0), trackerPosition3(0,0,0);
	if(headTrackerData) { trackerPosition0.set(headTrackerData->x, headTrackerData->y, headTrackerData->z); }
	if(waistTrackerData) { trackerPosition1.set(waistTrackerData->x, waistTrackerData->y, waistTrackerData->z); }
	if(leftHandTrackerData) { trackerPosition2.set(leftHandTrackerData->x, leftHandTrackerData->y, leftHandTrackerData->z); }
	if(rightHandTrackerData) { trackerPosition3.set(rightHandTrackerData->x, rightHandTrackerData->y, rightHandTrackerData->z); }

	vector<VirtualObject*>* objectList = new vector<VirtualObject*>();
	objectList = _object_registry->get_object_manager()->getObjectList();
	VirtualObject* object1 = objectList->at(0);
	VirtualObject* object4 = objectList->at(2);
	if(object1->getBound().intersects(object4->getBound()))
	{
		_object_registry->get_game_sounds()->playSound(TESTCOLLISION2);
		cout << "Detected"<< endl;
	}

	for(unsigned int i = 0; i < objectList->size(); i++)
	{
		if(objectList->at(i)->computeBound().contains(trackerPosition0))
		{
			_object_registry->get_feedback()->handleCollision(0, objectList->at(i)->getName());
		}
		if(objectList->at(i)->computeBound().contains(trackerPosition1))
		{
			_object_registry->get_feedback()->handleCollision(1, objectList->at(i)->getName());
		}
		if(objectList->at(i)->computeBound().contains(trackerPosition2))
		{
			_object_registry->get_feedback()->handleCollision(2, objectList->at(i)->getName());
		}
		if(objectList->at(i)->computeBound().contains(trackerPosition3))
		{
			_object_registry->get_feedback()->handleCollision(3, objectList->at(i)->getName());
		}
	}
}

void CollisionManager::set_object_registry(ObjectRegistry &registry)
{
	_object_registry = &registry;
}

void CollisionManager::setHeadTrackerData(TrackerData* trackerData)
{
	headTrackerData = trackerData;
}

void CollisionManager::setWaistTrackerData(TrackerData* trackerData)
{
	waistTrackerData = trackerData;
}

void CollisionManager::setLeftHandTrackerData(TrackerData* trackerData)
{
	leftHandTrackerData = trackerData;
}

void CollisionManager::setRightHandTrackerData(TrackerData *trackerData)
{
	rightHandTrackerData = trackerData;
}

void CollisionManager::checkCameraCollision(osg::Vec3d cameraPosition)
{
	vector<VirtualObject*>* objectList = new vector<VirtualObject*>();
	objectList = _object_registry->get_object_manager()->getObjectList();

	for(unsigned int i = 0; i < objectList->size(); i++)
	{
		if(objectList->at(i)->computeBound().contains(cameraPosition))
		{
			_object_registry->get_feedback()->handleCollision(0, objectList->at(i)->getName());
		}
	}
}