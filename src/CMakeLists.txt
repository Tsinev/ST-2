set(header_path "${PROJECT_SOURCE_DIR}/include")
set(header 
    ${header_path}/circle.h 
    ${header_path}/tasks.h
)
set(src 
    circle.cpp 
    tasks.cpp
)
add_library(${PROJECT_NAME} STATIC ${header} ${src})
target_include_directories(${PROJECT_NAME} 
    PUBLIC ${header_path}
)



add_executable(${PROJECT_NAME}.info main.cpp)

target_link_libraries(${PROJECT_NAME}.info ${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION "${lib_dest}")
install(TARGETS ${PROJECT_NAME}.info RUNTIME DESTINATION "${tool_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
