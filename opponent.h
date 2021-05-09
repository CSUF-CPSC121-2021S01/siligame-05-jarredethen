#ifndef OPPONENT_H
#define OPPONENT_H

#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  
  void Draw(graphics::Image& screen) override;

  void Move(const graphics::Image& screen) override;

 private:
  const graphics::Color kRed{255, 0, 0};
  const graphics::Color kOrange{255, 265, 0};
  const graphics::Color kYellow{255, 255, 0};
  bool going_right_ = true;
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image& screen) override;
  
  void Move(graphics::Image& screen) override;

 private:
  const graphics::Color kOrange{255, 165, 0};
};

#endif
