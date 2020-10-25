//
// Created by 유승우 on 2020/10/24.
//

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

int main() {
    doctest::Context context;

    // Run queries
    const int result = context.run();

    return result;
}