cmake_minimum_required(VERSION 3.1)
project(QCustomPlotBasics)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets PrintSupport)
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5PrintSupport_INCLUDE_DIRS})

QT5_WRAP_UI(UI_SOURCE_FILES ui/mainwindow.ui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(example_qcustomplot 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/example_qcustomplot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot/qcustomplot.cpp
    ${UI_SOURCE_FILES}
    )
target_link_libraries(example_qcustomplot
    Qt5::Core
    Qt5::Widgets
    Qt5::PrintSupport
    )

find_package(Boost REQUIRED COMPONENTS system iostreams)
include_directories(Boost_INCLUDE_DIRS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gnuplot-iostream)
add_executable(example_gnuplot 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/example_gnuplot.cpp
    )
target_link_libraries(example_gnuplot
    ${Boost_LIBRARIES}
    )

