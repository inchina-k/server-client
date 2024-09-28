cmake_minimum_required (VERSION 3.8)

# Hot Reload
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("server-client")

set(BOOST_ROOT "C:/boost_1_86_0")
set(BOOST_INCLUDEDIR "C:/boost_1_86_0/boost")
set(BOOST_LIBRARYDIR "C:/boost_1_86_0/stage/lib")

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory ("server")
add_subdirectory ("client")
