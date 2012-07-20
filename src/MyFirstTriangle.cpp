#include <gdx-cpp/Gdx.hpp>
#include <gdx-cpp/gl.hpp>
#include <gdx-cpp/Application.hpp>
#include <gdx-cpp/ApplicationListener.hpp>
#include <gdx-cpp/graphics/Mesh.hpp>
#include <gdx-cpp/graphics/GL10.hpp>


using namespace gdx;

class MyFirstTriangleApplication : public gdx::ApplicationListener {
public:
    MyFirstTriangleApplication() : mesh(0) , renderCount(0) {
        std::vector< VertexAttribute > attributes;
        attributes.push_back(VertexAttribute(VertexAttributes::Usage::Position, 3, "a_position"));

        mesh = new Mesh(true, 3, 3, attributes);

        std::vector<float> vertices;
        vertices.push_back(-0.5f);
        vertices.push_back(-0.5f);
        vertices.push_back(0);
        vertices.push_back(0.5f);
        vertices.push_back(-0.5f);
        vertices.push_back(0);
        vertices.push_back(0);
        vertices.push_back(0.5f);
        vertices.push_back(0);
        
        mesh->setVertices(vertices);
        
        std::vector<short int> vi;

        vi.push_back(0);
        vi.push_back(1);
        vi.push_back(2);
        
        mesh->setIndices(vi);
    }
    
    void create() {

    }
    
    void dispose() {
    }
    
    void pause() {
    }
    
    void render() {
        renderCount++;
        gdx_log_debug("RenderCountTest","%d", renderCount);
        gdx::gl10->glClear(GL_COLOR_BUFFER_BIT);
        mesh->render(GL_TRIANGLES, 0, 3);
        
    }

    void resize(int width, int height) {

    }
    
    void resume() {
    }
private:
    gdx::Mesh* mesh;
    int renderCount;
};

void gdxcpp_init(int argc, char** argv) {
    gdxcpp_create_application(new MyFirstTriangleApplication, "My first triangle", 640, 480);
}
