#include "force.hpp"

Force::Force(float ax, float ay): x(ax), y(ay) {}

const Force &Force::operator+=(const Force f)
{
  x += f.x;
  y += f.y;
  return *this;
}
