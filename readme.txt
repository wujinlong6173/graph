build project : 
    cd build
    cmake ..
    make
    make install
    make clean

run test:
    make test_graph
    cd build/graph
    test_graph.exe
