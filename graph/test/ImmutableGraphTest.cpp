#include <gtest/gtest.h>
#include <ImmutableGraph.h>

TEST(ImmutableGraph, makeGraph) {
    ImmutableGraph g1;
    g1.addNode(1, 2, 3, 4, 0);
    g1.addNode(2, 1, 3, 4, 0);
    g1.addNode(3, 1, 2, 4, 0);
    g1.addNode(4, 1, 2, 3, 0);
    g1.lock();

    ImmutableGraph g2;
    g2.addNode(4, 1, 2, 3, 0);
    g2.addNode(3, 1, 2, 4, 0);
    g2.addNode(2, 1, 3, 4, 0);
    g2.addNode(1, 2, 3, 4, 0);   

    EXPECT_EQ(g1, g2);
}