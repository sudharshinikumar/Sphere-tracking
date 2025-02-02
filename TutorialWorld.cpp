#include "TutorialWorld.h"
using namespace osg;

/***************************************************************
Three functions are required to by osgVE to initalize and update
throughout the duration of the program these are create, setup 
and update, these must be included in any program that uses osgVE
****************************************************************/
TutorialWorld::TutorialWorld()
{
	// The room model is 165"x168", all units in osgVE are measured in inches
	room = new VirtualObject("Models/terrain.dae");
	room->setPosition(Vec3(-400,-300,-100));
	CollisionManager* cm = new CollisionManager();
	_object_registry.register_collision_manager(*cm);
	Feedback* fb = new Feedback();
	_object_registry.register_feedback(*fb);
	ObjectManager* om = new ObjectManager(root);
	_object_registry.register_object_manager(*om);
	GameSounds* gamesounds = new GameSounds(soundManager);
	_object_registry.register_game_sounds(*gamesounds);
	GameLights* gamelights = new GameLights(lightManager);
	_object_registry.register_game_lights(*gamelights);

	tracker = new TrackedSphere(osg::Vec4(1,0,0,1.0));
	/*osg::Geode* vo = new Geode();
	osg::ShapeDrawable* sd = new osg::ShapeDrawable(new osg::Sphere(osg::Vec3d(0.0,0.0,0.0), 1));
	vo->addDrawable(sd);
	room->addChild(vo);*/
}

void TutorialWorld::create()
{
	root->addChild(room);
	
	GameLights* gamelights = _object_registry.get_game_lights();
    lightManager->enableLighting();
	camera->setLookAt(Vec3d(25.0, 25.0, 65.0), Vec3d(50.0, 50.0, 65.0), Vec3d(0.0, 0.0, 1.0));

	_object_registry.get_object_manager()->createObjects();

	root->addChild(tracker);
	//Add new sounds here, First define in GameSounds.h then add to bottom of list
	GameSounds* gamesounds = _object_registry.get_game_sounds();
	gamesounds->addSound("Sounds/testCollision.wav");		//0
	gamesounds->addSound("Sounds/testCollision1.wav");      //woooo
	gamesounds->addSound("Sounds/testCollision2.wav");      //Dnttouchme
	gamesounds->addSound("Sounds/testCollision3.wav");      //doyoulikeit
	gamesounds->addSound("Sounds/testCollision4.wav");      //cheering
	gamesounds->addSound("Sounds/testCollision5.wav");      //evlaugh


	gamesounds->addSound("Sounds/testCollision6.wav");      //welcome
}

void TutorialWorld::setup()
{
	if(pluginManager->getTrackerPlugin()->loaded())
	{
		CollisionManager* cm = _object_registry.get_collision_manager();
		cm->setHeadTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(0));
		cm->setWaistTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(1));
		cm->setLeftHandTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(2));
		cm->setRightHandTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(3));
	}
	if(VRSettings::instance()->getHeadTrackingEnabled()){
		tracker->setTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(2));
	}

}

void TutorialWorld::update()
{
	_object_registry.get_collision_manager()->update();
	_object_registry.get_object_manager()->update();
	_object_registry.get_feedback()->update();
	if(true) //Only set true if you want to test collisions with the camera, ie for testing only
	{
		_object_registry.get_collision_manager()->checkCameraCollision(camera->getPosition());

	}
	if(VRSettings::instance()->getHeadTrackingEnabled()){
		tracker->setNavTransformAttitude(((InteractiveManipulator*)camera.get())->getNavOrientation());
		tracker->setNavTransformPosition(((InteractiveManipulator*)camera.get())->getNavPosition());
		tracker->update();
	}
}