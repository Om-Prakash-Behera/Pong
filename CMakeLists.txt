cmake_minimum_required(VERSION 3.20)
project(Pong)

# C++ settings
set(CMAKE_CXX_STANDARD 20)

# Remove the need to copy and paste assets in debug builds
option(PRODUCTION_BUILD
    "Enable Production Build"
    OFF
)

# Access all cpp files in src
# Always do std::string(RESOURCES_PATH) + "textures/white_king.png"
file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# For packages installed by vcpkg
find_package(SFML CONFIG REQUIRED
    COMPONENTS
        Graphics
        Network
        System
        Window
        Audio
)

# For intellisense
target_include_directories(${PROJECT_NAME}
    PRIVATE include
)

# For linking library
target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        SFML::Graphics
        SFML::Network
        SFML::System
        SFML::Window
        SFML::Audio
)

# Asset path
if(PRODUCTION_BUILD)
    # Copy assets to release

    message(STATUS
        "Production Build Enabled"
    )

    target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
        RESOURCES_PATH="./assets/"
        PRODUCTION_BUILD=1
        DEVELOPMENT_BUILD=0
    )

    # Copy assets beside executable
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
    )

else()
    # Directly refer to assets in root

    message(STATUS
        "Development Build Enabled"
    )

    target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
        RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/"
        PRODUCTION_BUILD=0
        DEVELOPMENT_BUILD=1
    )

endif()

# Note that you need to do {"C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools"} in settings.json for intellisense to work for RESOURCES_PATH