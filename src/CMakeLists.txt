add_subdirectory(config)

# add the executable
add_executable(Todo main.cpp)

target_link_libraries(Todo PUBLIC Config)
target_include_directories(Todo PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/config"
                          )
