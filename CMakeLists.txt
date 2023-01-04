cmake_minimum_required (VERSION 3.5)

project (HelloWorld)

# CMAKE_CXX_FLAGXS 编译标志
# -Wall 显示所有警告
# -Werror 显示所有错误
# -std=c++11 所使用的标准库(c++11) 
set (CMAKE_CXX_FLAGXS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11")
# source_dir 源文件目录 
# PROJECT_SOURCE_DIR 当前目录
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

# 使用GLOB表示哪些文件需要编译
# source_dir目标下所有的.cpp文件
file (GLOB source_files "${source_dir}/*.cpp")

# add_executable 目标可执行文件设定
# HelloWorld 项目名
# source_files 想传入该项目中的文件(将是源文件)
add_executable (HelloWorld ${source_files})
