#pragma once

#include "glm/glm.hpp"
#include <algorithm>
#include <istream>
#include <ostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#define PI                3.1415926535897932384626422832795028841971f
#define TWO_PI            6.2831853071795864769252867665590057683943f
#define InvPi             0.31830988618379067154;
#define Inv2Pi            0.15915494309189533577;
#define PiOver2           1.57079632679489661923;
#define PiOver4           0.78539816339744830961;
#define Sqrt2             1.41421356237309504880;
#define SQRT_OF_ONE_THIRD 0.5773502691896257645091487805019574556476f
#define EPSILON           0.00001f

namespace utilityCore {
    extern float clamp(float f, float min, float max);
    extern bool replaceString(std::string& str, const std::string& from, const std::string& to);
    extern glm::vec3 clampRGB(glm::vec3 color);
    extern bool epsilonCheck(float a, float b);
    extern std::vector<std::string> tokenizeString(std::string str);
    extern glm::mat4 buildTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);
    extern std::string convertIntToString(int number);
    extern std::istream& safeGetline(std::istream& is, std::string& t); //Thanks to http://stackoverflow.com/a/6089413
}

inline int ilog2(int x) {
    int lg = 0;
    while (x >>= 1) {
        ++lg;
    }
    return lg;
}

inline int ilog2ceil(int x) {
    return x == 1 ? 0 : ilog2(x - 1) + 1;
}
//from 561 hw
inline float CosTheta(const glm::vec3 &w) { return w.z; }
inline float Cos2Theta(const glm::vec3 &w) { return w.z * w.z; }
inline float AbsCosTheta(const glm::vec3 &w) { return std::abs(w.z); }
inline float Sin2Theta(const glm::vec3 &w) {
    return std::max((float)0, (float)1 - Cos2Theta(w));
}
