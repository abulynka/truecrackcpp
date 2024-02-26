set(BINARY ${CMAKE_PROJECT_NAME}_test)

include_directories(../src)
include_directories(.)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib GTest::gtest GTest::gmock_main GTest::gtest_main GTest::gmock)
