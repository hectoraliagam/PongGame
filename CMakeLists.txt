cmake_minimum_required(VERSION 3.21)

project(pong VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# Build type
# -----------------------------
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# -----------------------------
# Raylib
# -----------------------------
find_package(raylib CONFIG REQUIRED)

# -----------------------------
# Sources
# -----------------------------
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# -----------------------------
# Includes
# -----------------------------
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
)

# -----------------------------
# Link libraries
# -----------------------------
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    raylib
)

# -----------------------------
# Compile options
# -----------------------------
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Release>:-O3>
)

# -----------------------------
# Output
# -----------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

# -----------------------------
# Windows specific
# -----------------------------
if(WIN32)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE opengl32 gdi32 winmm
    )

    target_link_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Release>:-mwindows>
    )
endif()
