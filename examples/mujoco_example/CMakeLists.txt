cmake_minimum_required(VERSION 3.5)
project(Local_Quadruped)

# These files are either under /Repo/ or /usr/local/include
find_package(osqp REQUIRED)
find_package(mujoco REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(OsqpEigen REQUIRED)

include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})
include_directories(include)

#add_library(jason SHARED)
#target_sources(jason PRIVATE
    # src/my_file.cpp
#)
#target_include_directories(jason PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the executable
add_executable(MujocoExample src/MujocoExample.cpp)
target_include_directories(MujocoExample PUBLIC include)
target_link_libraries(MujocoExample PUBLIC stdc++ stdc++fs m osqp::osqp mujoco::mujoco OsqpEigen::OsqpEigen glfw) 
# target_link_libraries(main PUBLIC stdc++ stdc++fs m osqp::osqp mujoco::mujoco orlqp::orlqp glfw)