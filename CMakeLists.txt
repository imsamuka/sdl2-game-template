cmake_minimum_required(VERSION 3.16)


## Create Project
project("Game" VERSION 1.0.0)


## Set Variables
set(ProjectName "${PROJECT_NAME}")
set(Vendor "${CMAKE_SOURCE_DIR}/vendor")
set(Assets "${CMAKE_SOURCE_DIR}/assets")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release")
endif()


# Copy ./assets to ./bin/assets
if(EXISTS ${Assets})
  file(COPY ${Assets} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()



# --------------------------------------------------------------------------
#                              # Create Solution
# --------------------------------------------------------------------------


## Select Files to compile in the binary
file(GLOB_RECURSE src CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")


## Create the target
add_executable(${ProjectName} ${src})


## Target Properties
set_target_properties(${ProjectName} PROPERTIES
  CXX_STANDARD 17
  OUTPUT_NAME "${ProjectName}-[${PROJECT_VERSION}-${CMAKE_BUILD_TYPE}]"
)


## Target Preprocessor Definitions
#target_compile_definitions(${ProjectName} PRIVATE DEBUG=1)


## Include directories
target_include_directories(${ProjectName} PRIVATE
  "${CMAKE_SOURCE_DIR}/include"
)


## Link Libraries
#target_link_libraries(${ProjectName} PRIVATE )


## Install Rules
install(DIRECTORY ${Assets} DESTINATION ".")
install(TARGETS ${ProjectName} DESTINATION ".")
