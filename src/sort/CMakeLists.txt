include_directories(${PROJECT_SOURCE_DIR}/3rdparty)
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/PrintSTL)

list(APPEND SORT_SRCS ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

set(TAG sort)
add_executable(${TAG} ${SORT_SRCS})
target_link_libraries(${TAG})