include(CMakeFindDependencyMacro)
cmake_policy(SET CMP0012 NEW)
cmake_policy(SET CMP0057 NEW)
set(features "core;font-configuration;zlib")
find_dependency(Boost)
if("fontconfig" IN_LIST features)
    find_dependency(Fontconfig) # CMake 3.14
endif()
find_dependency(Freetype)
find_dependency(JPEG)
find_dependency(PNG)
find_dependency(TIFF)
find_dependency(OpenJPEG CONFIG)
if("curl" IN_LIST features)
    find_dependency(CURL)
endif()
if("zlib" IN_LIST features)
    find_dependency(ZLIB)
endif()
if("qt" IN_LIST features)
    find_dependency(Qt6 CONFIG Core GUI)
endif()
find_dependency(Iconv) # CMake 3.11
include("${CMAKE_CURRENT_LIST_DIR}/unofficial-poppler-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/unofficial-poppler-cpp-targets.cmake")
if("qt" IN_LIST features)
    include("${CMAKE_CURRENT_LIST_DIR}/unofficial-poppler-qt6-targets.cmake")
endif()
