#include "ObjectRegistry.h"

ObjectRegistry::ObjectRegistry()
:	_collision_manager(NULL),
	_feedback(NULL),
	_object_manager(NULL),
	_game_sounds(NULL)
{
}

ObjectRegistry::~ObjectRegistry()
{
	if(_collision_manager)
		delete _collision_manager;
	if(_feedback)
		delete _feedback;
	if(_object_manager)
		delete _object_manager;
	if(_game_sounds)
		delete _game_sounds;
}

void ObjectRegistry::register_collision_manager(CollisionManager &cm)
{
	if(_collision_manager)
		delete _collision_manager;
	_collision_manager = & cm;
	_collision_manager->set_object_registry(*this);
}

CollisionManager* ObjectRegistry::get_collision_manager()
{
	return _collision_manager;
}

void ObjectRegistry::register_feedback(Feedback& fb)
{
	if(_feedback)
		delete _feedback;
	_feedback = &fb;
	_feedback->set_object_registry(*this);
}

Feedback* ObjectRegistry::get_feedback()
{
	return _feedback;
}

void ObjectRegistry::register_object_manager(ObjectManager &objmgr)
{
	if(_object_manager)
		delete _object_manager;
	_object_manager = &objmgr;
	_object_manager->set_object_registry(*this);
}

ObjectManager* ObjectRegistry::get_object_manager()
{
	return _object_manager;
}

void ObjectRegistry::register_game_sounds(GameSounds &gamesounds)
{
	if(_game_sounds)
		delete _game_sounds;
	_game_sounds = &gamesounds;
	_game_sounds->set_object_registry(*this);
}

GameSounds* ObjectRegistry::get_game_sounds()
{
	return _game_sounds;
}
void ObjectRegistry::register_game_lights(GameLights &gamelights)
{
	if(_game_lights == NULL)
		delete _game_lights;
	_game_lights = &gamelights;
	_game_lights->set_object_registry(*this);
}
GameLights* ObjectRegistry::get_game_lights()
{
	return _game_lights;
}