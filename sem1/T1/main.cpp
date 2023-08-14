#include <iostream>
#include <iomanip>
#include <string>
#include "rectangle.h"
#include "complexquad.h"
#include "concave.h"
#include "compositeShape.h"
#include "shape.h"

int main()
{
  bool isScaled = false;
  std::string shapeName;
  siobko::CompositeShape shapeArray;
  while (std::cin.peek() != EOF)
  {
    siobko::Shape* myShape;
    std::cin >> shapeName;
    if (shapeName == "RECTANGLE")
    {
      siobko::point_t left, right;
      std::cin >> left >> right;
      try
      {
        siobko::Rectangle tmp(left, right);
        myShape = &tmp;
        shapeArray.push_back(myShape);
      }
      catch (const std::exception& err)
      {
        std::cerr << err.what();
        continue;
      }
    }
    else if (shapeName == "CONCAVE")
    {
      siobko::point_t point1, point2, point3, point4;
      std::cin >> point1 >> point2 >> point3 >> point4;
      try
      {
        siobko::Concave concave(point1, point2, point3, point4);
        myShape = &concave;
        shapeArray.push_back(myShape);
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what();
        continue;
      }
    }
    else if (shapeName == "COMPLEXQUAD")
    {
      siobko::point_t lowLeftPoint, upRightPoint, lowRightPoint, upLeftPoint;
      std::cin >> lowLeftPoint >> upRightPoint >> lowRightPoint >> upLeftPoint;
      try
      {
        siobko::Complexquad tmp(lowLeftPoint, upRightPoint, lowRightPoint, upLeftPoint);
        myShape = &tmp;
        shapeArray.push_back(myShape);
      }
      catch (const std::exception& err)
      {
        std::cerr << err.what() << '\n';
        continue;
      }
    }
    else if (shapeName == "SCALE")
    {
      if (shapeArray.isEmpty())
      {
        break;
      }
      std::cout << std::setprecision(1) << std::fixed << shapeArray.getArea();
      for (size_t i = 0u; i < shapeArray.getSize(); ++i)
      {
        siobko::rectangle_t frameRect = shapeArray[i]->getFrameRect();
        std::cout << ' ' << frameRect.pos.x - frameRect.width * 0.5 << ' ' << frameRect.pos.y - frameRect.height * 0.5
          << ' ' << frameRect.pos.x + frameRect.width * 0.5 << ' ' << frameRect.pos.y + frameRect.height * 0.5;
      }
      std::cout << '\n';
      double k;
      siobko::point_t centerPoint;
      std::cin >> centerPoint >> k;
      for (size_t i = 0u; i < shapeArray.getSize(); i++)
      {
        siobko::rectangle_t originalPosition = shapeArray[i]->getFrameRect();
        shapeArray[i]->move(centerPoint);
        siobko::rectangle_t newPosition = shapeArray[i]->getFrameRect();
        double diffX = std::abs(newPosition.pos.x - originalPosition.pos.x) * k;
        double diffY = std::abs(newPosition.pos.y - originalPosition.pos.y) * k;
        shapeArray[i]->move(diffX, diffY);
      }
      try
      {
        shapeArray.scale(k);
      }
      catch (const std::exception& err)
      {
        std::cerr << err.what() << '\n';
        break;
      }
      std::cout << shapeArray.getArea();
      for (size_t i = 0u; i < shapeArray.getSize(); ++i)
      {
        siobko::rectangle_t rect = shapeArray[i]->getFrameRect();
        std::cout << ' ' << rect.pos.x - rect.width / 2 << ' ' << rect.pos.y - rect.height / 2 << ' '
          << rect.pos.x + rect.width / 2 << ' ' << rect.pos.y + rect.height / 2;
      }
      std::cout << '\n';
      isScaled = true;
      break;
    }
    else
    {
      std::cin.ignore();
    }
  }
  if (!isScaled)
  {
    std::cerr << "Scaling error" << '\n';
    return 1;
  }
  return 0;
}
