cmake_minimum_required(VERSION 3.10)

project(QtCppGuiExample LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIE -no-pie")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fPIE -no-pie")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(QtCppGuiExample SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
  )
else()
  add_executable(QtCppGuiExample
    main.cpp
    mainwindow.cpp
    mainwindow.h
  )
endif()

target_link_libraries(QtCppGuiExample PRIVATE Qt5::Widgets)
install(TARGETS QtCppGuiExample DESTINATION bin)
