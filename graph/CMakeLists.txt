
add_library(graph 
    src/EdgeListGraph.cpp
    src/ImmutableGraph.cpp 
)

target_include_directories(graph PUBLIC include)

enable_testing()

add_executable(test_graph 
    test/EdgeListGraphTest.cpp
    test/ImmutableGraphTest.cpp 
)

target_include_directories(test_graph PRIVATE include)

target_link_libraries(test_graph
    graph
    libgtest.a
)