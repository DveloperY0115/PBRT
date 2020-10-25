//
// Created by 유승우 on 2020/10/24.
//

#include "doctest_proxy.hpp"

#include <../../PBRT/Sources/core/geometry.h>

using namespace pbrt;

TEST_CASE("[Vector3] - UnitTests") {

    // Default Constructor test
    Vector3<float> zero_vec = Vector3<float>();

    // Create an unit vector unit_vec.
    Vector3<float> univ_vec = Vector3<float>(1.0, 1.0, 1.0);

    // Create an arbitrary vectors vec1, vec2.
    Vector3<float> vec1 = Vector3<float>(1.0, 2.0, 13.0);
    Vector3<float> vec2 = Vector3<float>(2.0, -1.5, 7.2);
    Vector3<float> vec3 = vec1 + vec2;

    // Element access tests
    CHECK_EQ(zero_vec.x, 0);
    CHECK_EQ(zero_vec.y, 0);
    CHECK_EQ(zero_vec.z, 0);

    // Indexing by operator [] tests
    CHECK_EQ(vec1[0], 1.0);
    CHECK_EQ(vec1[1], 2.0);
    CHECK_EQ(vec1[2], 13.0);

    // Vector addition tests
    CHECK_EQ(vec3.x, 3.0);
    CHECK_EQ(vec3.y, 0.5);
    CHECK_EQ(vec3.z, 20.2);

}