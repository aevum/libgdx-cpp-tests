#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/Log.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/Mesh.hpp>
#include <gdx-cpp/graphics/GL10.hpp>


using namespace gdx;

class BaseApplication : public gdx::ApplicationListener {
public:
    BaseApplication() {

    }
    
    void create() {
        gdx::FileHandle::ptr file = gdx::files->internal("data/badlogicsmall.png");

        gdx::FileHandle::buffer_ptr buffer;

        gdx_log_debug("BaseTest", "file size is : %s", file->name().c_str());
        
        int size = file->readBytes(buffer);

        gdx_log_debug("BaseTest", "file size is : %d", size);
        
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
