cmake_minimum_required (VERSION 2.6 FATAL_ERROR)

project      (qt_pointcloud)
find_package (PCL 1.8.1 REQUIRED)

include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})

find_package (VTK REQUIRED)
include(${VTK_USE_FILE})

set  (project_SOURCES main.cpp mainwindow.cpp)
set  (project_HEADERS mainwindow.h)
set  (project_FORMS   mainwindow.ui)
set   (VTK_LIBRARIES)

QT5_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT5_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})

ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (qt_pointcloud ${project_SOURCES}
${project_FORMS_HEADERS}
${project_HEADERS_MOC})

TARGET_LINK_LIBRARIES (qt_pointcloud ${PCL_LIBRARIES} ${VTK_LIBRARIES})
qt5_use_modules (qt_pointcloud Widgets)
