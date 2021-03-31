#include <gtest/gtest.h>
#include <EdgeListGraph.h>

TEST(EdgeListGraph, uniqueEdges) {
    EdgeListGraph g1;
    g1.addEdge(1, 2, 100);
    g1.addEdge(1, 2, 101);
    g1.addEdge(2, 1, 102);

    g1.addEdge(2, 2, 100);
    g1.addEdge(2, 2, 101);

    g1.addEdge(1, 3, 100);
    g1.addEdge(4, 1, 100);
    g1.addEdge(4, 5, 100);
    int c = g1.uniqueEdges();
    EXPECT_EQ(c, 4);

    EdgeListGraph g2;
    g2.addEdge(1, 2, 102);
    g2.addEdge(1, 3, 100);
    g2.addEdge(1, 4, 100);
    g2.addEdge(4, 5, 100);
    EXPECT_EQ(g1, g2);
}