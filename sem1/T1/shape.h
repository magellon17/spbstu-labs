#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"
namespace siobko
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newCenter) = 0;
    virtual void move(const double x, const double y) = 0;
    void scale(double k);
    virtual Shape* clone() const = 0;

  private:
    virtual void doScale(const double k) = 0;
  };
}
#endif
