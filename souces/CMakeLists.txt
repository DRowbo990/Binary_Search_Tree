
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
if(WIN32) 
  add_compile_options(/W4 /WX) 
else() 
  add_compile_options(-Wall -Wextra -Wpedantic -Werror) 
endif()
project(BST)
add_library(BSTLib STATIC
  BST.hpp
  )
set_target_properties(BSTLib PROPERTIES LINKER_LANGUAGE CXX)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(BSTTest
  BSTTestGiven.cpp
  BSTTestOwn.cpp
  BSTTestGrader.cpp
  )
target_link_libraries(BSTTest INTERFACE BSTLib PUBLIC gtest_main)
install(TARGETS BSTTest DESTINATION "dist")
include(GoogleTest)
gtest_discover_tests(BSTTest)