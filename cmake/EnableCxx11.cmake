FUNCTION ( ENABLE_CXX11 )
    # for g++ and clang++
    IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        IF (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.7.0")
            SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" PARENT_SCOPE )
        ELSE ()
            SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" PARENT_SCOPE )
        ENDIF ()
    ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # will have to adjust this... older clang versions may need -std=c++0x
        # but I could not find an exact version number :-/
        SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" PARENT_SCOPE )
    ENDIF ()
ENDFUNCTION ( ENABLE_CXX11 )

