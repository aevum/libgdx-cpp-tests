#include <gdx-cpp/math/EarClippingTriangulator.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <Box2D/Box2D.h>
#include <gdx-cpp/physics/box2d/Box2DDebugRenderer.hpp>
#include <gdx-cpp/graphics/OrthographicCamera.hpp>
#include <gdx-cpp/utils/ApplicationListenerDecorator.hpp>

class EarClippingTriangulatorTest : public gdx::ApplicationListener {
public:
    EarClippingTriangulatorTest()
        : world(b2Vec2(0,0)),
          camera(32, 48)
    {
        std::vector < gdx::Vector2 > vertices;
        
        vertices.push_back(gdx::Vector2(141.1,21));
        vertices.push_back(gdx::Vector2(141.4,20));
        vertices.push_back(gdx::Vector2(256.05,20));
        vertices.push_back(gdx::Vector2(256.05,255.95));
        vertices.push_back(gdx::Vector2(135.85,255.95));
        vertices.push_back(gdx::Vector2(136,228.45));
        vertices.push_back(gdx::Vector2(135,209.35));
        vertices.push_back(gdx::Vector2(140,188.45));
        vertices.push_back(gdx::Vector2(142.85,149.1));
        vertices.push_back(gdx::Vector2(140.4,133.45));
        vertices.push_back(gdx::Vector2(139,113.45));
        vertices.push_back(gdx::Vector2(141.5,68.05));
        vertices.push_back(gdx::Vector2(141,31.45));

        gdx::EarClippingTriangulator triangulator;
        
        std::vector< gdx::Vector2 > computed = triangulator.computeTriangles(vertices);

        std::vector< b2Vec2 > b2computed;

        b2BodyDef bdef;
        bdef.position.Set(16, 24);
        b2Body* body = world.CreateBody(&bdef);
        
        for(int  i = 0; i < computed.size(); ++i) {
            b2computed.push_back(b2Vec2(computed[i].x, computed[i].y));
        }

        for(int  i = 0; i < computed.size(); i += 3) {
            b2PolygonShape polygon;
            polygon.Set(&b2computed[i], 3);
            body->CreateFixture(&polygon, 1);
        }
    }
    
    void create() {
        
    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
        world.Step(gdx::system->nanoTime(), 3, 3);
        camera.update();
        renderer.render(world, camera.combined);
    }
    
    void resize(int width, int height) {
        
    }
    
    void resume() {
    }
    
private:
    b2World world;
    gdx::Box2DDebugRenderer renderer;
    gdx::OrthographicCamera camera;
    
};

void gdxcpp_init(int arcg, char** argv) {
    gdxcpp_create_application(new gdx::ApplicationListenerDecorator<EarClippingTriangulatorTest>(), "EarClippingTriangulator test", 640, 480);
}
