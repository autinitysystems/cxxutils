PROJECT ( cxxutils )
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.11 )

ENABLE_TESTING ()

SET ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )
INCLUDE ( EnableCxx11 )

ENABLE_CXX11 ()

FILE ( GLOB cxxutils_HEADERS include/cxxutils/*.hxx )
FILE ( GLOB cxxutils_SOURCES src/*.cxx )

INCLUDE_DIRECTORIES ( include )

ADD_LIBRARY ( cxxutils STATIC ${cxxutils_SOURCES} ${cxxutils_HEADERS} )

INSTALL ( TARGETS cxxutils DESTINATION lib )
INSTALL ( FILES ${cxxutils_HEADERS} DESTINATION include/cxxutils )

FIND_PACKAGE ( CxxTest REQUIRED )

FILE ( GLOB cxxutils_TESTS test/*.hxx )

CXXTEST_ADD_TEST ( cxxutils_test cxxutils_test.cxx ${cxxutils_TESTS} )
TARGET_LINK_LIBRARIES ( cxxutils_test cxxutils )
