cmake_minimum_required(VERSION 3.5)

project(Ti-Care LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Ti-Care
    main.cpp
    Scheduler.cpp
    Scheduler.hpp
    Task.cpp
    Task.hpp
    TaskDebugOutput.cpp
    TaskDebugOutput.hpp
    TaskCheckFile.cpp
    TaskCheckFile.hpp
    Executer.cpp
    Executer.hpp
    resource.qrc
)

target_link_libraries(Ti-Care PRIVATE Qt5::Widgets)
