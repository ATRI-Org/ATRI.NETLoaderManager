cmake_minimum_required(VERSION 3.15)

project(EndStoneDotNetLoader CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG main # or set to a specific version tag
)
FetchContent_MakeAvailable(endstone)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fPIC")
    link_libraries(-static-libgcc -static-libstdc++ libc++.a libc++abi.a)
endif ()
link_directories("lib/")
LINK_LIBRARIES("nethost")
add_library(${PROJECT_NAME} SHARED "src/main.cpp" "include/coreclr_delegates.h" "include/hostfxr.h" "src/HostLoader.cpp" )
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE endstone::headers)
