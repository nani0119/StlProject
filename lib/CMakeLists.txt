cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME UTIL)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(UTIL_EXCEPTION_FILE "util_exception.cpp")

# 生成动态库
add_library(util_exception SHARED ${UTIL_EXCEPTION_FILE})

# 设置动态版本，VERSION指代动态库版本，SOVERSION指代API版本
# set_target_properties(util_exception PROPERTIES VERSION 1.0 SOVERSION 1)

# 生成静态库
add_library(util_exception_static STATIC ${UTIL_EXCEPTION_FILE})

# 设置静态库与动态库输出同名
set_target_properties (util_exception_static PROPERTIES OUTPUT_NAME "util_exception")

# 安装设置
install(FILES util_exception.h DESTINATION include)
install(TARGETS util_exception util_exception_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)


# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)

set(UTIL_TUBLE_PRINTINCLUDE_DIR ${PROJECT_BINARY_DIR}/install/include)
add_custom_target(util_tupleprint
				  COMMAND  mkdir -p ${UTIL_TUBLE_PRINTINCLUDE_DIR}
				  COMMAND  cp ${CMAKE_CURRENT_SOURCE_DIR}/util_tupleprint.h ${UTIL_TUBLE_PRINTINCLUDE_DIR}	
				  COMMENT "copy util_tupleprint header"
	             )

# 安装设置
install(FILES util_tupleprint.h DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)

set(UTIL_NUMERIC_LIMIT_INFO_DIR ${PROJECT_BINARY_DIR}/install/include)
add_custom_target(UTIL_NUMERIC_LIMIT_INFO
				  COMMAND  mkdir -p ${UTIL_TUBLE_PRINTINCLUDE_DIR}
				  COMMAND  cp ${CMAKE_CURRENT_SOURCE_DIR}/util_numeric_limit_info.h ${UTIL_NUMERIC_LIMIT_INFO_DIR}	
				  COMMENT "copy util_numeric_limit_info  header"
	             )

# 安装设置
install(FILES util_tupleprint.h DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)

set(UTIL_TRAITS_DIR ${PROJECT_BINARY_DIR}/install/include)
add_custom_target(UTIL_TRAITS
				  COMMAND  mkdir -p ${UTIL_TRAITS_DIR}
				  COMMAND  cp ${CMAKE_CURRENT_SOURCE_DIR}/util_type_traits.h ${UTIL_TRAITS_DIR}	
				  COMMENT "copy util_traits  header"
	             )

# 安装设置
install(FILES util_tupleprint.h DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)

set(UTIL_CHRONO_DURATION_DIR ${PROJECT_BINARY_DIR}/install/include)
add_custom_target(UTIL_CHRONO_DURATION
				  COMMAND  mkdir -p ${UTIL_CHRONO_DURATION_DIR}
				  COMMAND  cp ${CMAKE_CURRENT_SOURCE_DIR}/util_chrono_duration.h ${UTIL_CHRONO_DURATION_DIR}	
				  COMMENT "copy util_chrono_duration  header"
	             )

# 安装设置
install(FILES util_chrono_duration.h DESTINATION include)

