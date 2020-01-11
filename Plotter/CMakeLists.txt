find_package(Qwt REQUIRED COMPONENTS Qwt)

file(GLOB_RECURSE PLOTTER_HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/*.h)
file(GLOB_RECURSE PLOTTER_SOURCE ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

add_library(Plotter SHARED ${PLOTTER_HEADERS} ${PLOTTER_SOURCE})
target_include_directories(Plotter
                           PUBLIC
                             $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                             $<INSTALL_INTERFACE:include>)
target_link_libraries(Plotter PUBLIC Qwt::Qwt)
target_compile_definitions(Plotter PRIVATE PLOTTER_DYNAMIC)