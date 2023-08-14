#include "rectangle.h"
#include <stdexcept>
#include <cmath>

siobko::Rectangle::Rectangle(point_t left, point_t right) : leftPoint(left),
rightPoint(right)
{
  if (right <= left)
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
  centerPoint = (left + right) * 0.5;
}
double siobko::Rectangle::getArea() const
{
  return std::abs((rightPoint.x - leftPoint.x) * (rightPoint.y - leftPoint.y));
}
siobko::rectangle_t siobko::Rectangle::getFrameRect() const
{
  return rectangle_t{ rightPoint.x - leftPoint.x, rightPoint.y - leftPoint.y, centerPoint };
}
void siobko::Rectangle::move(const point_t& destination)
{
  rightPoint = rightPoint + destination - centerPoint;
  leftPoint = leftPoint + destination - centerPoint;
  centerPoint = destination;
}
void siobko::Rectangle::move(const double x, const double y)
{
  point_t diff = { x, y };
  centerPoint = centerPoint + diff;
  leftPoint = leftPoint + diff;
  rightPoint = rightPoint + diff;
}
void siobko::Rectangle::doScale(const double k)
{
  rectangle_t temp = getFrameRect();
  leftPoint = { centerPoint.x - (temp.width * k) / 2 , centerPoint.y - (temp.height * k) / 2 };
  rightPoint = { centerPoint.x + (temp.width * k) / 2 , centerPoint.y + (temp.height * k) / 2 };
}
siobko::Shape* siobko::Rectangle::clone() const
{
  return new Rectangle(leftPoint, rightPoint);
}
