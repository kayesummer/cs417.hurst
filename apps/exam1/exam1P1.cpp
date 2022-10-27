//
// File:    exam1P1.cpp
// Author: Kaylee Hurst  
// Purpose: given two pairs of doubles  x and y with each 
// pair storing x-y coordinates and a pair z with a point to test, returns the value of (a*z0+b*z1-c)
//

#include <utility>
using namespace std;

double pointLocation(pair <double, double> p1, pair <double, double> p2, pair <double, double> testPoint)
{
    auto a = (p2.second - p1.second);
    auto b = (p1.first - p2.first);
    auto c = ((p1.first * p2.second) - (p2.first * p1.second));

    return ((a * testPoint.first) + (b * testPoint.second) - c);
}
