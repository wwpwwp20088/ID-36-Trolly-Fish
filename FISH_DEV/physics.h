#ifndef PHYSICS_H
#define PHYSICS_H

#include <Arduino.h>

// left edge is 1 pixel left offscreen
#define LEFT_EDGE (Rect){ -1, 0, 1, 64}
// right edit is 1 pixel right offscreen
#define RIGHT_EDGE (Rect){ 128, 0, 1, 64}
// top edge is 1 pixel offscreen below top
#define TOP_EDGE (Rect) {0, -1, 128, 1}
// bottom edge is 1 pixel offscreen below bottom
#define BOTTOM_EDGE (Rect){ 0, 64, 128, 1}

struct Rect
{
public:
    int x;
    int y;
    uint8_t width;
    uint8_t height;
};

struct Point
{
public:
    int x;
    int y;
};


class Physics
{
  public:
    bool static collide(Point point, Rect rect);
    bool static collide(Rect rect, Rect rect2);
};

bool Physics::collide(Point point, Rect rect)
{
  // does point fall within the bounds of rect
  return ((point.x >= rect.x) && (point.x < rect.x + rect.width) &&
      (point.y >= rect.y) && (point.y < rect.y + rect.height));
}

bool Physics::collide(Rect rect1, Rect rect2)
{
  return !( rect2.x                 >=  rect1.x+rect1.width    ||
            rect2.x + rect2.width   <=  rect1.x                ||
            rect2.y                 >=  rect1.y + rect1.height ||
            rect2.y + rect2.height  <=  rect1.y);
}
#endif
