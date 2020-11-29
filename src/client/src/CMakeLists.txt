set(TARGET_NAME bplus-client)
set(SOURCES main.cpp)
add_executable(${TARGET_NAME} ${SOURCES})
target_link_libraries(${TARGET_NAME}
    PRIVATE fmt
    PRIVATE cxxopts
    PRIVATE orders_interpreter
)

set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)
