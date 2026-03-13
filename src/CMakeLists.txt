set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header 
    ${header_path}/circle.h
    ${header_path}/tasks.h
)
set(src 
    circle.cpp
    tasks.cpp
)
add_library(${PROJECT_NAME} STATIC ${src} ${header})
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${header_path}
)

target_link_libraries(${PROJECT_NAME} pthread)

add_executable(${PROJECT_NAME}.info main.cpp)

target_link_libraries(${PROJECT_NAME}.info ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION "${lib_dest}" ARCHIVE DESTINATION "${lib_dest}")
install(TARGETS ${PROJECT_NAME}.info RUNTIME DESTINATION "${tool_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
