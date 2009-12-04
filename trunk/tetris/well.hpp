#pragma once

class Painter;
class Tetromino;

class Well
{
public:
  Well();
  // рисует колодец на рисовальщике Painter
  void draw(Painter &) const;
  // проверка на столкновения тетромины с 
  // блоками в колодце
  bool isCollision(const Tetromino &) const;
  // перенос тетромины в колодец
  void unite(const Tetromino &);
  // удаление полностью заполненых строки
  int removeSolidLines();
private:
  bool map_[20][10];
};
