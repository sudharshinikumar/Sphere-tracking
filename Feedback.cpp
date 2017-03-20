#include "Feedback.h"

Feedback::Feedback()
{
}

void Feedback::set_object_registry(ObjectRegistry &registry)
{
	_object_registry = &registry;
}

void Feedback::update()
{

}

void Feedback::handleCollision(int tracker, string name)
{
	switch(tracker)
	{
	case 0:
	case 1: 
	case 2:
	case 3:
		if(name == "piles")
		{
		_object_registry->get_game_sounds()->playSound(TESTCOLLISION1);
		_object_registry->get_game_lights()->disableLighting();
		cout << "Colliding with: " << name << endl;
		_object_registry->get_game_lights()->enableLighting();
		break;
		}
		
		else if (name == "flowerpot")
		{
        _object_registry->get_game_sounds()->playSound(TESTCOLLISION2);
		cout << "Colliding with: " << name << endl;
		break;
	    }
		
		else if(name == "Cylinder")
		{
		_object_registry->get_game_sounds()->playSound(TESTCOLLISION3);
		cout << "Colliding with: " << name << endl;
		break;
		}
		
		/*else if(name == "box")
		{
		_object_registry->get_game_sounds()->playSound(TESTCOLLISION4);
		_object_registry->get_game_lights()->disableLighting();
		cout << "Colliding with: " << name << endl;
		_object_registry->get_game_lights()->enableLighting();
		break;
		}*/
		
		else if(name == "SimpleSphere")
		{
		_object_registry->get_game_sounds()->playSound(TESTCOLLISION);
		cout << "Colliding with: " << name << endl;
		break;
		}
		
		else if(name == "frame")
		{
		_object_registry->get_game_sounds()->playSound(TESTCOLLISION6);
		_object_registry->get_game_lights()->disableLighting();
		cout << "Colliding with: " << name << endl;
		_object_registry->get_game_lights()->enableLighting();
		break;
		}
	default:
		break;
	}
}

		