#ifndef LIGHT_MANAGER
#define LIGHT_MANAGER

#include <vector>
using std::vector;
#include <osg/LightSource>
#include <osg/Light>

class LightManager {
public:
    
	enum LIGHTNUMBER{
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT
    };
    
   
    LightManager();
    
      ~LightManager() {}
   
    void init(osg::Group * root);

     
  osg::Light* getOrCreateLight(LightManager::LIGHTNUMBER number);
    
private:
    osg::Group * groupOfLights;
       vector<osg::LightSource*>   lights;
       
    bool valid;
};
#endif
