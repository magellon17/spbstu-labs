#include "compositeShape.h"
#include <exception>
#include <limits>

siobko::CompositeShape::CompositeShape() : data(new siobko::Shape* [64u]),
size(0u), capacity(64u)
{}
siobko::CompositeShape::CompositeShape(const size_t& size) : data(new siobko::Shape* [size]),
size(0u), capacity(size)
{}
siobko::CompositeShape::CompositeShape(const CompositeShape& other) : data(new siobko::Shape* [other.capacity]),
size(other.size), capacity(other.capacity)
{
  for (size_t i = 0u; i < other.size; ++i)
  {
    push_back(other.data[i]->clone());
  }
}
siobko::CompositeShape::CompositeShape(CompositeShape&& other) noexcept : data(other.data),
size(other.size), capacity(other.capacity)
{
  other.data = nullptr;
  other.size = 0u;
  other.capacity = 0u;
}
siobko::CompositeShape::~CompositeShape()
{
  while (size)
  {
    pop_back();
  }
  delete[] data;
}
siobko::CompositeShape& siobko::CompositeShape::operator=(const CompositeShape& other)
{
  if (this != &other)
  {
    siobko::CompositeShape tmp(other);
    delete[]data;
    data = tmp.data;
    size = tmp.size;
    capacity = tmp.capacity;
  }
  return *this;
}
siobko::CompositeShape& siobko::CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (this != &other)
  {
    delete[] data;
    data = other.data;
    size = other.size;
    capacity = other.capacity;
  }
  return *this;
}
siobko::Shape* siobko::CompositeShape::operator[](size_t i) const
{
  if (i >= size)
  {
    throw std::out_of_range("Invalid compositeShape index");
  }
  return data[i];
}
double siobko::CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0u; i < size; ++i)
  {
    sum += data[i]->getArea();
  }
  return sum;
}
siobko::rectangle_t siobko::CompositeShape::getFrameRect() const
{
  double minX = std::numeric_limits<double>::max();
  double minY = std::numeric_limits<double>::max();
  double maxX = std::numeric_limits<double>::min();
  double maxY = std::numeric_limits<double>::min();
  for (size_t i = 0u; i < size; ++i)
  {
    rectangle_t tmp = data[i]->getFrameRect();
    minX = std::min(minX, tmp.pos.x - tmp.width / 2);
    minY = std::min(minY, tmp.pos.y - tmp.height / 2);
    maxX = std::max(maxX, tmp.pos.x + tmp.width / 2);
    maxY = std::max(maxY, tmp.pos.y + tmp.height / 2);
  }
  return rectangle_t{ maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2} };
}
void siobko::CompositeShape::move(const point_t& newcenter)
{
  for (size_t i = 0u; i < size; ++i)
  {
    data[i]->move(newcenter);
  }
}
void siobko::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0u; i < size; ++i)
  {
    data[i]->move(x, y);
  }
}
void siobko::CompositeShape::scale(const double k)
{
  for (size_t i = 0u; i < size; ++i)
  {
    data[i]->scale(k);
  }
}
siobko::CompositeShape* siobko::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}
void siobko::CompositeShape::push_back(Shape* shp)
{
  if (size >= capacity)
  {
    try {
      addMemory();
    }
    catch (const std::bad_alloc& err) {
      throw std::runtime_error(err.what());
    }
  }
  data[size++] = shp->clone();
}
void siobko::CompositeShape::addMemory()
{
  capacity *= 2u;
  siobko::CompositeShape tmp(capacity);
  for (size_t i = 0u; i < size; ++i) {
    tmp.push_back(data[i]);
  }
  delete[]data;
  data = tmp.data;
}
void siobko::CompositeShape::pop_back()
{
  size--;
  delete data[size];
  data[size] = nullptr;
}
siobko::Shape* siobko::CompositeShape::at(const size_t i) const
{
  if (i >= size)
  {
    throw std::out_of_range("Invalid compositeShape index");
  }
  return data[i];
}
bool siobko::CompositeShape::isEmpty() const
{
  return size == 0u;
}
size_t siobko::CompositeShape::getSize() const
{
  return size;
}
