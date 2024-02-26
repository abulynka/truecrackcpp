set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(../lib/cxxopts/include)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

foreach(SOURCE ${SOURCES})
    if("${SOURCE}" MATCHES "truecrypt/")
        set_source_files_properties(${SOURCE} PROPERTIES COMPILE_FLAGS "-Wno-error")
    endif()
endforeach()

set(SOURCES ${SOURCES})

add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

add_library(Threads::Threads INTERFACE IMPORTED)
