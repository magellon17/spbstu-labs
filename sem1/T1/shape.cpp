#include "shape.h"
#include <exception>

void siobko::Shape::scale(const double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Invalid scale multiplier");
  }
  doScale(k);
}
