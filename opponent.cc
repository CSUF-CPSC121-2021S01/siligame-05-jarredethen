#include "opponent.h"
#include <vector>
#include "cpputils/graphics/image.h"

void OpponentProjectile::Draw(graphics::Image& screen) {
  screen.DrawLine(GetX() + 1, GetY(), GetX() + 3, GetY(), darkyellow);
  screen.DrawLine(GetX() + 4, GetY() + 1, GetX() + 4, GetY() + 3, darkyellow);
  screen.DrawLine(GetX() + 3, GetY() + 4, GetX() + 1, GetY() + 4, darkyellow);
  screen.DrawLine(GetX(), GetY() + 3, GetX(), GetY() + 1, darkyellow);

  screen.DrawRectangle(GetX() + 1, GetY() + 1, 3, 3, lightdarkyellow);

  screen.SetColor(GetX() + 2, GetY() + 2, yellow);
}

void Opponent::Draw(graphics::Image& screen) {
  screen.DrawRectangle(GetX() + 17, GetY() + 11, 16, 16, black);
  screen.DrawRectangle(GetX() + 18, GetY() + 12, 14, 14, green);
  screen.DrawRectangle(GetX() + 10, GetY() + 12, 2, 16, green);
  screen.DrawRectangle(GetX() + 10, GetY() + 12, 7, 2, green);
  screen.DrawRectangle(GetX() + 33, GetY() + 12, 7, 2, green);
  screen.DrawRectangle(GetX() + 38, GetY() + 12, 2, 16, green);
  screen.DrawRectangle(GetX() + 20, GetY() + 16, 2, 2, white);
  screen.DrawRectangle(GetX() + 28, GetY() + 16, 2, 2, white);
  screen.DrawRectangle(GetX() + 22, GetY() + 21, 2, 2, black);

  screen.DrawLine(GetX() + 9, GetY() + 11, GetX() + 40, GetY() + 11, black);
  screen.DrawLine(GetX() + 40, GetY() + 11, GetX() + 40, GetY() + 29, black);
  screen.DrawLine(GetX() + 40, GetY() + 29, GetX() + 37, GetY() + 29, black);
  screen.DrawLine(GetX() + 37, GetY() + 29, GetX() + 37, GetY() + 14, black);
  screen.DrawLine(GetX() + 32, GetY() + 14, GetX() + 32, GetY() + 11, black);
  screen.DrawLine(GetX() + 17, GetY() + 11, GetX() + 9, GetY() + 11, black);
  screen.DrawLine(GetX() + 9, GetY() + 11, GetX() + 9, GetY() + 29, black);
  screen.DrawLine(GetX() + 9, GetY() + 29, GetX() + 12, GetY() + 29, black);
  screen.DrawLine(GetX() + 12, GetY() + 29, GetX() + 12, GetY() + 14, black);
  screen.DrawLine(GetX() + 12, GetY() + 14, GetX() + 17, GetY() + 14, black);
  screen.DrawLine(GetX() + 17, GetY() + 14, GetX() + 17, GetY() + 11, black);
  screen.DrawLine(GetX() + 37, GetY() + 14, GetX() + 32, GetY() + 14, black);
  screen.DrawLine(GetX() + 38, GetY() + 28, GetX() + 39, GetY() + 28, red);
  screen.DrawLine(GetX() + 10, GetY() + 28, GetX() + 11, GetY() + 28, red);
  screen.DrawLine(GetX() + 20, GetY() + 13, GetX() + 23, GetY() + 16, black);
  screen.DrawLine(GetX() + 29, GetY() + 13, GetX() + 26, GetY() + 16, black);
  screen.DrawLine(GetX() + 19, GetY() + 15, GetX() + 19, GetY() + 18, black);
  screen.DrawLine(GetX() + 19, GetY() + 18, GetX() + 22, GetY() + 18, black);
  screen.DrawLine(GetX() + 22, GetY() + 18, GetX() + 22, GetY() + 15, black);
  screen.DrawLine(GetX() + 22, GetY() + 15, GetX() + 19, GetY() + 15, black);
  screen.DrawLine(GetX() + 30, GetY() + 15, GetX() + 27, GetY() + 15, black);
  screen.DrawLine(GetX() + 27, GetY() + 15, GetX() + 27, GetY() + 18, black);
  screen.DrawLine(GetX() + 27, GetY() + 18, GetX() + 30, GetY() + 18, black);
  screen.DrawLine(GetX() + 30, GetY() + 18, GetX() + 30, GetY() + 15, black);
  screen.DrawLine(GetX() + 30, GetY() + 15, GetX() + 27, GetY() + 15, black);

  screen.SetColor(GetX() + 21, GetY() + 17, black);
  screen.SetColor(GetX() + 29, GetY() + 17, black);
}

void Opponent::Move(const graphics::Image& screen) {
  if (going_right_ && GetX() + GetWidth() >= screen.GetWidth()) {
    going_right_ = false;
  } else if (!going_right_ && GetX() <= 0) {
    going_right_ = true;
  }
  int offset = going_right_ ? 1 : -1;

  SetX(GetX() + offset * 5);
  SetY(GetY() + 2);

  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}

void OpponentProjectile::Move(const graphics::Image& screen) {
  SetY(GetY() + 3);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}

std::unique_ptr<class OpponentProjectile>
Opponent::LaunchProjectile() {  // **************************
  std::unique_ptr<OpponentProjectile> o_proj;
  Opponent element;
  int i = 0;
  if (i < 10) {
    i++;
    return nullptr;
  } else {
    i = 0;
    o_proj =
        std::make_unique<OpponentProjectile>(element.GetX(), element.GetY());
    return std::move(o_proj);
  }
}
