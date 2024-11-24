cmake_minimum_required(VERSION 3.10)
project(myApplication 
	VERSION 1.0
	DESCRIPTION "A CMake Project for cryptographic algorithms"
	LANGUAGES C)
	
# Main Directories
set(ROOT_DIR ${CMAKE_SOURCE_DIR}) #Application DIR which contains the top level cmakelists.txt file
set(APP_DIR ${ROOT_DIR}) 

# Application Directories
set(OUT_DIR ${APP_DIR}/out)
set(GEN_DIR ${OUT_DIR}/gen)
set(LIBS_DIR ${OUT_DIR}/libs)
set(APP_BIN ${APP_DIR})

# Modules Directories
set(CAESAR_CIPHER_DIR ${APP_DIR}/../modules/caesar_cipher)
set(XOR_CIPHER_DIR ${APP_DIR}/../modules/xor_cipher)

#making out , gen , libs directories 
file(MAKE_DIRECTORY ${GEN_DIR})
file(MAKE_DIRECTORY ${LIBS_DIR})


# setting generated files directories 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBS_DIR}) #specify where static library is placed
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBS_DIR}) #specify where dynamic library is placed 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${APP_BIN}) #specify where final executable is placed

#including other Cmakelists.txt files which are in caesar_cipher and xor_cipher directories 
add_subdirectory(${CAESAR_CIPHER_DIR} ${CMAKE_BINARY_DIR}/caesar_cipher)
add_subdirectory(${XOR_CIPHER_DIR} ${CMAKE_BINARY_DIR}/xor_cipher)

#define prerequistes of our target (output)
add_executable(output app.c)

#make sure that object files are stored in gen directory
set_target_properties(output PROPERTIES COMPILE_OBJECT_OUTPUT_DIRECTORY ${GEN_DIR})


#specify which libraries the output executable should be linked against and link output to these libraries by their target names in cmakelists.txt (caesar_cipher and xor_cipher)
target_link_libraries(output PRIVATE caesar_cipher xor_cipher)

#specify include directories for output target
target_include_directories(output PRIVATE ${CAESAR_CIPHER_DIR}/inc)
target_include_directories(output PRIVATE ${XOR_CIPHER_DIR}/inc)


add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/caesar_cipher
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/xor_cipher
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR} 
    COMMENT "Cleaning all build"
)

