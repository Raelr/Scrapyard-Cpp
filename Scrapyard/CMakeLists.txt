project(Scrapyard)

add_library(Scrapyard src/Scrapyard/Application.cpp)

add_subdirectory(libs/spdlog)

find_package(spdlog)

target_include_directories(Scrapyard PUBLIC spdlog)
target_link_libraries(Scrapyard spdlog)