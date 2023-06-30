cmake_minimum_required(VERSION 3.5)
project(PasswordKeep VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp


        startwindow.cpp startwindow.h startwindow.ui

        new_pack.ui new_pack.h new_pack.cpp

        open_pack.h open_pack.cpp open_pack.ui

        mainwindow.cpp mainwindow.h mainwindow.ui

        new_element.h new_element.cpp new_element.ui

        edit_element.h edit_element.cpp edit_element.ui


        SHA256.cpp SHA256.h

        mainwindow_extra.cpp mainwindow_extra.ui mainwindow_extra.h


  )





if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PasswordKeep
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PasswordKeep APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PasswordKeep SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PasswordKeep
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PasswordKeep PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(PasswordKeep PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS PasswordKeep
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PasswordKeep)
endif()
