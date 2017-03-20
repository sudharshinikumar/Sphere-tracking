#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
using std::cout; using std::endl;
#include "ObjectRegistry.h"
class ObjectRegistry;

class Feedback
{
public:
	Feedback();
	void set_object_registry(ObjectRegistry& registry);
	void update();
	void handleCollision(int tracker, string name);

private:
	ObjectRegistry* _object_registry;
};
#endif
