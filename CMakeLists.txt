cmake_minimum_required(VERSION 3.0.0)
project(shapes VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

add_subdirectory(shapes_lib)

add_executable(shapes)
target_link_libraries(shapes shapes_lib)
target_sources(shapes
    PRIVATE
    main.cpp
)




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
