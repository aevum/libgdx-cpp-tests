#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/Mesh.hpp>
#include <gdx-cpp/graphics/GL10.hpp>
#include <gdx-cpp/graphics/Texture.hpp>
#include <gdx-cpp/graphics/g2d/SpriteBatch.hpp>



using namespace gdx;

class DeltaTimeTest : public gdx::ApplicationListener {
public:
    DeltaTimeTest() {
    }
    
    void create() {
        lastFrameTime = gdx::system->nanoTime();
    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
        long frameTime = gdx::system->nanoTime();
        float deltaTime = (frameTime - lastFrameTime) / 1000000000.0f;
        lastFrameTime = frameTime;
        
        gdx_log_debug("DeltaTimeTest", "delta: %f, gdx delta: %f" , deltaTime , gdx::graphics->getDeltaTime());
    }
    
    void resize(int width, int height) {
    }
    
    void resume() {
    }
private:
    uint64_t lastFrameTime;
};

void gdxcpp_init(int argc, char** argv) {
    gdxcpp_create_application(new DeltaTimeTest, "Delta Time Test", 640, 480);
}
