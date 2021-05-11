cmake_minimum_required(VERSION 3.0)
project(Arma)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


# Adding bin & lib directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Arma_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Arma_SOURCE_DIR}/lib)


# Path for adding content
option(USE_INSTALL_RESOURCE_PATH
        "Set resource path to install location" OFF)
if(NOT USE_INSTALL_RESOURCE_PATH)
    set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
else()
    set(RESOURCE_PATH
            "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/content/")
endif()


# generating a header file that passes resource_path to our app
configure_file(headers/config.h.in config.h)


# locating the SFML shared libraries and their corresponding header files
find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)


# including our own libraries
include_directories(headers)
add_subdirectory(sources)


# execute
add_executable(Arma main.cpp)
target_include_directories(Arma
        PRIVATE "${PROJECT_BINARY_DIR}")


# enable to locate the SFML shared libraries and subsequently load them at runtime
set_target_properties(Arma
        PROPERTIES
            INSTALL_RPATH_USE_LINK_PATH TRUE)
set_target_properties(Arma
        PROPERTIES
            INSTALL_RPATH
                "${CMAKE_INSTALL_PREFIX}/lib"
        )


# linking targets
target_link_libraries(Arma sfml-graphics)
target_link_libraries(Arma Assets Model Render Controller
        Composite Unit UnitFactory Color UnitTexture Graphics)


# wrapping up our configuration
install(TARGETS Arma
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)


# Copy resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}")
