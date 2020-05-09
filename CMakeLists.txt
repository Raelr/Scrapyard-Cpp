cmake_minimum_required(VERSION 3.16)
project(VulkanPractice)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(glm REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

add_subdirectory(Scrapyard)

list(APPEND EXTRA_LIBS Scrapyard)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Scrapyard")

add_executable(VulkanPractice main.cpp)

target_link_libraries(VulkanPractice glfw ${GLFW_LIBRARIES} ${EXTRA_LIBS} Vulkan::Vulkan)
target_include_directories(VulkanPractice PUBLIC ${EXTRA_INCLUDES})