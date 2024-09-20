include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(test_RPC RPC.test.cpp ../RPC_core.cpp)

target_link_libraries(test_RPC gtest gtest_main)

enable_testing()

add_test(NAME RPCTests COMMAND test_RPC)
