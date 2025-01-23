######################################################################################################################################################
######################################################################################################################################################
cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

######################################################################################################################################################
# Proejct meta data

project(MRMathCPP
  VERSION 3.0.0.0
  DESCRIPTION "Simple Mathematical Utilities"
  HOMEPAGE_URL "https://github.com/richmit/MRMathCPP/"
  LANGUAGES CXX)

set(MRMATHCPP_VERSION_DATE  2024-11-06)
mark_as_advanced(MRMATHCPP_VERSION_DATE)

string(TIMESTAMP MRMATHCPP_CONFIG_DATE "%Y-%m-%d")
mark_as_advanced(MRMATHCPP_CONFIG_DATE)

######################################################################################################################################################
# Include ctest -- we might not use it if boost is not found...
include(CTest)

######################################################################################################################################################
# Here are the options we use to modify the build -- these options are passed to cmake like so: cmake -DO_BTEST=YES or -DO_BTEST=NO

OPTION(O_DOXYGEN     "Include support for doxygen"              ON  )
OPTION(O_GTEST       "Include support for Google Test"          ON  )
OPTION(OWNLOAD_GTEST "Download latest Google Test from Github"  OFF )

######################################################################################################################################################
# Find tools & libraries used to build targets

if(O_DOXYGEN)
  find_package(Doxygen)
endif()

if(O_GTEST)
  if(OWNLOAD_GTEST)
    message(STATUS "Downloading GTest")
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/heads/main.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    set(MRMATHCPP_FOUND_GTEST "1")  # If FetchContent_MakeAvailable didn't work, then cmake will error out.
    set(GTest_FOUND "YES")         # If FetchContent_MakeAvailable didn't work, then cmake will error out.
  else()
    message(STATUS "Not downloading GTest")
    find_package(GTest)
    if(GTest_FOUND)
      set(MRMATHCPP_FOUND_GTEST "1")
    else()
      set(MRMATHCPP_FOUND_GTEST "0")
    endif()
  endif()
else()
  if(OWNLOAD_GTEST)
    message(FATAL_ERROR "-DO_GTEST must be YES if -DOWNLOAD_GTEST is YES!")
  endif()
endif()

######################################################################################################################################################
# Create Unit Test Targets

