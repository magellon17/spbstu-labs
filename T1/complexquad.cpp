#include "complexquad.h"

siobko::Complexquad::Complexquad(point_t lowLeftPoint, point_t upRightPoint, point_t lowRightPoint,
  point_t upLeftPoint) : lowLeftPoint(lowLeftPoint), upRightPoint(upRightPoint),
  lowRightPoint(lowRightPoint), upLeftPoint(upLeftPoint)
{
  point_t side1(upRightPoint - lowLeftPoint);
  point_t side2(upLeftPoint - lowRightPoint);
  std::pair<double, double> A = { side1.y, side2.y };
  std::pair<double, double> B = { -side1.x, -side2.x };
  std::pair<double, double> C = { lowLeftPoint.y * upRightPoint.x - lowLeftPoint.x * upRightPoint.y,
  lowRightPoint.y * upLeftPoint.x - lowRightPoint.x * upLeftPoint.y };
  double det = A.first * B.second - B.first * A.second;
  double detX = -C.first * B.second + C.second * B.first;
  double detY = -A.first * C.second;
  if (det == 0)
  {
    throw std::invalid_argument("Invalid complexquad parameters");
  }
  centerPoint = { detX / det, detY / det };
  if (centerPoint == lowLeftPoint || centerPoint == upRightPoint ||
    centerPoint == lowRightPoint || centerPoint == upLeftPoint)
  {
    throw std::invalid_argument("Invalid complexquad parameters");
  }
}
double siobko::Complexquad::getArea() const
{
  std::pair<double, double> vectorUL = { upLeftPoint.x - centerPoint.x, upLeftPoint.y - centerPoint.y };
  std::pair<double, double> vectorLL = { lowLeftPoint.x - centerPoint.x, lowLeftPoint.y - centerPoint.y };
  std::pair<double, double> vectorUR = { upRightPoint.x - centerPoint.x, upRightPoint.y - centerPoint.y };
  std::pair<double, double> vectorLR = { lowRightPoint.x - centerPoint.x, lowRightPoint.y - centerPoint.y };
  return (std::abs(vectorUL.first * vectorLL.second - vectorUL.second * vectorLL.first) +
    std::abs(vectorUR.first * vectorLR.second - vectorUR.second * vectorLR.first)) / 2; // гаусс
}
siobko::rectangle_t siobko::Complexquad::getFrameRect() const
{
  double minX = std::min({ lowLeftPoint.x, upRightPoint.x, lowRightPoint.x, upLeftPoint.x });
  double maxX = std::max({ lowLeftPoint.x, upRightPoint.x, lowRightPoint.x, upLeftPoint.x });
  double minY = std::min({ lowLeftPoint.y, upRightPoint.y, lowRightPoint.y, upLeftPoint.y });
  double maxY = std::max({ lowLeftPoint.y, upRightPoint.y, lowRightPoint.y, upLeftPoint.y });
  rectangle_t rect = { maxX - minX, maxY - minY, {maxX - (maxX - minX) / 2, maxY - (maxY - minY) / 2} };
  return rect;
}
void siobko::Complexquad::move(const point_t& newCenterPoint)
{
  point_t diff(newCenterPoint - centerPoint);
  upRightPoint = upRightPoint + diff;
  lowLeftPoint = lowLeftPoint + diff;
  upLeftPoint = upLeftPoint + diff;
  lowRightPoint = lowRightPoint + diff;
  centerPoint = newCenterPoint;
}
void siobko::Complexquad::move(double x, double y)
{
  point_t diff = { x, y };
  upRightPoint = upRightPoint + diff;
  lowLeftPoint = lowLeftPoint + diff;
  upLeftPoint = upLeftPoint + diff;
  lowRightPoint = lowRightPoint + diff;
  centerPoint = centerPoint + diff;
}
void siobko::Complexquad::doScale(const double k)
{
  upRightPoint = centerPoint + (upRightPoint - centerPoint) * k;
  lowLeftPoint = centerPoint + (lowLeftPoint - centerPoint) * k;
  upLeftPoint = centerPoint + (upLeftPoint - centerPoint) * k;
  lowRightPoint = centerPoint + (lowRightPoint - centerPoint) * k;
}
siobko::Shape* siobko::Complexquad::clone() const
{
  return new Complexquad(lowLeftPoint, upRightPoint, lowRightPoint, upLeftPoint);
}
