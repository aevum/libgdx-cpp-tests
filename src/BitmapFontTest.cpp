#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/gl.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/GL10.hpp>
#include <gdx-cpp/graphics/g2d/SpriteBatch.hpp>
#include <gdx-cpp/utils/ApplicationListenerDecorator.hpp>
#include <gdx-cpp/graphics/g2d/BitmapFont.hpp>
#include <gdx-cpp/graphics/glutils/ImmediateModeRenderer10.hpp>



using namespace gdx;

class BitmapFontTest : public gdx::ApplicationListener {
public:
    BitmapFontTest() {
    }
    
    void create() {
        spriteBatch = new SpriteBatch();
        font = BitmapFont::fromFiles(gdx::files->internal("data/verdana39.fnt"), null_shared_ptr(), false);
        renderer = new ImmediateModeRenderer10();
    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
        int viewHeight = gdx::graphics->getHeight();
        
        GL10& gl = *gdx::graphics->getGL10();
        
        gl.glClearColor(1, 1, 1, 1);
        gl.glClear(GL_COLOR_BUFFER_BIT);
        spriteBatch->begin();
        
        std::string text = "Sphinx of black quartz,\njudge my vow.";
        font->setColor(Color::RED);
        
        float x = 20, y = 20;
        float alignmentWidth;
        
        if (true) {
            alignmentWidth = 0;
            font->drawMultiLine(*spriteBatch, text, 200, viewHeight - y, alignmentWidth, BitmapFont::HALIGNMENT_RIGHT);
        }
        
        if (false) {
            BitmapFont::TextBounds& bounds = font->getMultiLineBounds(text);
            alignmentWidth = bounds.width;
            font->drawMultiLine(*spriteBatch, text, x, viewHeight - y, alignmentWidth, BitmapFont::HALIGNMENT_RIGHT);
        }
        
        if (true) {
            alignmentWidth = 280;
            font->drawMultiLine(*spriteBatch, text, x, viewHeight - y, alignmentWidth, BitmapFont::HALIGNMENT_RIGHT);
        }
        
        spriteBatch->end();
        
        drawRect(x, y, x + alignmentWidth, 300);
    }

    void drawRect (float x1, float y1, float x2, float y2) {
        renderer->begin(GL_LINE_STRIP);
        renderer->vertex(x1, y1, 0);
        renderer->vertex(x1, y2, 0);
        renderer->vertex(x2, y2, 0);
        renderer->vertex(x2, y1, 0);
        renderer->vertex(x1, y1, 0);
        renderer->end();
    }
    
    void resize(int width, int height) {
    }
    
    void resume() {
    }
    
private:
    SpriteBatch* spriteBatch;
    BitmapFont* font;
    ImmediateModeRenderer10* renderer;
    
};

void gdxcpp_init(int argc, char** argv) {
    gdxcpp_create_application(new ApplicationListenerDecorator<BitmapFontTest>(), "BitmapFont Test", 640, 480);
}
