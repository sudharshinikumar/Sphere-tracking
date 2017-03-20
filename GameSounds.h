#ifndef GAMESOUNDS_H
#define GAMESOUNDS_H

#include <osgVirtualEnvironment/Sound.h>
#include <osgVirtualEnvironment/SoundManager.h>
#include <string>
using std::string;
#include <vector>
using std::vector;

#define TESTCOLLISION	0	//Make sure to start at 0 and count up
#define TESTCOLLISION1  1
#define TESTCOLLISION2  2
#define TESTCOLLISION3  3
#define TESTCOLLISION4  4
#define TESTCOLLISION5  5
#define TESTCOLLISION6  6
//... define all sounds that are going to be used

#include "ObjectRegistry.h"
class ObjectRegistry;

class GameSounds
{
public:
	GameSounds(SoundManager* sm);
	~GameSounds();

	void addSound(const string& location);
	void playSound(int soundNumber);
	void loopSound(int soundNumber);
	void stopSound(int soundNumber);

	void set_object_registry(ObjectRegistry& registry);
private:
	ObjectRegistry* _object_registry;
	SoundManager* soundManager;
	vector<Sound*>* soundList;
};
#endif
