#include "GameSounds.h"

GameSounds::GameSounds(SoundManager* sm)
:	soundManager(NULL),
	soundList(NULL)
{
	soundManager = sm;
	soundList = new vector<Sound*>();
}

GameSounds::~GameSounds()
{
}

void GameSounds::addSound(const std::string &location)
{
	soundList->push_back(soundManager->create2DSound(location));
}

void GameSounds::playSound(int soundNumber)
{
	soundList->at(soundNumber)->play();
}

void GameSounds::loopSound(int soundNumber)
{
	soundList->at(soundNumber)->loop();
}

void GameSounds::stopSound(int soundNumber)
{
	soundList->at(soundNumber)->stop();
}

void GameSounds::set_object_registry(ObjectRegistry &registry)
{
	_object_registry = &registry;
}