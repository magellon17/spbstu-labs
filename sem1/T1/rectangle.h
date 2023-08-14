#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base-types.h"
#include "shape.h"
namespace siobko
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t leftPoint, point_t rightPoint);
    ~Rectangle() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(const double x, const double y) override;
    Shape* clone() const override;

  private:
    point_t leftPoint, rightPoint, centerPoint;
    void doScale(const double k) override;
  };
}
#endif
