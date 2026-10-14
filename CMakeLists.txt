cmake_minimum_required(VERSION 3.20)
project(GoldenSunTheBrokenSealRecomp C CXX)

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

set(GBARECOMP_TOMLPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.deps/tomlplusplus" CACHE PATH "Pinned toml++ headers")
set(RECOMP_UI_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/recomp-ui" CACHE PATH "Pinned player launcher")
set(GBARECOMP_SELFHEAL_RECOMPILE_DEFAULT OFF CACHE BOOL "Preview needs no runtime compiler" FORCE)
set(GBARECOMP_COMPILER_CACHE OFF CACHE STRING "Keep compilation output inside this project")

# Locate SDL2 MinGW development package
if(NOT SDL2_ROOT)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/reference/sdl2/SDL2-2.30.11/x86_64-w64-mingw32")
        set(SDL2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/reference/sdl2/SDL2-2.30.11/x86_64-w64-mingw32")
    elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL2-2.30.11/x86_64-w64-mingw32")
        set(SDL2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL2-2.30.11/x86_64-w64-mingw32")
    elseif(EXISTS "D:/Project/GameRecomp/_sdl2/SDL2-2.32.8/x86_64-w64-mingw32")
        set(SDL2_ROOT "D:/Project/GameRecomp/_sdl2/SDL2-2.32.8/x86_64-w64-mingw32")
    endif()
endif()

if(SDL2_ROOT)
    if(NOT SDL2_INCLUDE_DIR)
        set(SDL2_INCLUDE_DIR "${SDL2_ROOT}/include/SDL2")
    endif()
    if(NOT SDL2_LIBRARY)
        set(SDL2_LIBRARY "${SDL2_ROOT}/lib/libSDL2.dll.a")
    endif()
    if(NOT SDL2_DLL AND EXISTS "${SDL2_ROOT}/bin/SDL2.dll")
        set(SDL2_DLL "${SDL2_ROOT}/bin/SDL2.dll" CACHE FILEPATH "SDL2 runtime DLL")
    endif()
    set(GBARECOMP_MINGW_PREFIX_UNIX "${SDL2_ROOT}" CACHE PATH "SDL2 MinGW prefix" FORCE)
endif()

if(MINGW AND NOT GBARECOMP_MINGW_RUNTIME_BIN)
    get_filename_component(_mingw_bin "${CMAKE_CXX_COMPILER}" DIRECTORY)
    set(GBARECOMP_MINGW_RUNTIME_BIN "${_mingw_bin}" CACHE PATH "MinGW runtime DLLs")
endif()

add_subdirectory("${GBARECOMP_ROOT}" gbarecomp-build EXCLUDE_FROM_ALL)
get_target_property(RUNTIME_DEFINES gbarecomp_runtime COMPILE_DEFINITIONS)
list(FILTER RUNTIME_DEFINES EXCLUDE REGEX "^GBARECOMP_SRC_DIR=")
set_property(TARGET gbarecomp_runtime PROPERTY COMPILE_DEFINITIONS ${RUNTIME_DEFINES} GBARECOMP_SRC_DIR="gbarecomp")

include("${RECOMP_UI_ROOT}/recomp_ui.cmake")
add_library(game_launcher_ui STATIC src/game_launcher_boot.cpp)
target_include_directories(game_launcher_ui PRIVATE
    "${GBARECOMP_ROOT}/src/runtime"
    "${GBARECOMP_ROOT}/src/gba"
    ${SDL2_INCLUDE_DIR}
)
recomp_target_launcher_ui(game_launcher_ui CONSOLE gba)
target_link_libraries(game_launcher_ui PUBLIC ${SDL2_LIBRARY})

set(GAME_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/game")
if(NOT EXISTS "${GAME_SRC_DIR}/dispatch_table.cpp")
    message(FATAL_ERROR
        "Game translation units not found in ${GAME_SRC_DIR}.\n"
        "Run: .\\build.ps1 -Rom <your.gba> or .\\scripts\\generate.ps1 -Rom <your.gba>")
endif()

file(GLOB GS1_GAME_SOURCES CONFIGURE_DEPENDS "${GAME_SRC_DIR}/*.cpp")

add_executable(GoldenSunTheBrokenSealRecomp WIN32
    src/main.cpp
    ${GS1_GAME_SOURCES}
)

# Apply -O1 to generated guest shards for faster compile times
set_source_files_properties(${GS1_GAME_SOURCES} PROPERTIES COMPILE_OPTIONS "-O1;-g0")

target_include_directories(GoldenSunTheBrokenSealRecomp PRIVATE
    "${GBARECOMP_ROOT}/src/armv4t"
    "${GBARECOMP_ROOT}/src/gba"
    "${GBARECOMP_ROOT}/src/runtime"
    "${GBARECOMP_ROOT}/src/debug"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game"
)

target_compile_definitions(GoldenSunTheBrokenSealRecomp PRIVATE
    GBARECOMP_WINDOW_TITLE="Golden Sun: The Broken Seal"
    GBARECOMP_DEFAULT_GAME_CONFIG="game.toml"
)

target_link_libraries(GoldenSunTheBrokenSealRecomp PRIVATE
    game_launcher_ui
    -Wl,--start-group
    gbarecomp_armv4t
    gbarecomp_gba
    gbarecomp_runtime
    gbarecomp_debug
    -Wl,--end-group
)

if(WIN32)
    target_link_options(GoldenSunTheBrokenSealRecomp PRIVATE
        "-mwindows"
        "LINKER:--subsystem,windows"
        "LINKER:--stack,67108864"
        "LINKER:--allow-multiple-definition"
    )
    target_link_libraries(GoldenSunTheBrokenSealRecomp PRIVATE shell32 user32 gdi32 winmm)
endif()

recomp_stage_launcher_assets(GoldenSunTheBrokenSealRecomp CONSOLE gba)

if(COMMAND gbarecomp_stage_mingw_runtime)
    gbarecomp_stage_mingw_runtime(GoldenSunTheBrokenSealRecomp)
endif()

if(SDL2_DLL)
    add_custom_command(TARGET GoldenSunTheBrokenSealRecomp POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
            "${SDL2_DLL}"
            "$<TARGET_FILE_DIR:GoldenSunTheBrokenSealRecomp>/SDL2.dll"
        VERBATIM
    )
elseif(SDL2_ROOT AND EXISTS "${SDL2_ROOT}/bin/SDL2.dll")
    add_custom_command(TARGET GoldenSunTheBrokenSealRecomp POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
            "${SDL2_ROOT}/bin/SDL2.dll"
            "$<TARGET_FILE_DIR:GoldenSunTheBrokenSealRecomp>/SDL2.dll"
        VERBATIM
    )
endif()

add_custom_command(TARGET GoldenSunTheBrokenSealRecomp POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/game.toml"
        "$<TARGET_FILE_DIR:GoldenSunTheBrokenSealRecomp>/game.toml"
    VERBATIM
)

# Compatibility alias target gs1
add_custom_target(gs1 ALL DEPENDS GoldenSunTheBrokenSealRecomp)

# Target for testing launcher contract
add_executable(launcher_contract EXCLUDE_FROM_ALL tests/launcher_contract.cpp)
target_compile_definitions(launcher_contract PRIVATE RECOMP_LAUNCHER)
target_include_directories(launcher_contract PRIVATE
    "${GBARECOMP_ROOT}/src/runtime"
    "${RECOMP_UI_ROOT}/src"
    "${RECOMP_UI_ROOT}/src/common"
)
target_link_libraries(launcher_contract PRIVATE game_launcher_ui gbarecomp_gba)
