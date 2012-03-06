#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/Mesh.hpp>
#include <gdx-cpp/graphics/GL10.hpp>

using namespace gdx_cpp::graphics;
using namespace gdx_cpp;

class BaseApplication : public gdx_cpp::ApplicationListener {
public:
    BaseApplication() {

    }
    
    void create() {
        gdx_cpp::files::FileHandle::ptr file = Gdx::files->internal("data/badlogicsmall.png");

        gdx_cpp::files::FileHandle::buffer_ptr buffer;

        Gdx::app->log("BaseTest", "file size is : %s", file->name().c_str());
        
        int size = file->readBytes(buffer);

        Gdx::app->log("BaseTest", "file size is : %d", size);
        
    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
    }

    void resize(int width, int height) {
    }
    
    void resume() {
    }
private:
};

void gdxcpp_init(int argc, char** argv) {
    gdxcpp_create_application(new BaseApplication, "Base App", 640, 480);
}
