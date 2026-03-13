add_executable(${PROJECT_NAME}.test tests.cpp)
target_include_directories(${PROJECT_NAME}.test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.test 
    ${PROJECT_NAME} 
    GTest::GTest 
    GTest::Main 
    pthread
)




