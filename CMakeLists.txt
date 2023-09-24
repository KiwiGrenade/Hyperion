cmake_minimum_required(VERSION 3.23)
project(3DVector)

set(CMAKE_CXX_STANDARD 23)

#TODO: Refactor this so src/ won't be necessary
add_subdirectory(src)
add_executable(3DVector main.cpp)
#######################################################################################
#Catch2 content
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
target_link_libraries(3DVector PRIVATE Catch2::Catch2WithMain)
#######################################################################################

target_link_libraries(3DVector PRIVATE FileRendering)
target_include_directories(3DVector PUBLIC 
	"${PROJECT_SOURCE_DIR}/src")

