CMAKE_MINIMUM_REQUIRED( VERSION 3.5 )
CMAKE_POLICY(SET CMP0048 NEW)
CMAKE_POLICY(SET CMP0054 NEW)
PROJECT ( cxxutils VERSION 0.1.0.0 )

LIST ( APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/cxx11"
)

FIND_PACKAGE ( Threads REQUIRED )

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
TARGET_COMPILE_FEATURES( cxxutils
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

INSTALL ( TARGETS cxxutils DESTINATION lib )
INSTALL ( FILES ${cxxutils_HEADERS} "${CMAKE_CURRENT_BINARY_DIR}/include/cxxutils/config.hxx" DESTINATION include/cxxutils )

FIND_PACKAGE ( CxxTest )
IF ( CXXTEST_FOUND )
    ENABLE_TESTING ()
    
    FILE ( GLOB cxxutils_TESTS test/*.hxx )
    
    INCLUDE_DIRECTORIES ( ${CXXTEST_INCLUDE_DIRS} )
    
    CXXTEST_ADD_TEST ( cxxutils_test cxxutils_test.cxx ${cxxutils_TESTS} )
    TARGET_LINK_LIBRARIES ( cxxutils_test cxxutils ${CMAKE_THREAD_LIBS_INIT} )
ENDIF ()

FIND_PACKAGE ( Doxygen )
IF ( DOXYGEN_FOUND )
    CONFIGURE_FILE ( Doxyfile.in Doxyfile )
    ADD_CUSTOM_TARGET ( doc "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating documentation with Doxygen." VERBATIM
    )
ENDIF ()
