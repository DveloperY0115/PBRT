#ifndef PBRT_VECMATH_HPP
#define PBRT_VECMATH_HPP

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#include <pbrt/pbrt.h>
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
            return std::isnan(x) || std::isnan(y);
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

        Vector2<T>& operator+=(const Vector2<T> &v) {
            x += v.x;
            y += v.y;
            return *this;
        }

        Vector2<T> operator-(const Vector2<T> &v) const {
            return Vector2(x - v.x, y - v.y);
        }

        Vector2<T>& operator-=(const Vector2<T> &v) {
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

        Vector2<T> operator/(T f) const {
            assert(f != 0);
            float inv = (float) 1 / f;
            return Vector2<T>(x * inv, y * inv);
        }

        Vector2<T>& operator/=(T f) {
            assert(f != 0);
            float inv = (float) 1 / f;
            x *= inv;
            y *= inv;
            return *this;
        }

        Vector2<T> operator-() const {
            return Vector2<T>(-x, -y);
        }

        float LengthSquared() const { return x * x + y * y; }
        float Length() const { return sqrt(LengthSquared()); }
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
            return std::isnan(x) || std::isnan(y) || std::isnan(z);
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
            return Vector3(x + v.x, y + v.y, z + v.z);
        }

        Vector3<T>& operator+=(const Vector3<T> &v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        Vector3<T> operator-(const Vector3<T> &v) const {
            return Vector3<T>(x - v.x, y - v.y, z - v.z);
        }

        Vector3<T>& operator-=(const Vector3<T> &v) {
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

        Vector3<T>& operator/=(T f) {
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

    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;

    template <typename T>
    class Point2 {
    public:
        T x, y;

        Point2() { x = 0; y = 0; }
        Point2(T x, T y)
                : x(x), y(y) {
            assert(!HasNaNs());
        }

        explicit Point2(const Point3<T> &p)
                : x(p.x), y(p.y) {
            assert(!HasNaNs());
        }


        bool HasNaNs() const {
            return isnan(x) || isnan(y);
        }
    };

    typedef Point2<float> Point2f;
    typedef Point2<int> Point2i;

    template <typename T>
    class Point3 {
    public:
        T x, y, z;

        Point3() { x = 0; y = 0; z = 0; }
        Point3(T x, T y, T z)
                : x(x), y(y), z(z) {
            assert(!HasNaNs());
        }

        template <typename U>
        explicit Point3(const Point3<U> &p)
                : x((T)p.x), y((T)p.y), z((T)p.z) {
            assert(!HasNaNs());
        }

        template <typename U>
        explicit operator Vector3<U>() const {
            return Vector3<U>(x, y, z);
        }

        bool HasNaNs() const {
            return isnan(x) || isnan(y) || isnan(z);
        }

        Point3<T> operator+(const Vector3<T> &v) const {
            return Point3<T>(x + v.x, y + v.y, z + v.z);
        }

        Point3<T>& operator+=(const Vector3<T> &v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        Vector3<T> operator-(const Point3<T> &p) const {
            return Vector3<T>(x - p.x, y - p.y, z - p.z);
        }

        Point3<T> operator-(const Vector3<T> &v) const {
            return Point3<T>(x - v.x, y - v.y, z - v.z);
        }

        Point3<T>& operator-=(const Vector3<T> &v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        Point3<T> operator*(const T s) const {
            return Point3<T>(s*x, s*y, s*z);
        }

        Point3<T>& operator*=(const T s) {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        Point3<T> operator/(const T f) const {
            assert(f != 0);
            T inv = 1 / f;
            return Point3<T>(inv * x, inv * y, inv * z);
        }

        Point3<T>& operator/=(const T f) {
            assert(f != 0);
            T inv = 1 / f;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }
    };

    typedef Point3<float> Point3f;
    typedef Point3<int> Point3i;


    // geometry inline functions
    template <typename T>
    inline Vector3<T> operator*(T s, const Vector3<T> &v) {
        return v * s;
    }

    template <typename T>
    inline Vector3<T> operator*(const Vector3<T> &v, T s) {
        return v * s;
    }

    template <typename T>
    inline Vector3<T> Abs(const Vector3<T>& v) {
        return Vector3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
    }

    template <typename T>
    inline T Dot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    template <typename T>
    inline T AbsDot(const Vector3<T> &v1, const Vector3<T> &v2) {
        return std::abs(Dot(v1, v2));
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

    template <typename T>
    inline T MinComponent(const Vector3<T> &v) {
        return std::min(v.x, std::min(v.y, v.z));
    }

    template <typename T>
    inline T MaxComponent(const Vector3<T> &v) {
        return std::max(v.x, std::max(v.y, v.z));
    }

    template <typename T>
    inline int MaxDimension(const Vector3<T> &v) {
        return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) :
               ((v.y > v.z) ? 1 : 2);
    }

    template <typename T>
    inline Vector3<T> Min(const Vector3<T> &p1, const Vector3<T> &p2) {
        return Vector3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
    }

    template <typename T>
    inline Vector3<T> Max(const Vector3<T> &p1, const Vector3<T> &p2) {
        return Vector3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
    }

    template <typename T>
    inline Vector3<T> Permute(const Vector3<T> &v, int x, int y, int z) {
        return Vector3<T>(v[x], v[y], v[z]);
    }

    template <typename T>
    inline void CoordinateSystem(const Vector3<T> &v1, Vector3<T> *v2, Vector3<T> *v3) {
        if (std::abs(v1.x) > std::abs(v1.y)) {
            *v2 = Normalize(Vector3<T>(-1 * v1.z, 0, v1.x));
        }
        else {
            *v2 = Normalize(Vector3<T>(0, v1.z, -1 * v1.y));
        }
        *v3 = Cross(v1, *v2);
    }

    template <typename T>
    inline float Distance(const Point3<T> &p1, const Point3<T> &p2) {
        return (p1 - p2).Length();
    }

    template <typename T>
    inline float DistanceSquared(const Point3<T> &p1, const Point3<T> &p2) {
        return (p1 - p2).LengthSquared();
    }
}

#endif

#endif //PBRT_VECMATH_HPP
