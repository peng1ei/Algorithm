include_directories(${PROJECT_SOURCE_DIR}/3rdparty)
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/PrintSTL)

option(TEST_GENERATE_RANDOM "test generate random array" OFF)
option(TEST_SELECTION_SORT "test selection sort" OFF)
option(TEST_INSERTION_SORT "test insertion sort" OFF)
option(TEST_BUBBLE_SORT "test bubble sort" ON)

if(TEST_GENERATE_RANDOM)
    add_definitions(-DTEST_GENERATE_RANDOM)
endif()

if(TEST_SELECTION_SORT)
    add_definitions(-DTEST_SELECTION_SORT)
endif()

if(TEST_INSERTION_SORT)
    add_definitions(-DTEST_INSERTION_SORT)
endif()

if(TEST_BUBBLE_SORT)
    add_definitions(-DTEST_BUBBLE_SORT)
endif()

list(APPEND SORT_SRCS ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

set(TAG sort)
add_executable(${TAG} ${SORT_SRCS})
target_link_libraries(${TAG})