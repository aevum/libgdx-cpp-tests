#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/gl.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/Mesh.hpp>
#include <gdx-cpp/graphics/GL10.hpp>
#include <gdx-cpp/graphics/Texture.hpp>
#include <gdx-cpp/graphics/g2d/SpriteBatch.hpp>
#include <gdx-cpp/utils/ApplicationListenerDecorator.hpp>

using namespace gdx;

class AlphaTest : public gdx::ApplicationListener {
public:
    AlphaTest() {
    }
    
    void create() {
        Pixmap::ptr pixmap = Pixmap::newFromRect(256, 256, Pixmap::Format::RGBA8888, Pixmap::Gdx2d);
        pixmap->setColor(0, 1, 0, 0.7f);
        pixmap->fill();
        
        spriteBatch = new SpriteBatch();
        texture = Texture::ptr(new Texture(pixmap, false));
        texture->setFilter(Texture::TextureFilter::Linear, Texture::TextureFilter::Linear);
    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
        gdx::graphics->getGL10()->glClear(GL_COLOR_BUFFER_BIT);
        
        spriteBatch->begin();
        spriteBatch->draw(*texture, 0, 0, 256, 256, 0, 0, 256, 256, false, false);
        spriteBatch->end();
    }
    
    void resize(int width, int height) {
    }
    
    void resume() {
    }
    
private:
    SpriteBatch* spriteBatch;
    Texture::ptr texture;
};

void gdxcpp_init(int argc, char** argv) {
    gdxcpp_create_application(new ApplicationListenerDecorator<AlphaTest>(), "Alpha Test", 640, 480);
}
