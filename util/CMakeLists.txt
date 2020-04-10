cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME UTIL)

# 添加动态或者静态链接库路径
link_directories(${PROJECT_BINARY_DIR}/install/lib)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/install/include)

# ======================================================
# 自动包含当前目录代码文件
set(PAIR_FILE "pair.cc")

# 生成可执行文件
add_executable(pair_exe ${PAIR_FILE})

# 链接库文件
target_link_libraries(pair_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS pair_exe DESTINATION bin)

# ======================================================

# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(TUPLE_FILE "tuple.cc")

# 生成可执行文件
add_executable(tuple_exe ${TUPLE_FILE})

# 添加依赖
add_dependencies(tuple_exe util_tupleprint)

# 指定安装的文件信息
install(TARGETS tuple_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(SHAREDPTR_FILE "sharedptr.cc")

# 生成可执行文件
add_executable(sharedptr_exe ${SHAREDPTR_FILE})


# 指定安装的文件信息
install(TARGETS sharedptr_exe DESTINATION bin)