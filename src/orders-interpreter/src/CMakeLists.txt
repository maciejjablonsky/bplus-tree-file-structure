set(TARGET_NAME orders_interpreter)
set(SOURCES
    include/orders-interpreter/Orders.hpp
    include/orders-interpreter/Tui.hpp
    Interpreter.cpp
    Interpreter.hpp
    Orders.cpp
    Tui.cpp
)

add_library(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${TARGET_NAME}
    PUBLIC fmt
)
