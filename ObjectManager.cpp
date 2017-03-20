#include "Objectmanager.h"
#include <osg/PositionAttitudeTransform>

ObjectManager::ObjectManager(osg::Group *root)
:	objectGroup(new osg::Group()),
	objectList(new vector<VirtualObject*>())
{
	root->addChild(objectGroup);
}

void ObjectManager::set_object_registry(ObjectRegistry &registry)
{
	_object_registry = &registry;
}

void ObjectManager::update()
{
	objPosition += osg::Vec3(-1,-1,0);
	object8->setPosition(objPosition);
	objPosition1 += osg::Vec3(0,1,0);
	object1->setPosition(objPosition1);
}

void ObjectManager::createObjects()
{
	// Creates a simple sphere primitive
	object1 = new VirtualObject();
	osg::Geode* geode = new osg::Geode();
	osg::ShapeDrawable* sd = new osg::ShapeDrawable(new osg::Sphere(osg::Vec3d(0.0, 0.0, 0.0), 10));
	geode->addDrawable(sd);
	object1->setModel(geode);

	//osg::BoundingSphere* bs = object1->getBound();
	objPosition1 = osg::Vec3(200,25,-30);
	object1->setPosition(objPosition1);
	osg::Texture2D* texture = new osg::Texture2D();
	texture->setImage(osgDB::readImageFile("Images/texture4.jpg"));
	object1->setTexture(texture);
	object1->setName("SimpleSphere");
	// Must add to the objectGroup as this attaches the node to the render tree
	objectGroup->addChild(object1);
	// Only add to list if you want to check collisions on the object as this list is what is passed
	// on to the CollisionManager
	objectList->push_back(object1);	
	objPosition = osg::Vec3d(270, 500,20);	
    object8 = new VirtualObject("Models/plane.dae");
	object8->setPosition(objPosition);
	objectGroup->addChild(object8);
	object8->setName("plane");
	objectList->push_back(object8);

	VirtualObject* object4 = new VirtualObject("Models/piles.dae");
	object4->setPosition(osg::Vec3d(120,  350,-50 ));
	objectGroup->addChild(object4);
	object4->setName("piles");
	objectList->push_back(object4);
	/*VirtualObject* object11 = new VirtualObject("Models/lamp.dae");
    object11->setScale(osg::Vec3(5.0, 5.0, 5.0));
    object11->setPosition(osg::Vec3d(5.0,120.0,0));
objectGroup->addChild(object11);
object11->setName("lamp");
objectList->push_back(object11);*/


	
	GameLights* gamelights = _object_registry->get_game_lights();
	gamelights->enableLighting();
    osg::LightSource* lightsource = gamelights->create();
	lightsource->getLight()->setAmbient(Vec4(0.8, 0.8, 0.8, 1.0));
	lightsource->getLight()->setDiffuse(Vec4(0.6, 0.6, 0.6, 1.0));
	lightsource->getLight()->setPosition(Vec4(20.0, 20.0, 70.0, 1.0));
	object1->addChild(lightsource);
}
