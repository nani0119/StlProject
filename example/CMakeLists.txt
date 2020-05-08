cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME Chapter3)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/CppExample)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QtCppConsoleExample)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QtCppExample)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QtCppGuiExample)

# 添加子目录
add_subdirectory(CppExample)
add_subdirectory(QtCppConsoleExample)
add_subdirectory(QtCppExample)
add_subdirectory(QtCppGuiExample)


