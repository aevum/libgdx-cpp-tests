#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/Mesh.hpp>
#include <gdx-cpp/graphics/GL10.hpp>
#include <gdx-cpp/graphics/Texture.hpp>
#include <gdx-cpp/graphics/g2d/SpriteBatch.hpp>
#include <gdx-cpp/utils/ApplicationListenerDecorator.hpp>
#include <gdx-cpp/graphics/g2d/Sprite.hpp>
#include <gdx-cpp/utils/StringConvertion.hpp>
#include <gdx-cpp/gl.hpp>


using namespace gdx;

class SvgBackendTest2 : public gdx::ApplicationListener {
public:
    SvgBackendTest2() {
    }
    
    void create() {
        Pixmap::ptr pixmap = Pixmap::newFromFile(gdx::files->internal("data/boss.svg"));
        texture = Texture::ptr(new Texture(pixmap, false));
        
        sprite = new Sprite(texture);
        sprite->setPosition(0, 0);
        
        spriteBatch = new SpriteBatch();
    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
        gdx::graphics->getGL10()->glClearColor(1, 1, 1, 1);
        gdx::graphics->getGL10()->glClear(GL_COLOR_BUFFER_BIT);
        
        spriteBatch->begin();
        sprite->draw(*spriteBatch);        
        spriteBatch->end();
    }
    
    void resize(int width, int height) {
    }
    
    void resume() {
    }
    
    virtual ~SvgBackendTest2() {
    }
    
private:
    SpriteBatch* spriteBatch;
    Sprite* sprite;
    Texture::ptr texture;
};

void gdxcpp_init(int argc, char** argv) {  
    gdxcpp_create_application(new ApplicationListenerDecorator<SvgBackendTest2>(), "Svg Backend Test 2", 640, 480);
}
