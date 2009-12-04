#pragma once

struct Force
{
  Force(float x, float y);
  float x, y;
  const Force &operator+=(const Force f);
};
