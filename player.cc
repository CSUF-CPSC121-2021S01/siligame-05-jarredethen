#include "player.h"
#include <vector>
#include "cpputils/graphics/image.h"

void PlayerProjectile::Draw(graphics::Image &screen) {
  screen.DrawLine(GetX() + 1, GetY(), GetX() + 3, GetY(), darkblue);
  screen.DrawLine(GetX() + 4, GetY() + 1, GetX() + 4, GetY() + 3, darkblue);
  screen.DrawLine(GetX() + 3, GetY() + 4, GetX() + 1, GetY() + 4, darkblue);
  screen.DrawLine(GetX(), GetY() + 3, GetX(), GetY() + 1, darkblue);

  screen.DrawRectangle(GetX() + 1, GetY() + 1, 3, 3, lightdarkblue);

  screen.SetColor(GetX() + 2, GetY() + 2, blue);
}

void Player::Draw(graphics::Image &screen) {
  screen.SetColor(GetX() + 23, GetY() + 10, black);
  screen.SetColor(GetX() + 23, GetY() + 11, black);
  screen.SetColor(GetX() + 22, GetY() + 12, black);
  screen.SetColor(GetX() + 22, GetY() + 13, black);
  screen.SetColor(GetX() + 24, GetY() + 12, black);
  screen.SetColor(GetX() + 24, GetY() + 13, black);
  screen.SetColor(GetX() + 21, GetY() + 14, black);
  screen.SetColor(GetX() + 25, GetY() + 14, black);
  screen.SetColor(GetX() + 26, GetY() + 15, black);
  screen.SetColor(GetX() + 26, GetY() + 16, black);
  screen.SetColor(GetX() + 20, GetY() + 15, black);
  screen.SetColor(GetX() + 20, GetY() + 16, black);
  screen.SetColor(GetX() + 27, GetY() + 17, black);
  screen.SetColor(GetX() + 19, GetY() + 17, black);
  screen.SetColor(GetX() + 18, GetY() + 18, black);
  screen.SetColor(GetX() + 17, GetY() + 18, black);
  screen.SetColor(GetX() + 28, GetY() + 18, black);
  screen.SetColor(GetX() + 29, GetY() + 18, black);
  screen.SetColor(GetX() + 34, GetY() + 20, black);
  screen.SetColor(GetX() + 12, GetY() + 20, black);
  screen.SetColor(GetX() + 9, GetY() + 22, black);
  screen.SetColor(GetX() + 37, GetY() + 22, black);
  screen.SetColor(GetX() + 6, GetY() + 24, black);
  screen.SetColor(GetX() + 40, GetY() + 24, black);
  screen.SetColor(GetX() + 20, GetY() + 29, black);
  screen.SetColor(GetX() + 26, GetY() + 29, black);
  screen.SetColor(GetX() + 23, GetY() + 35, black);

  screen.DrawLine(GetX() + 16, GetY() + 19, GetX() + 14, GetY() + 19, black);
  screen.DrawLine(GetX() + 30, GetY() + 19, GetX() + 32, GetY() + 19, black);
  screen.DrawLine(GetX() + 11, GetY() + 21, GetX() + 10, GetY() + 21, black);
  screen.DrawLine(GetX() + 35, GetY() + 21, GetX() + 36, GetY() + 21, black);
  screen.DrawLine(GetX() + 38, GetY() + 23, GetX() + 39, GetY() + 23, black);
  screen.DrawLine(GetX() + 8, GetY() + 23, GetX() + 7, GetY() + 23, black);
  screen.DrawLine(GetX() + 4, GetY() + 25, GetX() + 11, GetY() + 25, black);
  screen.DrawLine(GetX() + 35, GetY() + 25, GetX() + 42, GetY() + 25, black);
  screen.DrawLine(GetX() + 12, GetY() + 26, GetX() + 14, GetY() + 26, black);
  screen.DrawLine(GetX() + 32, GetY() + 26, GetX() + 34, GetY() + 26, black);
  screen.DrawLine(GetX() + 31, GetY() + 27, GetX() + 30, GetY() + 27, black);
  screen.DrawLine(GetX() + 15, GetY() + 27, GetX() + 16, GetY() + 27, black);
  screen.DrawLine(GetX() + 17, GetY() + 28, GetX() + 19, GetY() + 28, black);
  screen.DrawLine(GetX() + 27, GetY() + 28, GetX() + 29, GetY() + 28, black);
  screen.DrawLine(GetX() + 21, GetY() + 30, GetX() + 21, GetY() + 31, black);
  screen.DrawLine(GetX() + 25, GetY() + 30, GetX() + 25, GetY() + 31, black);
  screen.DrawLine(GetX() + 22, GetY() + 32, GetX() + 22, GetY() + 34, black);
  screen.DrawLine(GetX() + 24, GetY() + 32, GetX() + 24, GetY() + 34, black);

  screen.SetColor(GetX() + 13, GetY() + 23, gray);
  screen.SetColor(GetX() + 33, GetY() + 23, gray);
  screen.SetColor(GetX() + 33, GetY() + 25, gray);
  screen.SetColor(GetX() + 13, GetY() + 25, gray);

  screen.DrawLine(GetX() + 23, GetY() + 12, GetX() + 23, GetY() + 34, gray);
  screen.DrawLine(GetX() + 22, GetY() + 14, GetX() + 22, GetY() + 31, gray);
  screen.DrawLine(GetX() + 24, GetY() + 14, GetX() + 24, GetY() + 31, gray);
  screen.DrawLine(GetX() + 25, GetY() + 15, GetX() + 25, GetY() + 29, gray);
  screen.DrawLine(GetX() + 21, GetY() + 15, GetX() + 21, GetY() + 29, gray);
  screen.DrawLine(GetX() + 20, GetY() + 28, GetX() + 20, GetY() + 17, gray);
  screen.DrawLine(GetX() + 26, GetY() + 28, GetX() + 26, GetY() + 17, gray);
  screen.DrawLine(GetX() + 27, GetY() + 18, GetX() + 27, GetY() + 27, gray);
  screen.DrawLine(GetX() + 19, GetY() + 27, GetX() + 19, GetY() + 18, gray);
  screen.DrawLine(GetX() + 14, GetY() + 20, GetX() + 14, GetY() + 22, gray);
  screen.DrawLine(GetX() + 14, GetY() + 24, GetX() + 14, GetY() + 25, gray);
  screen.DrawLine(GetX() + 32, GetY() + 20, GetX() + 32, GetY() + 22, gray);
  screen.DrawLine(GetX() + 32, GetY() + 24, GetX() + 32, GetY() + 25, gray);
  screen.DrawLine(GetX() + 12, GetY() + 21, GetX() + 12, GetY() + 22, gray);
  screen.DrawLine(GetX() + 12, GetY() + 24, GetX() + 12, GetY() + 25, gray);
  screen.DrawLine(GetX() + 34, GetY() + 21, GetX() + 34, GetY() + 22, gray);
  screen.DrawLine(GetX() + 34, GetY() + 24, GetX() + 34, GetY() + 25, gray);
  screen.DrawLine(GetX() + 9, GetY() + 23, GetX() + 9, GetY() + 24, gray);
  screen.DrawLine(GetX() + 37, GetY() + 23, GetX() + 37, GetY() + 24, gray);
  screen.DrawLine(GetX() + 7, GetY() + 24, GetX() + 8, GetY() + 24, gray);
  screen.DrawLine(GetX() + 38, GetY() + 24, GetX() + 39, GetY() + 24, gray);

  screen.DrawLine(GetX() + 13, GetY() + 15, GetX() + 13, GetY() + 21, red);
  screen.DrawLine(GetX() + 33, GetY() + 15, GetX() + 33, GetY() + 21, red);

  screen.DrawRectangle(GetX() + 17, GetY() + 19, 2, 9, gray);
  screen.DrawRectangle(GetX() + 28, GetY() + 19, 2, 9, gray);
  screen.DrawRectangle(GetX() + 30, GetY() + 20, 2, 7, gray);
  screen.DrawRectangle(GetX() + 15, GetY() + 20, 2, 7, gray);
  screen.DrawRectangle(GetX() + 10, GetY() + 22, 2, 3, gray);
  screen.DrawRectangle(GetX() + 35, GetY() + 22, 2, 3, gray);

  screen.SetColor(GetX() + 13, GetY() + 22, darkgray);
  screen.SetColor(GetX() + 12, GetY() + 23, darkgray);
  screen.SetColor(GetX() + 13, GetY() + 24, darkgray);
  screen.SetColor(GetX() + 14, GetY() + 23, darkgray);
  screen.SetColor(GetX() + 32, GetY() + 23, darkgray);
  screen.SetColor(GetX() + 34, GetY() + 23, darkgray);
  screen.SetColor(GetX() + 33, GetY() + 22, darkgray);
  screen.SetColor(GetX() + 33, GetY() + 24, darkgray);
  screen.SetColor(GetX() + 13, GetY() + 14, darkgray);
  screen.SetColor(GetX() + 33, GetY() + 14, darkgray);
}

void PlayerProjectile::Move(const graphics::Image &screen) {
  SetY(GetY() - 3);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}
