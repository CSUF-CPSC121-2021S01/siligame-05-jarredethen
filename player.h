#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : PlayerProjectile(0, 0) {}

  PlayerProjectile(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& screen) override;

  void Move(const graphics::Image& screen) override;

 private:
  //  const graphics::Color kBlue{0, 0, 255};
  const graphics::Color darkblue{30, 24, 135};
  const graphics::Color lightdarkblue{41, 31, 193};
  const graphics::Color blue{63, 52, 227};
};

class Player : public GameElement {
 public:
  Player() : Player(0, 0) {}

  Player(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image& screen) override;

  void Move(const graphics::Image& screen) override {}

 private:
  /*  const graphics::Color kBlack{0, 0, 0};
  const graphics::Color kGreen{0, 255, 0};
  const graphics::Color kRed{255, 0, 0};
  const graphics::Color kBlue{0, 0, 255};  */
  const graphics::Color black{255, 255, 255};
  const graphics::Color gray{43, 43, 43};
  const graphics::Color red{182, 17, 17};
  const graphics::Color darkgray{15, 14, 14};

};

#endif
