PROJECT ( cxxutils )
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.11 )

FIND_PACKAGE ( Threads REQUIRED )

ENABLE_TESTING ()

SET ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )
INCLUDE ( EnableCxx11 )
INCLUDE ( TestCxx11Features )

ENABLE_CXX11 ()
TEST_CXX11_FEATURES ()

CONFIGURE_FILE (
    "${CMAKE_CURRENT_SOURCE_DIR}/include/cxxutils/config.hxx.in"
    "${CMAKE_CURRENT_BINARY_DIR}/include/cxxutils/config.hxx"
)

FILE ( GLOB cxxutils_HEADERS include/cxxutils/*.hxx )
FILE ( GLOB cxxutils_SOURCES src/*.cxx )

INCLUDE_DIRECTORIES ( include )
INCLUDE_DIRECTORIES ( ${CMAKE_CURRENT_BINARY_DIR}/include )

ADD_LIBRARY ( cxxutils STATIC ${cxxutils_SOURCES} ${cxxutils_HEADERS} )
TARGET_LINK_LIBRARIES ( cxxutils ${CMAKE_THREAD_LIBS_INIT} )

INSTALL ( TARGETS cxxutils DESTINATION lib )
INSTALL ( FILES ${cxxutils_HEADERS} "${CMAKE_CURRENT_BINARY_DIR}/include/cxxutils/config.hxx" DESTINATION include/cxxutils )

FIND_PACKAGE ( CxxTest REQUIRED )

FILE ( GLOB cxxutils_TESTS test/*.hxx )

INCLUDE_DIRECTORIES ( ${CXXTEST_INCLUDE_DIRS} )

CXXTEST_ADD_TEST ( cxxutils_test cxxutils_test.cxx ${cxxutils_TESTS} )
TARGET_LINK_LIBRARIES ( cxxutils_test cxxutils ${CMAKE_THREAD_LIBS_INIT} )

FIND_PACKAGE ( Doxygen )
IF ( DOXYGEN_FOUND )
    CONFIGURE_FILE ( Doxyfile.in Doxyfile )
    ADD_CUSTOM_TARGET ( doc "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating documentation with Doxygen." VERBATIM
    )
ENDIF ()
