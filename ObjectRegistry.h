#ifndef OBJECTREGISTRY
#define OBJECTREGISTRY

#include "CollisionManager.h"
class CollisionManager;
#include "Feedback.h"
class Feedback;
#include "ObjectManager.h"
class ObjectManager;
#include "GameSounds.h"
class GameSounds;
#include "GameLights.h"
class GameLights;

class ObjectRegistry
{
public:
	ObjectRegistry();
	~ObjectRegistry();

	void register_collision_manager(CollisionManager& cm);
	CollisionManager* get_collision_manager();

	void register_feedback(Feedback& fb);
	Feedback* get_feedback();

	void register_object_manager(ObjectManager& objmgr);
	ObjectManager* get_object_manager();

	void register_game_sounds(GameSounds& gamesounds);
	GameSounds* get_game_sounds();

	void register_game_lights(GameLights& gamelights);
	GameLights* get_game_lights();

private:
	CollisionManager* _collision_manager;
	Feedback* _feedback;
	ObjectManager* _object_manager;
	GameSounds* _game_sounds;
	GameLights* _game_lights;

	ObjectRegistry(const ObjectRegistry& registry);
	ObjectRegistry& operator=(const ObjectRegistry& registry);
};
#endif