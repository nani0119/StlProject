cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME I18N)

# 添加动态或者静态链接库路径
link_directories(${PROJECT_BINARY_DIR}/install/lib)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/install/include)

# ======================================================
# 自动包含当前目录代码文件
set(I18N_LOC_FILE "loc.cc")

# 生成可执行文件
add_executable(i18n_loc_exe ${I18N_LOC_FILE})

# 链接库文件
target_link_libraries(i18n_loc_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS i18n_loc_exe DESTINATION bin)
