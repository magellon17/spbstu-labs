#include "concave.h"
#include <cmath>
#include <exception>
#include <algorithm>
#include "base-types.h"

siobko::Concave::Concave(const point_t& point1, const point_t& point2,
  const point_t& point3, const point_t& point4) : point1(point1),
  point2(point2), point3(point3), point4(point4), centerPoint(point4)
{
  double triangleSide1 = sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
  double triangleSide2 = sqrt((point3.x - point2.x) * (point3.x - point2.x) + (point3.y - point2.y) * (point3.y - point2.y));
  double triangleSide3 = sqrt((point3.x - point1.x) * (point3.x - point1.x) + (point3.y - point1.y) * (point3.y - point1.y));
  if ((triangleSide1 >= triangleSide2 + triangleSide3) || (triangleSide2 >= triangleSide3 + triangleSide1) ||
    (triangleSide3 >= triangleSide2 + triangleSide1))
  {
    throw std::invalid_argument("Invalid concave parameters");
  }
}
double siobko::Concave::getArea() const
{
  return point1.x * point2.y - point2.x * point1.y + point2.x * point3.y - point3.x * point2.y +
    point3.x * point4.y - point4.x * point3.y + point4.x * point1.y - point1.x * point4.y; // формула гаусса
}
void siobko::Concave::move(const double x, const double y)
{
  point_t diff{ x, y };
  point1 = point1 + diff;
  point2 = point2 + diff;
  point3 = point3 + diff;
  point4 = point4 + diff;
  centerPoint = centerPoint + diff;
}
void siobko::Concave::move(const point_t& newCenter)
{
  point1 = point1 + (newCenter - centerPoint);
  point2 = point2 + (newCenter - centerPoint);
  point3 = point3 + (newCenter - centerPoint);
  point4 = point4 + (newCenter - centerPoint);
  centerPoint = newCenter;
}
siobko::rectangle_t siobko::Concave::getFrameRect() const
{
  double minX = std::min({ point1.x, point2.x, point3.x, point4.x });
  double maxX = std::max({ point1.x, point2.x, point3.x, point4.x });
  double minY = std::min({ point1.y, point2.y, point3.y, point4.y });
  double maxY = std::max({ point1.y, point2.y, point3.y, point4.y });

  rectangle_t rect = { maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2} };
  return rect;
}
void siobko::Concave::doScale(const double k)
{
  point1 = centerPoint + (point1 - centerPoint) * k;
  point2 = centerPoint + (point2 - centerPoint) * k;
  point3 = centerPoint + (point3 - centerPoint) * k;
  point4 = centerPoint + (point4 - centerPoint) * k;
}
siobko::Shape* siobko::Concave::clone() const
{
  return new Concave(point1, point2, point3, point4);
}
