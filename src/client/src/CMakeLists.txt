set(TARGET_NAME bplus-client)
set(SOURCES main.cpp)
add_executable(${TARGET_NAME} ${SOURCES})
target_link_libraries(${TARGET_NAME}
    PRIVATE fmt
    PRIVATE cxxopts
)