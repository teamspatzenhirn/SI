project(Example)
add_executable(${PROJECT_NAME} example.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ..)
target_link_libraries(${PROJECT_NAME} SI)
