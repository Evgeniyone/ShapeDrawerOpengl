#ifndef DRAWER__SHAPE_H_
#define DRAWER__SHAPE_H_

#include <memory>

namespace ShapeDrawer {
struct Point2D {
  float x;
  float y;
};
struct RectangleAtributes {
  Point2D point_1;
  Point2D point_2;
};

struct TriangleAtributes {
  Point2D point_1;
  Point2D point_2;
  Point2D point_3;
};

struct CircleAtributes {
  Point2D center;
  float radius;
};

struct SquareAtributes {
  Point2D point;
  float side_length;
};

class Shape {
 public:
  virtual void Draw() = 0;
  virtual ~Shape() = default;
};

class Triangle : public Shape {
 public:
  Triangle(const TriangleAtributes& atributes) : atributes_(atributes) {}
  void Draw() override;
  void SetAtributes(TriangleAtributes atributes) { atributes_ = atributes; }

 private:
  TriangleAtributes atributes_;
};

class Square : public Shape {
 public:
  Square(const SquareAtributes& atributes) : atributes_(atributes) {}
  void Draw() override;
  void SetAtributes(const SquareAtributes& atributes) {
    atributes_ = atributes;
  }

 private:
  SquareAtributes atributes_;
};

class Circle : public Shape {
 public:
  Circle(const CircleAtributes& atributes) : atributes_(atributes) {}
  void Draw() override;
  void SetAtributes(const CircleAtributes& atributes) {
    atributes_ = atributes;
  }

 private:
  CircleAtributes atributes_;
};

class Rectangle : public Shape {
 public:
  Rectangle(const RectangleAtributes& atributes) : atributes_(atributes) {}
  void Draw() override;
  void SetAtributes(const RectangleAtributes& atributes) {
    atributes_ = atributes;
  }

 private:
  RectangleAtributes atributes_;
};

using ShapePtr = std::unique_ptr<Shape>;

class ShapeFactory {
 public:
  template <class T, class Atributes>
  ShapePtr createShape(Atributes atributes) {
    return std::make_unique<T>(atributes);
  }
};
}  // namespace ShapeDrawer

#endif  // DRAWER__SHAPE_H_
