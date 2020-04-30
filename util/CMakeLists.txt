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

# ======================================================
# 自动包含当前目录代码文件
set(WEAKPTR_FILE "weakptr.cc")

# 生成可执行文件
add_executable(weakptr_exe ${WEAKPTR_FILE})

# 指定安装的文件信息
install(TARGETS weakptr_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(UNIQUEPTR_FILE "uniqueptr.cc")

# 生成可执行文件
add_executable(uniqueptr_exe ${UNIQUEPTR_FILE})

# 指定安装的文件信息
install(TARGETS uniqueptr_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(NUMERIC_LIMIT_FILE "numericlimit.cc")

# 生成可执行文件
add_executable(numeric_limit_exe ${NUMERIC_LIMIT_FILE})

# 指定安装的文件信息
install(TARGETS numeric_limit_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(TYPE_TRAITS_FILE "typetraits.cc")

# 生成可执行文件
add_executable(type_traits_exe ${TYPE_TRAITS_FILE})

# 指定安装的文件信息
install(TARGETS type_traits_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(FUNCTION_WRAPPER_FILE "functionwrapper.cc")

# 生成可执行文件
add_executable(function_wrapper_exe ${FUNCTION_WRAPPER_FILE})

# 指定安装的文件信息
install(TARGETS function_wrapper_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(REFERENCE_WRAPPER_FILE "referencewrapper.cc")

# 生成可执行文件
add_executable(reference_wrapper_exe ${REFERENCE_WRAPPER_FILE})

# 指定安装的文件信息
install(TARGETS reference_wrapper_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(AUXILIARY_FUNCTION_FILE "auxiliaryfunction.cc")

# 生成可执行文件
add_executable(auxiliary_function_exe ${AUXILIARY_FUNCTION_FILE})

# 指定安装的文件信息
install(TARGETS auxiliary_function_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(RATIO_FILE "ratio.cc")

# 生成可执行文件
add_executable(ratio_exe ${RATIO_FILE})

# 指定安装的文件信息
install(TARGETS ratio_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(CHRONO_FILE "chrono.cc")

# 生成可执行文件
add_executable(chrono_exe ${CHRONO_FILE})

# 指定安装的文件信息
install(TARGETS chrono_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(CSTD_FILE "cstd.cc")

# 生成可执行文件
add_executable(cstd_exe ${CSTD_FILE})

# 指定安装的文件信息
install(TARGETS cstd_exe DESTINATION bin)
