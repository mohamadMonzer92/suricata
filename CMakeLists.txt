cmake_minimum_required(VERSION 3.15)
project(suricata C)
set(CMAKE_C_STANDARD 99)


#set(ENV{PATH} "/Users/housseinmonzer/.cargo/bin:ENV{PATH}")
set(ENV{PATH} "/Users/housseinmonzer/.cargo/bin:$PATH")
#set(ENV{cbindgen} "/Users/housseinmonzer/.cargo/bin/cbindgen")

message("PATH is defined as: " $ENV{PATH})
message("CBINDGEN: " $ENV{cbindgen})

#add_custom_target(
#        run
##        COMMAND ${CMAKE_COMMAND} -E env "PATH=/Users/housseinmonzer/.cargo/bin/cbindgen:ENV{PATH}" make
#        COMMAND ${CMAKE_COMMAND} -E env "PATH=/Users/housseinmonzer/.cargo/bin/cbindgen:$PATH" make
##        COMMAND make
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_custom_target(
        run
        /usr/bin/make -f "${CMAKE_CURRENT_SOURCE_DIR}/../Makefile"
)

add_custom_command(
        OUTPUT suricataOUT
#        COMMAND make
        run
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)
#add_custom_target(run COMMAND make WORKING_DIRECTORY)
#add_custom_command(OUTPUT suricataOUT COMMAND make run)
add_executable(src main.c)