if(GTest_FOUND)
  # Master list of targets
  set(TARGETS
              "mjr_math_bply"
              "mjr_math_cplx"
              "mjr_math_fc"
              "mjr_math_ivl"
              "mjr_math_linm"
              "mjr_math_odr"
              "mjr_math_sfun"
              "mjr_math_str"
              "mjr_math_uply"
              "mjr_math_vec"
            )

  # Add a target for each one we can build
  foreach(CURTGT IN LISTS TARGETS)

    add_executable(${CURTGT} EXCLUDE_FROM_ALL "utests/${CURTGT}.cpp")
    list(APPEND TARGETS_UTEST ${CURTGT})

    target_compile_features(${CURTGT} PUBLIC cxx_std_23)

    # MRMathCPP specific header libs
    target_include_directories(${CURTGT} PRIVATE lib)
    target_include_directories(${CURTGT} PRIVATE ${CMAKE_BINARY_DIR})

    # Compiler specific stuff
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      target_compile_options(${CURTGT} PUBLIC -Wall -Wconversion -Wno-unknown-pragmas -Wextra -Wno-deprecated-copy)
      target_compile_options(${CURTGT} PUBLIC -O4)
    elseif((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang"))
      target_compile_options(${CURTGT} PUBLIC -Wall -Wconversion -Wno-unknown-pragmas -Wextra -Wno-sign-conversion)
      target_compile_options(${CURTGT} PUBLIC -O3)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
      target_compile_options(${CURTGT} PUBLIC -Wall)
      target_compile_options(${CURTGT} PUBLIC -O3)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
      message("Warning: MSVC support is currently experimental")
    endif()

    target_link_libraries(${CURTGT} PRIVATE GTest::gtest_main)
    add_test(NAME "${CURTGT}" COMMAND "${CURTGT}")

  endforeach(CURTGT)

  add_custom_target(utests
    DEPENDS ${TARGETS_UTEST}
    COMMENT "Building Unit Tests"
  )
  add_custom_target(run-utests
    DEPENDS ${TARGETS_UTEST}
    COMMENT "Running Unit Tests"
    COMMAND cmake --build . -t test
  )
endif()

######################################################################################################################################################
# Add targets for documentation generation & publication

if(Doxygen_FOUND)
  # Gen targets
  foreach(DOXINPUT IN ITEMS "lib")
    message(STATUS "Generateing doxygen target for ${DOXINPUT}")
    CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/Doxyfile.cmake ${CMAKE_BINARY_DIR}/doc-${DOXINPUT}/Doxyfile)
    add_custom_target(doc-${DOXINPUT}
      COMMAND ${DOXYGEN_EXECUTABLE} > dox.out
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/doc-${DOXINPUT}
      COMMENT "Generating ${DOXINPUT} documentation with Doxygen"
      VERBATIM)
  endforeach(DOXINPUT)
  # Pub target
  if(EXISTS "c:/Users/richmit/Documents/WWW/site/SS/MRMathCPP/doc-lib/")
    add_custom_target(install-doc-lib
      DEPENDS doc-lib
      COMMAND  rsync -rlt --log-format=%f --stats --delete --delete-excluded --modify-window=2 doc-lib/ /c/Users/richmit/Documents/WWW/site/SS/MRMathCPP/doc-lib
      COMMENT "Put doc-lib data in web site directory"
    )
  endif()
else()
  message("Warning: Doxygen not found.  No documentation targets!")
endif()

######################################################################################################################################################
# Create interface target for the entire project

set(MRMATHCPP_INCLUDES "lib/MRMathBPLY.hpp"
                       "lib/MRMathCPLX.hpp"
                       "lib/MRMathCPP.hpp"
                       "lib/MRMathFC.hpp"
                       "lib/MRMathIVL.hpp"
                       "lib/MRMathLINM.hpp"
                       "lib/MRMathODR.hpp"
                       "lib/MRMathSFUN.hpp"
                       "lib/MRMathSTR.hpp"
                       "lib/MRMathUPLY.hpp"
                       "lib/MRMathVEC.hpp"
                    )
add_library(MRMathCPP INTERFACE ${MRMATHCPP_INCLUDES})
target_include_directories(MRMathCPP INTERFACE
                           "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/lib>"
                           "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/build>"
                           "$<INSTALL_INTERFACE:include>")

######################################################################################################################################################
# Export the library interface cmake file

export(TARGETS MRMathCPP FILE "${CMAKE_BINARY_DIR}/MRMathCPPLib.cmake")

######################################################################################################################################################
# Create Package Files

include(CMakePackageConfigHelpers)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/MRMathCPPConfig.cmake.in"
                              "${CMAKE_CURRENT_BINARY_DIR}/MRMathCPPConfig.cmake"
                              INSTALL_DESTINATION $"{CMAKE_INSTALL_LIBDIR}/cmake/MRMathCPP")

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/MRMathCPPConfigVersion.cmake"
                                 COMPATIBILITY AnyNewerVersion)

######################################################################################################################################################
# Install
#
# This configuration "installs" all the stuff required to build things with MRMathCPP into the export directory:
#  - Non-deprecated Header files
#  - cmake package
#  - cmake export for library

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/build/install")
include(GNUInstallDirs)
install(FILES ${MRMATHCPP_INCLUDES} TYPE INCLUDE)
install(TARGETS MRMathCPP EXPORT MRMathCPPLib)

install(EXPORT MRMathCPPLib
        FILE MRMathCPPLib.cmake
        DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/MRMathCPP")

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/MRMathCPPConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/MRMathCPPConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/MRMathCPP")



# include(GoogleTest)
# gtest_discover_tests(hello_test)
