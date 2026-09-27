cmake_minimum_required(VERSION 3.20)
project(gs1 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Locate GBARecomp framework source tree
if(NOT GBARECOMP_ROOT)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/reference/gbarecomp/CMakeLists.txt")
        set(GBARECOMP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/reference/gbarecomp")
    elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../gbarecomp-main/CMakeLists.txt")
        set(GBARECOMP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../gbarecomp-main")
    else()
        set(GBARECOMP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/gbarecomp")
    endif()
endif()

if(NOT EXISTS "${GBARECOMP_ROOT}/CMakeLists.txt")
    message(FATAL_ERROR "GBARECOMP_ROOT not found: ${GBARECOMP_ROOT}\n"
        "Clone https://github.com/mstan/gbarecomp (with submodules) or set -DGBARECOMP_ROOT=<path>.")
endif()

# Locate SDL2 MinGW development package
if(NOT SDL2_ROOT)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/reference/sdl2/SDL2-2.30.11/x86_64-w64-mingw32")
        set(SDL2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/reference/sdl2/SDL2-2.30.11/x86_64-w64-mingw32")
    elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL2-2.30.11/x86_64-w64-mingw32")
        set(SDL2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL2-2.30.11/x86_64-w64-mingw32")
    endif()
endif()

if(SDL2_ROOT)
    if(NOT SDL2_INCLUDE_DIR)
        set(SDL2_INCLUDE_DIR "${SDL2_ROOT}/include/SDL2")
    endif()
    if(NOT SDL2_LIBRARY)
        set(SDL2_LIBRARY "${SDL2_ROOT}/lib/libSDL2.dll.a")
    endif()
    set(GBARECOMP_MINGW_PREFIX_UNIX "${SDL2_ROOT}" CACHE PATH "SDL2 MinGW prefix" FORCE)
endif()

if(EXISTS "C:/MYAPPLY/mingw64/bin")
    set(GBARECOMP_MINGW_RUNTIME_BIN "C:/MYAPPLY/mingw64/bin" CACHE PATH "MinGW runtime DLLs" FORCE)
endif()

add_subdirectory("${GBARECOMP_ROOT}" gbarecomp-build EXCLUDE_FROM_ALL)

set(GAME_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/game")
if(NOT EXISTS "${GAME_SRC_DIR}/dispatch_table.cpp")
    message(FATAL_ERROR
        "Game translation units not found in ${GAME_SRC_DIR}.\n"
        "Run: .\\build.ps1 -Rom <your.gba> or .\\scripts\\generate.ps1 -Rom <your.gba>")
endif()

file(GLOB GS1_GAME_SOURCES CONFIGURE_DEPENDS "${GAME_SRC_DIR}/*.cpp")

add_executable(gs1 WIN32
    src/main.cpp
    ${GS1_GAME_SOURCES}
)

# Apply -O1 to generated guest shards for faster compile times
set_source_files_properties(${GS1_GAME_SOURCES} PROPERTIES COMPILE_OPTIONS "-O1;-g0")

target_include_directories(gs1 PRIVATE
    "${GBARECOMP_ROOT}/src/armv4t"
    "${GBARECOMP_ROOT}/src/gba"
    "${GBARECOMP_ROOT}/src/runtime"
    "${GBARECOMP_ROOT}/src/debug"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game"
)

target_compile_definitions(gs1 PRIVATE
    GBARECOMP_WINDOW_TITLE="Golden Sun: The Broken Seal"
    GBARECOMP_DEFAULT_GAME_CONFIG="game.toml"
)

target_link_libraries(gs1 PRIVATE
    -Wl,--start-group
    gbarecomp_armv4t
    gbarecomp_gba
    gbarecomp_runtime
    gbarecomp_debug
    -Wl,--end-group
)

if(WIN32)
    target_link_options(gs1 PRIVATE
        "-mwindows"
        "LINKER:--subsystem,windows"
        "LINKER:--stack,16777216"
        "LINKER:--allow-multiple-definition"
    )
    target_link_libraries(gs1 PRIVATE shell32 user32 gdi32 winmm)
endif()

if(COMMAND gbarecomp_stage_mingw_runtime)
    gbarecomp_stage_mingw_runtime(gs1)
endif()

add_custom_command(TARGET gs1 POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/game.toml"
        "$<TARGET_FILE_DIR:gs1>/game.toml"
    VERBATIM
)

if(SDL2_ROOT AND EXISTS "${SDL2_ROOT}/bin/SDL2.dll")
    add_custom_command(TARGET gs1 POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
            "${SDL2_ROOT}/bin/SDL2.dll"
            "$<TARGET_FILE_DIR:gs1>/SDL2.dll"
        VERBATIM
    )
endif()
