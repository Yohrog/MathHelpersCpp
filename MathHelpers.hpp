#pragma once

// Doesn't include M_PI on some platforms. For those cases include "math.h" instead.
#include <cmath>

template <typename T>
inline int signum(T val) {
    return (T(0) < val) - (val < T(0));
}

inline float wrapAngleRadians(float angle) {
    if (angle <= M_PI && angle > -M_PI)
        return angle;
    else if (std::signbit(angle))
        return -(static_cast<float>(M_PI) - fmodf(-angle, M_PI));
    else
        return static_cast<float>(M_PI) - fmodf(angle, M_PI);
}

inline float wrapAngleDegrees(float angle) {
    if (angle <= 180.f && angle > -180.f)
        return angle;
    else if (std::signbit(angle))
        return -(180.f - fmodf(-angle, 180.f));
    else
        return 180.f - fmodf(angle, 180.f);
}

inline float radians(const float angle) {
    return wrapAngleRadians(angle * 0.0174532939162f);
}

inline float degrees(const float angle) {
    return angle * static_cast<float>(180.f/M_PI);
}

inline float squared(float x) {
    return x * x;
}

inline float cubed(float x) {
    return x * x * x;
}

inline float smoothStop(float t) {
    return 1 - cubed(1 - t);
}

inline float linearInterpolate(float a, float b, float alpha) {
    return a * (1 - alpha) + b * alpha;
}

inline float smoothStep(float t) {
    return linearInterpolate(squared(t), smoothStop(t), t);
}