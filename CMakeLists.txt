cmake_minimum_required(VERSION 2.8)

project(gdx-cpp-tests)

LIST(APPEND CMAKE_MODULE_PATH ${GDX_ROOT}/share/gdx/cmake)

set(GdxCpp_USE_BOX2D TRUE)
find_package(GdxCpp)
include_directories(${GDXCPP_INCLUDE_DIR})

set(APPLICATIONS MyFirstTriangle
    SpriteBatchTest
    PixmapTest
    SpriteCacheTest
    AlphaTest
    DeltaTimeTest
    SpritePerformanceTest
    ParticleEmitterTest
    SoundTest
    SvgBackendTest
    SvgBackendTest2
    BitmapFontTest
    BitmapFontFlipTest
    BaseTest
    EarClippingTriangulatorTest
    box2d/Chain box2d/ApplyForce
    box2d/Bridge box2d/Cantilever
    box2d/CharacterCollision
    box2d/CollisionFiltering
    box2d/ContinuousTest
    box2d/DebugRendererTest
    box2d/OneSidedPlatform
    box2d/Prismatic
    box2d/Pyramid
    box2d/SimpleTest
    box2d/SphereStack
    box2d/VaryingRestitution
    box2d/VerticalStack)

foreach(APP ${APPLICATIONS})
    get_filename_component(APP_NAME ${APP} NAME)
    gdx_setup_target(${APP_NAME} EXECUTABLE src/${APP}.cpp "")
    target_link_libraries(${APP_NAME} ${GDXCPP_LIBRARIES} pthread rt)
endforeach()
