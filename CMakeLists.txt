cmake_minimum_required(VERSION 3.24)
project(LuXiang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(DEBUG_SUFFIX)
if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
    set(DEBUG_SUFFIX "d")
endif ()

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64")

set(OPENCV_PREFIX_PATH "C:/opencv4.5.1")

include_directories(
        ${OPENCV_PREFIX_PATH}/include
)

link_directories(
        ${OPENCV_PREFIX_PATH}/lib
)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LuXiang WIN32
        main.cpp)
target_link_libraries(LuXiang
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets

        #        opencv
        opencv_world451${DEBUG_SUFFIX}.lib

        )

if (WIN32)
    # Copy OpenCV dlls
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${OPENCV_PREFIX_PATH}/bin/opencv_world451${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
endif ()
