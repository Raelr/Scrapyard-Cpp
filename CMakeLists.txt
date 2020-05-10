cmake_minimum_required(VERSION 3.16)
project(VulkanPractice)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Scrapyard)
add_subdirectory(Sandbox)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(glm REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

add_executable(VulkanPractice Scrapyard/src/Scrapyard/Entrypoint.h)

target_include_directories(VulkanPractice PUBLIC "${PROJECT_BINARY_DIR}" Scrapyard Sandbox)
target_link_libraries(VulkanPractice glfw ${GLFW_LIBRARIES} Vulkan::Vulkan Scrapyard Sandbox)