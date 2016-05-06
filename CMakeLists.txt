cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0054 NEW)
project(cxxutils VERSION 0.1.0.0)

find_package(Threads REQUIRED)
add_subdirectory(contrib)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/cxxutils/config.hxx.in"
    "${CMAKE_CURRENT_BINARY_DIR}/include/cxxutils/config.hxx"
)

set(cxxutils_HEADERS
    include/cxxutils/benchmark.hxx
    include/cxxutils/macros.hxx
    include/cxxutils/meminfo.hxx
    include/cxxutils/noncopyable.hxx
    include/cxxutils/singleton.hxx
)
set(cxxutils_SOURCES
    src/benchmark.cxx
    src/meminfo.cxx
    src/singleton.cxx
)

add_library(cxxutils STATIC ${cxxutils_SOURCES} ${cxxutils_HEADERS})
target_include_directories(cxxutils
    PUBLIC include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include
)
target_link_libraries(cxxutils PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(cxxutils
    PUBLIC
        cxx_auto_type
        cxx_defaulted_functions
        cxx_deleted_functions
        cxx_explicit_conversions
        cxx_generalized_initializers
        cxx_lambdas
        cxx_nullptr
        cxx_uniform_initialization
)

install(TARGETS cxxutils DESTINATION lib)
install(FILES ${cxxutils_HEADERS} "${CMAKE_CURRENT_BINARY_DIR}/include/cxxutils/config.hxx" DESTINATION include/cxxutils)

enable_testing()
set(test_SOURCES
    test/main.cxx
    test/benchmark.cxx
    test/meminfo.cxx
    test/noncopyable.cxx
    test/singleton.cxx
)
add_executable(cxxutils_test_app ${test_SOURCES})
set_target_properties(cxxutils_test_app PROPERTIES OUTPUT_NAME cxxutils_test)
target_include_directories(cxxutils_test_app PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include)
target_link_libraries(cxxutils_test_app cxxutils contrib::gtest contrib::gmock)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(Doxyfile.in Doxyfile)
    add_custom_target( doc "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating documentation with Doxygen." VERBATIM
    )
endif()
