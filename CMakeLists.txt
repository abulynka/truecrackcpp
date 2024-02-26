cmake_minimum_required(VERSION 3.22.1)
project(truecrackcpp)

set(CMAKE_CXX_STANDARD 20)

add_custom_target(a
        COMMAND make all -j 8
        COMMENT "Building everything from truecryptcpp project"
)

add_custom_target(src
        COMMAND make -j 8
        WORKING_DIRECTORY ./src
        COMMENT "Building truecryptcpp"
)

add_custom_target(test
        COMMAND make -j 8
        WORKING_DIRECTORY ./test
        COMMENT "Building truecryptcpp test"
)

add_compile_options(-fsanitize=address -Werror -Wall -g -rdynamic)
add_link_options(-fsanitize=address)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
