cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Todo")
set(EXTERNAL_LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external-libs")
set(PATH_TO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/")

project(${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
    SOURCE_DIR ${EXTERNAL_LIBS_DIR}/json
)
FetchContent_MakeAvailable(json)
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/tasks.json ${CMAKE_CURRENT_BINARY_DIR}/src/tasks.json COPYONLY)

include_directories(${EXTERNAL_LIBS_DIR}/imgui)

set(INTERFACE_FILES
  ${PATH_TO_FILES}/headers/interfaces/IWindow.hpp
)

set(IMGUI_HEADERS
  ${EXTERNAL_LIBS_DIR}/imgui/imgui.h
  ${EXTERNAL_LIBS_DIR}/imgui/imconfig.h
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_impl_glfw.h
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_impl_opengl3.h
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_impl_opengl3_loader.h
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_internal.h
  ${EXTERNAL_LIBS_DIR}/imgui/imstb_rectpack.h
  ${EXTERNAL_LIBS_DIR}/imgui/imstb_textedit.h
  ${EXTERNAL_LIBS_DIR}/imgui/imstb_truetype.h
)

set(HEADER_FILES
  ${PATH_TO_FILES}/headers/Window.hpp
  ${IMGUI_HEADERS}
)

set(IMGUI_SOURCES
  ${EXTERNAL_LIBS_DIR}/imgui/imgui.cpp
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_draw.cpp
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_impl_glfw.cpp
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_impl_opengl3.cpp
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_tables.cpp
  ${EXTERNAL_LIBS_DIR}/imgui/imgui_widgets.cpp
)

set(SOURCE_FILES
  ${PATH_TO_FILES}/Window.cpp
  ${IMGUI_SOURCES}
  ${PATH_TO_FILES}/main.cpp
)

add_executable(
  ${PROJECT_NAME}
  ${INTERFACE_FILES}
  ${HEADER_FILES}
  ${SOURCE_FILES}
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${EXTERNAL_LIBS_DIR}/glfw-3.3.8.bin.WIN64/include/
  ${EXTERNAL_LIBS_DIR}/imgui
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  ${EXTERNAL_LIBS_DIR}/glfw-3.3.8.bin.WIN64/lib-vc2022/glfw3.lib
  nlohmann_json::nlohmann_json
  opengl32
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
