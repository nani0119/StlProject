cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME ALGO)

# 添加动态或者静态链接库路径
link_directories(${PROJECT_BINARY_DIR}/install/lib)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/install/include)

# ======================================================
# 自动包含当前目录代码文件
set(NON_MODIFYING_ALGO_FILE "nonmodifyingalgo.cc")

# 生成可执行文件
add_executable(non_modifying_algo_exe ${NON_MODIFYING_ALGO_FILE})

# 链接库文件
target_link_libraries(non_modifying_algo_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS non_modifying_algo_exe DESTINATION bin)

# ======================================================

set(MODIFYING_ALGO_FILE "modifyingalgo.cc")

add_executable(modifying_algo_exe ${MODIFYING_ALGO_FILE})

target_link_libraries(modifying_algo_exe ${EXTRA_LIBS})

install(TARGETS modifying_algo_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(REMOVING_ALGO_FILE "removingalgo.cc")

# 生成可执行文件
add_executable(removing_algo_exe ${REMOVING_ALGO_FILE})

# 链接库文件
target_link_libraries(removing_algo_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS removing_algo_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(MUTATING_ALGO_FILE "mutatingalgo.cc")

# 生成可执行文件
add_executable(mutating_algo_exe ${MUTATING_ALGO_FILE})

# 链接库文件
target_link_libraries(mutating_algo_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS mutating_algo_exe DESTINATION bin)