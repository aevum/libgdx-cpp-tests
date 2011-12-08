cmake_minimum_required(VERSION 2.8)

project(gdx-cpp-tests)

set(GDX_ROOT $ENV{HOME}/dev/)
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

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/tests/)

if (NDK_ROOT)
    set(BUILD_AS_SHARED_LIB TRUE)
else()
    set(BUILD_AS_SHARED_LIB FALSE)
endif()

foreach(APP ${APPLICATIONS})
    get_filename_component(APP_NAME ${APP} NAME)
    if (NOT BUILD_AS_SHARED_LIB)
        add_executable(${APP_NAME} src/${APP}.cpp)
    else()
        add_library(${APP_NAME} SHARED src/${APP}.cpp)
    endif()

    target_link_libraries(${APP_NAME} ${GDXCPP_LIBRARIES})
endforeach()