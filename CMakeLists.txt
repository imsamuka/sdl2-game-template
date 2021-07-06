cmake_minimum_required(VERSION 3.16)


## Create Project
project("Game" VERSION 1.0.0)


## Set Variables
set(ProjectName "${PROJECT_NAME}")
set(Vendor "${CMAKE_SOURCE_DIR}/vendor")
set(Assets "${CMAKE_SOURCE_DIR}/assets")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/sdl2")

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release")
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(ModeSuffix "d")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
  set(ModeSuffix "rd")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
  set(ModeSuffix "ms")
else() # Release Mode
  set(ModeSuffix "r")
endif()


# Copy ./assets to ./bin/assets
if(EXISTS ${Assets})
  file(COPY ${Assets} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()


## Find Libraries
find_package(SDL2      )
find_package(SDL2_mixer)
find_package(SDL2_gfx  )
find_package(SDL2_image)
find_package(SDL2_ttf  )
find_package(SDL2_net  )



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
  OUTPUT_NAME "${ProjectName}-[${PROJECT_VERSION}${ModeSuffix}]"
)


## Target Preprocessor Definitions
#target_compile_definitions(${ProjectName} PRIVATE DEBUG=1)


## Include directories
target_include_directories(${ProjectName} PRIVATE
  "${CMAKE_SOURCE_DIR}/include"
  "${Vendor}/entt"
  ${SDL2_INCLUDE_DIRS}
)


## Link Libraries
target_link_libraries(${ProjectName} PRIVATE
  SDL2
  SDL2_mixer
  SDL2_gfx
  SDL2_image
  SDL2_ttf
  SDL2_net
)


## Install Rules
install(DIRECTORY ${Assets} DESTINATION ".")
install(TARGETS ${ProjectName} DESTINATION ".")
