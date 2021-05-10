#ifndef OPPONENT_H
#define OPPONENT_H

#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}

  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image& screen) override;

  void Move(const graphics::Image& screen) override;

 private:
  //  const graphics::Color kOrange{255, 165, 0};
  const graphics::Color darkyellow{95, 99, 20};
  const graphics::Color lightdarkyellow{131, 137, 31};
  const graphics::Color yellow{162, 171, 25};
};

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}

  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& screen) override;

  void Move(const graphics::Image& screen) override;
  
  std::unique_ptr<OpponentProjectile> LaunchProjectile();

 private:
  /*  const graphics::Color kRed{255, 0, 0};
  const graphics::Color kOrange{255, 165, 0};
  const graphics::Color kYellow{255, 255, 0};  */
  const graphics::Color black{0, 0, 0};
  const graphics::Color white{255, 255, 255};
  const graphics::Color red{182, 17, 17};
  const graphics::Color green{13, 88, 25};
  bool going_right_ = true;
};

#endif
