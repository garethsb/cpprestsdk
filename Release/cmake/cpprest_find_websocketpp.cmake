function(cpprest_find_websocketpp)
  if(TARGET cpprestsdk_websocketpp_internal)
    return()
  endif()

  find_package(WEBSOCKETPP CONFIG QUIET)
  if(WEBSOCKETPP_FOUND)
    message("-- Found websocketpp version " ${WEBSOCKETPP_VERSION} " on system")
    set(WEBSOCKETPP_INCLUDE_DIR ${WEBSOCKETPP_INCLUDE_DIR} CACHE INTERNAL "")
  elseif(EXISTS ${PROJECT_SOURCE_DIR}/libs/websocketpp/CMakeLists.txt)
    message("-- websocketpp not found, using the embedded version")
    set(WEBSOCKETPP_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libs/websocketpp CACHE INTERNAL "")
  else()
    message(FATAL_ERROR "-- websocketpp not found and embedded version not present; try `git submodule update --init` and run CMake again")
  endif()

  cpprest_find_boost()
  cpprest_find_openssl()

  # Boost 1.87 removed the deprecated Asio API, so websocketpp must have been ported to the new one,
  # which declares io_context_ptr. The version number cannot tell, because upstream develop reports
  # 0.8.3 without the port.
  find_package(Boost QUIET)
  set(_endpoint_hpp "${WEBSOCKETPP_INCLUDE_DIR}/websocketpp/transport/asio/endpoint.hpp")
  if("${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}" VERSION_GREATER_EQUAL 1.87 AND EXISTS "${_endpoint_hpp}")
    file(STRINGS "${_endpoint_hpp}" _io_context_ptr REGEX "io_context_ptr" LIMIT_COUNT 1)
    if(NOT _io_context_ptr)
      message(FATAL_ERROR "-- websocketpp in ${WEBSOCKETPP_INCLUDE_DIR} does not build with Boost "
        "${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}, because it uses the deprecated Asio API that Boost 1.87 removed; "
        "use a websocketpp with the new Asio API, such as https://github.com/cpprest-lts/websocketpp 0.8.4 or later, "
        "or set CPPREST_EXCLUDE_WEBSOCKETS=ON")
    endif()
  endif()

  add_library(cpprestsdk_websocketpp_internal INTERFACE)
  # Package managers such as Conan may define only the websocketpp::websocketpp target, not WEBSOCKETPP_INCLUDE_DIR
  if(WEBSOCKETPP_FOUND AND TARGET websocketpp::websocketpp)
    target_link_libraries(cpprestsdk_websocketpp_internal INTERFACE "$<BUILD_INTERFACE:websocketpp::websocketpp>")
  else()
    target_include_directories(cpprestsdk_websocketpp_internal INTERFACE "$<BUILD_INTERFACE:${WEBSOCKETPP_INCLUDE_DIR}>")
  endif()
  target_link_libraries(cpprestsdk_websocketpp_internal
    INTERFACE
      cpprestsdk_boost_internal
      cpprestsdk_openssl_internal
  )
endfunction()
