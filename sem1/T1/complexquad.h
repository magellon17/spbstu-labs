#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include <algorithm>
#include "base-types.h"
#include "shape.h"
namespace siobko
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(point_t lowLeftPoint, point_t upRightPoint, point_t lowRightPoint, point_t upLefttPoint);
    ~Complexquad() = default;

    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(const point_t& p) override;
    void move(const double x, const double y) override;
    Shape* clone() const override;

  private:
    point_t lowLeftPoint, upRightPoint, lowRightPoint, upLeftPoint, centerPoint;
    void doScale(const double k);
  };
}
#endif
