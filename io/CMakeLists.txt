cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME IO)

# 添加动态或者静态链接库路径
link_directories(${PROJECT_BINARY_DIR}/install/lib)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/install/include)

# ======================================================
# 自动包含当前目录代码文件
set(IO_STATE1_FILE "iostate1.cc")

# 生成可执行文件
add_executable(io_state1_exe ${IO_STATE1_FILE})

# 链接库文件
target_link_libraries(io_state1_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_state1_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(IO_STATE2_FILE "iostate2.cc")

# 生成可执行文件
add_executable(io_state2_exe ${IO_STATE2_FILE})

# 链接库文件
target_link_libraries(io_state2_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_state2_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(IO_STATE3_FILE "iostate3.cc")

# 生成可执行文件
add_executable(io_state3_exe ${IO_STATE3_FILE})

# 链接库文件
target_link_libraries(io_state3_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_state3_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(IO_STATE_EXCEPTION_FILE "iostateexception.cc")

# 生成可执行文件
add_executable(io_state_exception_exe ${IO_STATE_EXCEPTION_FILE})

# 链接库文件
target_link_libraries(io_state_exception_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_state_exception_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(IO_MEMBER_FUNCTION_FILE "iomemberfunction.cc")

# 生成可执行文件
add_executable(io_member_function_exe ${IO_MEMBER_FUNCTION_FILE})

# 链接库文件
target_link_libraries(io_member_function_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_member_function_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(IO_MANIPULATOR_FILE "iomanipulator.cc")

# 生成可执行文件
add_executable(io_manipulator_exe ${IO_MANIPULATOR_FILE})

# 链接库文件
target_link_libraries(io_manipulator_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_manipulator_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(IO_FORMATTING_FILE "ioformatting.cc")

# 生成可执行文件
add_executable(io_formatting_exe ${IO_FORMATTING_FILE})

# 链接库文件
target_link_libraries(io_formatting_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_formatting_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(IO_FSTREAM_FILE "iofstream.cc")

# 生成可执行文件
add_executable(io_fstream_exe ${IO_FSTREAM_FILE})

# 链接库文件
target_link_libraries(io_fstream_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_fstream_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(IO_USERDEFINED_FILE "iouserdefined.cc")

# 生成可执行文件
add_executable(io_userdefined_exe ${IO_USERDEFINED_FILE})

# 链接库文件
target_link_libraries(io_userdefined_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS io_userdefined_exe DESTINATION bin)