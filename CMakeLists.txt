cmake_minimum_required(VERSION 3.12)
project(StudentSystem)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    
)

include_directories(include)
# # 添加源文件
# set(SOURCES
#     main.cpp
#     student.cpp
#     course.cpp
# )

# 添加可执行文件
add_executable(StudentSystem ${SOURCES})