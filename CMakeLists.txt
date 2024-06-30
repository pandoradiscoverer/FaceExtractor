cmake_minimum_required(VERSION 3.10)
project(FaceDetection)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(dlib REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
    main.cpp
    mainwindow.cpp
)

set(HEADERS
    mainwindow.h
)

set(UIS
    mainwindow.ui
)

add_executable(FaceDetection ${SOURCES} ${HEADERS} ${UIS})
target_link_libraries(FaceDetection ${OpenCV_LIBS} dlib::dlib Qt5::Widgets)
