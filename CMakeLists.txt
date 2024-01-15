cmake_minimum_required(VERSION 3.10)

set(PROJECT_N "Enter")
project(${PROJECT_N} VERSION 1.0)

set(CMAKE_CXX_FLAGS "-fpermissive -std=c++17")
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)


# a macro that gets all of the header containing directories. 
MACRO(header_directories return_list includes_base_folder extention )
    FILE(GLOB_RECURSE new_list ${includes_base_folder}/*.${extention})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()



# using said macro.
header_directories(INCLUDES ${PROJECT_SOURCE_DIR}/include/ hpp)

message("src files:")
foreach(file ${SRCS})
        message(STATUS ${file})
endforeach()

set(DEPS_include_dir ${PROJECT_SOURCE_DIR}/deps/include)
set(DEPS_lib_dir ${PROJECT_SOURCE_DIR}/deps/lib)
set(DEPS2_include_dir ${PROJECT_SOURCE_DIR}/_deps/lua-vanilla-src/src)


include_directories(${DEPS_include_dir} ${DEPS2_include_dir})
include_directories(${INCLUDES})

message("include directories:")
foreach(dir ${INCLUDES})
        message(STATUS ${dir})
endforeach()
add_executable(${PROJECT_N} ${SRCS})

target_include_directories(${PROJECT_N} PUBLIC include)

target_link_libraries(${PROJECT_N} ${DEPS_lib_dir}/liblua-5.4.4.dll.a ${DEPS_lib_dir}/liblua54.a ${DEPS_lib_dir}/lua5.1.lib)