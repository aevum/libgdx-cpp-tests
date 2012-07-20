#include <gdx-cpp/Gdx.hpp>
#include "Box2DTest.cpp"
#include "Box2D/Box2D.h"


using namespace gdx;

class BaseApplication : public Box2DTest {
public:
    void createWorld (b2World& world) {
    }
private:
};

void gdxcpp_init(int argc, char** argv) {
    createApplication(new BaseApplication, "BaseApplication test", 640, 480);
}
