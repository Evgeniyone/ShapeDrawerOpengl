//
// Created by evgeny on 17.02.23.
//

#include "Render.h"

#include <random>
namespace ShapeDrawer {
std::vector<ShapePtr> Render::shapes_ = {};

void Render::Draw() {
  CreateShapes();
  std::srand(time(0));
  int random_pos = std::rand() % shapes_.size();
  shapes_[random_pos]->Draw();
}
void Render::CreateShapes() {
  ShapeFactory factory;
  shapes_.push_back(factory.createShape<Triangle>(
      TriangleAtributes{0.1, 0.1, 0.3, 0.3, 0.6, 0.1}));
  shapes_.push_back(
      factory.createShape<Square>(SquareAtributes{0.1, 0.1, 0.5}));
  shapes_.push_back(
      factory.createShape<Circle>(CircleAtributes{0.1, 0.1, 0.3}));
  shapes_.push_back(
      factory.createShape<Rectangle>(RectangleAtributes{-0.1, -0.1, 0.7, 0.7}));
}
} // namespace ShapeDrawer

