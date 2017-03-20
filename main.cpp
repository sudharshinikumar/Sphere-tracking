#include "TutorialWorld.h"

int main(int argc, char*argv[])
{
	/*	Initialize a new Virtual Environment and pass the necessary parameters 
		to osgVE which are loaded in from the config files found in the release
		folder, the new VR Environment is than ran */
	TutorialWorld* vrenvironment = new TutorialWorld();
	vrenvironment->init(argc, argv);
	vrenvironment->run();

	return 0;
}