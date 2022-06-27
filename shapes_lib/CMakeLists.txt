add_library(shapes_lib STATIC)

target_sources(shapes_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/abstract_shape.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/abstract_canvas.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/canvas.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/circle.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/common.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/pixmap.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/rectangle.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/triangle.hpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/shape.hpp

    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/canvas.cpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/circle.cpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/pixmap.cpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/rectangle.cpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/triangle.cpp
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>/shape.cpp
    )

target_include_directories(shapes_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

# target_link_libraries(shapes
#     PUBLIC
        
# )

# if (${ENABLE_TESTS})
#     add_subdirectory(tests)
# endif()
