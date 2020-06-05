cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME REGEX)

# 添加动态或者静态链接库路径
link_directories(${PROJECT_BINARY_DIR}/install/lib)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/install/include)

# ======================================================
# 自动包含当前目录代码文件
set(REGEX_MATCH_AND_SEARCH_FILE "matchandsearch.cc")

# 生成可执行文件
add_executable(regex_match_search_exe ${REGEX_MATCH_AND_SEARCH_FILE})

# 链接库文件
target_link_libraries(regex_match_search_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS regex_match_search_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(REGEX_MATCH_RESULT_FILE "regexmatchresult.cc")

# 生成可执行文件
add_executable(regex_match_result_exe ${REGEX_MATCH_RESULT_FILE})

# 链接库文件
target_link_libraries(regex_match_result_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS regex_match_result_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(REGEX_ITERATOR_FILE "regexiterator.cc")

# 生成可执行文件
add_executable(regex_iterator_exe ${REGEX_ITERATOR_FILE})

# 链接库文件
target_link_libraries(regex_iterator_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS regex_iterator_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(REGEX_ITERATOR_TOKEN_FILE "regexiteratortoken.cc")

# 生成可执行文件
add_executable(regex_iterator_token_exe ${REGEX_ITERATOR_TOKEN_FILE})

# 链接库文件
target_link_libraries(regex_iterator_token_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS regex_iterator_token_exe DESTINATION bin)
# ======================================================
# 自动包含当前目录代码文件
set(REGEX_REPLACE_FILE "regexreplace.cc")

# 生成可执行文件
add_executable(regex_replace_exe ${REGEX_REPLACE_FILE})

# 链接库文件
target_link_libraries(regex_replace_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS regex_replace_exe DESTINATION bin)

# ======================================================
# 自动包含当前目录代码文件
set(REGEX_EXCEPTION_FILE "regexexception.cc")

# 生成可执行文件
add_executable(regex_exception_exe ${REGEX_EXCEPTION_FILE})

# 链接库文件
target_link_libraries(regex_exception_exe ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS regex_exception_exe DESTINATION bin)