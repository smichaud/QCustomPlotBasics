cmake_minimum_required(VERSION 2.8.11)
project(QCustomPlotBasics)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

QT4_WRAP_UI(UI_SOURCE_FILES ui/mainwindow.ui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_executable(BasicPlot 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot/qcustomplot.cpp
    ${UI_SOURCE_FILES}
    )
target_link_libraries(BasicPlot ${QT_LIBRARIES})
