cmake_minimum_required(VERSION 3.5)

project(GIFLIB VERSION 0.1 LANGUAGES C CXX)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_library(GIFLIB
    gifLib/dgif_lib.c
    gifLib/egif_lib.c
    gifLib/gif_err.c
    gifLib/gif_hash.c
    gifLib/gifalloc.c
    gifLib/quantize.c
    gifLib/gif_hash.h
    gifLib/gif_lib_private.h
    gifLib/gif_lib.h
    gifImage/qgifglobal.h
    gifImage/qgifimage_p.h
    gifImage/qgifimage.cpp
    gifImage/qgifimage.h
)

target_link_libraries(GIFLIB Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
