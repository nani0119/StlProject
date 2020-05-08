cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME CppExample)

# 添加动态或者静态链接库路径
link_directories(${PROJECT_BINARY_DIR}/install/lib)

# 添加链接库
# 静态库
set(EXTRA_LIBS ${EXTRA_LIBS} "util_exception_static")
# 动态库
# set(EXTRA_LIBS ${EXTRA_LIBS} "util_exception")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/install/include)

# 获取全局属性
# get_property(Sales_item_FILE  GLOBAL PROPERTY "Sales_item_FILE") 

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(CppExample_FILE "cppexample.cc")

# 生成可执行文件
add_executable(CppExample ${CppExample_FILE})

# 链接库文件
target_link_libraries(CppExample ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS CppExample DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

