add_executable(tests tests.cpp)

target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(tests 
    ${PROJECT_NAME} 
    GTest::GTest 
    GTest::Main 
    pthread
)




