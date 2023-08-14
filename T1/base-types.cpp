#include "base-types.h"

std::istream& siobko::operator>>(std::istream& in, point_t& p)
{
  return (in >> p.x >> p.y);
}
bool siobko::operator<=(const point_t& l, const point_t& r)
{
  return (l.x <= r.x) && (l.y <= r.y);
}
bool siobko::operator==(const point_t& left, const point_t& right)
{
  return left.x == right.x && left.y == right.y;
}
siobko::point_t siobko::operator-(const point_t& l, const point_t& r)
{
  return point_t{ l.x - r.x, l.y - r.y };
}
siobko::point_t siobko::operator+(const point_t& l, const point_t& r)
{
  return point_t{ l.x + r.x, l.y + r.y };
}
siobko::point_t siobko::operator*(const point_t& p, double k)
{
  return point_t{ p.x * k, p.y * k };
}
