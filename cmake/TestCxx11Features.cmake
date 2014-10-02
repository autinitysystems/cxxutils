FUNCTION ( TEST_CXX11_FEATURES )
    MESSAGE ( STATUS "Testing available C++11 features..." )

    TRY_COMPILE ( feature_available "${CMAKE_BINARY_DIR}/cxx11_features" "${CMAKE_MODULE_PATH}/test_cxx11_defaultdelete.cxx" )
    MESSAGE ( STATUS "Explicitly defaulted and deleted special member functions: ${feature_available}" )
    SET ( HAS_CXX11_DEFAULTDELETE ${feature_available} PARENT_SCOPE )

    TRY_COMPILE ( feature_available "${CMAKE_BINARY_DIR}/cxx11_features" "${CMAKE_MODULE_PATH}/test_cxx11_explicitcast.cxx" )
    MESSAGE ( STATUS "Explicit conversion operators: ${feature_available}" )
    SET ( HAS_CXX11_EXPLICITCAST ${feature_available} PARENT_SCOPE )

    MESSAGE ( STATUS "Done testing C++11 features." )
ENDFUNCTION ( TEST_CXX11_FEATURES )
