//
// Created by 유승우 on 2020/10/24.
//

#include "doctest_proxy.hpp"

#include <pbrt/util/vecmath.hpp>

using namespace pbrt;

TEST_CASE("[Vector3] - UnitTests") {

    // Default Constructor test
    Vector3<float> zero_vec = Vector3<float>();

    // Create an unit vector unit_vec.
    Vector3<float> unit_vec = Vector3<float>(1.0, 1.0, 1.0);

    // Create an arbitrary vectors vec1, vec2.
    Vector3<float> vec1 = Vector3<float>(1.0, 2.0, 13.0);
    Vector3<float> vec2 = Vector3<float>(2.0, -1.5, 7.2);

    // Element access tests
    CHECK_EQ(zero_vec.x, 0);
    CHECK_EQ(zero_vec.y, 0);
    CHECK_EQ(zero_vec.z, 0);

    // Indexing by operator [] tests
    CHECK_EQ(vec1[0], 1.0f);
    CHECK_EQ(vec1[1], 2.0f);
    CHECK_EQ(vec1[2], 13.0f);

    // Vector addition tests
    Vector3<float> vec3 = vec1 + vec2;
    CHECK_EQ(vec3.x, 3.0f);
    CHECK_EQ(vec3.y, 0.5f);
    CHECK_EQ(vec3.z, 20.2f);

    // Vector subtraction tests
    Vector3<float> vec4 = vec1 - vec2;
    CHECK_EQ(vec4.x, -1.0f);
    CHECK_EQ(vec4.y, 3.5f);
    CHECK_EQ(vec4.z, 5.8f);

    // Vector multiplication tests
    Vector3<float> vec5 = vec1 * 3;
    CHECK_EQ(vec5.x, 3.0f);
    CHECK_EQ(vec5.y, 6.0f);
    CHECK_EQ(vec5.z, 39.0f);

    // Vector division tests
    Vector3<float> vec6 = vec1 / 2;
    CHECK_EQ(vec6.x, (1.0/2));
    CHECK_EQ(vec6.y, (2.0/2));
    CHECK_EQ(vec6.z, (13.0/2));

    // Vector negation tests
    Vector3<float> unit_neg = -unit_vec;
    CHECK_EQ(unit_neg.x, -1.0);
    CHECK_EQ(unit_neg.y, -1.0);
    CHECK_EQ(unit_neg.z, -1.0);

    // LengthSquared and Length functions
    CHECK_EQ(unit_vec.LengthSquared(), 3.0f);
    CHECK_EQ(unit_vec.Length(), sqrt(3.0f));

    /*
     * Tests for inline Vector3 functions
     */
    // Abs function
    Vector3<float> vec2_abs = Abs(vec2);
    CHECK_EQ(vec2_abs.x, 2.0f);
    CHECK_EQ(vec2_abs.y, 1.5f);
    CHECK_EQ(vec2_abs.z, 7.2f);

    // Dot and AbsDot function
    float vec1_Dot_vec2 = Dot(vec1, vec2);
    CHECK_EQ(vec1_Dot_vec2, 1.0f * 2.0f + (2.0f * -1.5f) + 13.0f * 7.2f);
    CHECK_EQ(AbsDot(vec1, vec2), abs(vec1_Dot_vec2));

    // Cross function

    // Normalize function
    Vector3<float> unit_normalized = Normalize(unit_vec);
    CHECK_EQ(unit_normalized.x, 1.0f / sqrt(3.0f));
    CHECK_EQ(unit_normalized.y, 1.0f / sqrt(3.0f));
    CHECK_EQ(unit_normalized.z, 1.0f / sqrt(3.0f));

    // Min & Max Components
    float vec1_min = MinComponent(vec1);
    float vec1_max = MaxComponent(vec1);
    CHECK_EQ(vec1_min, 1.0f);
    CHECK_EQ(vec1_max, 13.0f);

    // Max dimension function
    CHECK_EQ(MaxDimension(vec1), 2);

    // Min & Max functions
    Vector3<float> vec1_Min_vec2 = Min(vec1, vec2);
    Vector3<float> vec1_Max_vec2 = Max(vec1, vec2);

    CHECK_EQ(vec1_Min_vec2.x, 1.0f);
    CHECK_EQ(vec1_Min_vec2.y, -1.5f);
    CHECK_EQ(vec1_Min_vec2.z, 7.2f);

    CHECK_EQ(vec1_Max_vec2.x, 2.0f);
    CHECK_EQ(vec1_Max_vec2.y, 2.0f);
    CHECK_EQ(vec1_Max_vec2.z, 13.0f);

    // TODO: Fix this function!
    // CoordinateSytem test
    /*
    Vector3<float> ortho_vec_0 = Vector3<float>(1.0f, 0, 0);
    Vector3<float>* ortho_vec_1 = nullptr;
    Vector3<float>* ortho_vec_2 = nullptr;

    CoordinateSystem(ortho_vec_0, ortho_vec_1, ortho_vec_2);
    CHECK_EQ(Dot(ortho_vec_0, *ortho_vec_1), 0.0f);
    CHECK_EQ(Dot(ortho_vec_0, *ortho_vec_2), 0.0f);
    CHECK_EQ(Dot(*ortho_vec_1, *ortho_vec_2), 0.0f);
     */
}