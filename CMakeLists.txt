cmake_minimum_required (VERSION 3.9)

project(MonProjets)

set(SRCS "Coordonnee.cpp" "Coordonnee.hpp" "Plane.cpp" "Plane.hpp")

add_executable (Projets ${SRCS} "main.cpp")

find_package (Threads)

target_compile_features(Projets PUBLIC cxx_std_17)
target_link_libraries (Projets Threads::Threads)