#ifndef BASETYPES_H
#define BASETYPES_H
#include <iostream>
namespace siobko
{
  struct point_t
  {
    double x, y;
  };
  struct rectangle_t
  {
    double width, height;
    point_t pos;
  };
  std::istream& operator>>(std::istream& in, point_t& p);
  bool operator<=(const point_t& l, const point_t& r);
  bool operator==(const point_t& left, const point_t& right);
  point_t operator-(const point_t& l, const point_t& r);
  point_t operator+(const point_t& l, const point_t& r);
  point_t operator*(const point_t& p, double k);
}
#endif
