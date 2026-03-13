add_executable(${PROJECT_NAME}.test AllTests.cpp tests.cpp)



target_link_libraries(${PROJECT_NAME}.test
    PRIVATE
        ${PROJECT_NAME}
        gtest
        pthread
)




