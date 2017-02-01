cmake_minimum_required(VERSION 3.1)
project(QCustomPlotBasics)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets PrintSupport)
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5PrintSupport_INCLUDE_DIRS})

QT5_WRAP_UI(UI_SOURCE_FILES ui/mainwindow.ui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_executable(BasicPlot 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot/qcustomplot.cpp
    ${UI_SOURCE_FILES}
    )
target_link_libraries(BasicPlot
    Qt5::Core
    Qt5::Widgets
    Qt5::PrintSupport
    )
