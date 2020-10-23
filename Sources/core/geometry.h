//
// Created by 유승우 on 2020/10/23.
//

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_CORE_GEOMETRY_H
#define PBRT_CORE_GEOMETRY_H

#include "pbrt.h"
#include <iterator>
#include <assert.h>

namespace pbrt {

    template <typename T>
    class Vector2 {
    public:
        T x, y;

        /*
         * Default Constructor
         * Create a Vector2 instance and
         * initialize all elements to 0.
         */
        Vector2() { x = 0; y = 0; }

        /*
         * Constructor with initial values
         */
        Vector2(T x, T y) : x(x), y(y) {
            assert(!HasNaNs());
        }

        bool HasNaNs() const {
            return isnan(x) || isnan(y);
        }

        T operator[](int i) const {
            assert(i >= 0 && i <= 1);
            if (i == 0) return x;
            return y;
        }

        T& operator[](int i) {
            assert(i >= 0 && i <= 1);
            if (i == 0) return x;
            return y;
        }

        Vector2<T> operator+(const Vector2<T> &v) const {
            return Vector2(x + v.x, y + v.y);
        }

        Vector2<T>& operator+(const Vector2<T> &v) {
            x += v.x;
            y += v.y;
            return *this;
        }

        Vector2<T> operator-(const Vector2<T> &v) const {
            return Vector2(x - v.x, y - v.y);
        }

        Vector2<T>& operator-(const Vector2<T> &v) {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        Vector2<T> operator*(T s) const {
            return Vector2<T>(s*x, s*y);
        }

        Vector2<T>& operator*=(T s) {
            x *= s;
            y *= s;
            return *this;
        }
    };

    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;

    template <typename T>
    class Vector3 {
    public:
        T x, y, z;

        /*
         * Default Constructor
         * Create a Vector3 instance and
         * initialize all element to 0.
         */
        Vector3() { x = 0; y = 0; z = 0; }

        /*
         * Constructor with initial values
         */
        Vector3(T x, T y, T z) : x(x), y(y), z(z) {
            assert(!HasNaNs());
        }

        bool HasNaNs() const {
            return isnan(x) || isnan(y) || isnan(z);
        }

        T operator[](int i) const {
            assert(i >= 0 && i <= 2);
            if (i == 0) return x;
            if (i == 1) return y;
            return z;
        }

        T& operator[](int i) {
            assert(i >= 0 && i <= 2);
            if (i == 0) return x;
            if (i == 1) return y;
            return z;
        }

        Vector3<T> operator+(const Vector3<T> &v) const {
            return Vector3(x + v.x, y + v.y + z + v.z);
        }

        Vector3<T>& operator+(const Vector3<T> &v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        Vector3<T> operator-(const Vector3<T> &v) const {
            return Vector3(x - v.x, y - v.y + z - v.z);
        }

        Vector3<T>& operator-(const Vector3<T> &v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        Vector3<T> operator*(T s) const {
            return Vector3<T>(s*x, s*y, s*z);
        }

        Vector3<T>& operator*=(T s) {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        Vector3<T> operator/(T f) const {
            assert(f != 0);
            float inv = (float) 1 / f;
            return Vector3<T>(x * inv, y * inv, z * inv);
        }

        Vector3<T>& operator/(T f) {
            assert(f != 0);
            float inv = (float) 1 / f;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

        Vector3<T> operator-() const {
            return Vector3<T>(-x, -y, -z);
        }

        float LengthSquared() const { return x * x + y * y + z * z; }
        float Length() const { return sqrt(LengthSquared()); }
    };

    template <typename T>
    inline Vector3<T> operator*(T s, const Vector3<T> &v) {
        return v * s;
    }

    template <typename T>
    inline Vector3<T> Abs(const Vector3<T>& v) {
        return Vector3<T>(abs(v.x), abs(v.y), abs(v.z));
    }

    template <typename T>
    inline T Dot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    template <typename T>
    inline T AbsDot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return abs(Dot(v1, v2));
    }

    template <typename T>
    inline Vector3<T> Cross(const Vector3<T> &v1, const Vector3<T> &v2) {
        double v1x = v1.x, v1y = v1.y, v1z = v1.z;
        double v2x = v2.x, v2y = v2.y, v2z = v2.z;
        return Vector3<T>((v1y * v2z) - (v1z * v2y),
                          (v1z * v2x) - (v1x * v2z),
                          (v1x * v2y) - (v1y * v2x));
    }

    template <typename T>
    inline Vector3<T> Normalize(const Vector3<T> &v) {
        return v / v.Length();
    }
    
    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;

}

#endif