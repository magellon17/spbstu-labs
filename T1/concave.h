#ifndef CONCAVE_H
#define CONCAVE_H
#include "base-types.h"
#include "shape.h"
namespace siobko
{
  class Concave: public Shape
  {
  public:
    Concave(const point_t& point1, const point_t& point2,
      const point_t& point3, const point_t& point4);
    ~Concave() = default;

    double getArea() const override;
    void move(const point_t& newCenter) override;
    void move(const double x, const double y) override;
    rectangle_t getFrameRect() const override;
    Shape* clone() const override;

  private:
    point_t point1, point2, point3, point4, centerPoint;
    void doScale(const double k) override;
  };
}
#endif
