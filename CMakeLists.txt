cmake_minimum_required(VERSION 3.12)
project(MyExampleProject)

# Add the source files in the example folder
file(GLOB TEST_C ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_c.cpp)
file(GLOB DEMO ${CMAKE_CURRENT_SOURCE_DIR}/demo.cpp)


# Create an executable
# add_executable(test_c ${TEST_C})
add_executable(demo ${DEMO})


# Include the ALGLIB source files directly
file(GLOB ALGLIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# # Add the ALGLIB source files to the test_c executable
# target_sources(test_c PRIVATE ${ALGLIB_SRC})

# # Include directories if needed
# target_include_directories(test_c PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the ALGLIB source files to the test_c executable
target_sources(demo PRIVATE ${ALGLIB_SRC})

# Include directories if needed
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

