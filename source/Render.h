#ifndef DRAWER__RENDER_H_
#define DRAWER__RENDER_H_

#include <vector>

#include "Shape.h"
namespace ShapeDrawer {
class Render{
 public:
  static void CreateShapes();
  static void Draw();
 private:
  static std::vector<ShapePtr> shapes_;
};
} // namespace ShapeDrawer


#endif  // DRAWER__RENDER_H_
