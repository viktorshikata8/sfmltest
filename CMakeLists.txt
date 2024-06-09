cmake_minimum_required(VERSION 3.28)
project(sfmltest)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp
        src/sfml.h
        src/sfml.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND_EXPAND_LISTS
    )
endif()
