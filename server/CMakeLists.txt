add_executable (server "server.cpp" "main.cpp" "storage.cpp")

set_property(TARGET server PROPERTY CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(json)

target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json)

