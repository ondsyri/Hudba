# CMakeList.txt : CMake project for auta_cvic11, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (auta_cvic11 "Auta.cpp" "Auta.h" "AutaDB.cpp" "AutaDB.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET auta_cvic11 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
