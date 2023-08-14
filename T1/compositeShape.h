#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"
namespace siobko
{
  class CompositeShape
  {
  public:
    CompositeShape();
    explicit CompositeShape(const size_t& size);
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    ~CompositeShape();

    void push_back(Shape* shp);
    void pop_back();
    void move(const point_t& other);
    void move(const double x, const double y);
    void scale(const double k);
    Shape* operator[](const size_t i) const;
    Shape* at(const size_t i) const;
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    CompositeShape* clone() const;
    bool isEmpty() const;
    size_t getSize() const;
    double getArea() const;
    rectangle_t getFrameRect() const;

  private:
    Shape** data;
    size_t size;
    size_t capacity;
    void addMemory();
  };
}
#endif
