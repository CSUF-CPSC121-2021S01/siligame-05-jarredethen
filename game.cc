#include "game.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void Game::Init() {
  player_.SetX(375);
  player_.SetY(500);
  CreateOpponents();
  CreateOpponentProjectiles();
  CreatePlayerProjectiles();
  screen_.AddMouseEventListener(*this);
  screen_.AddAnimationEventListener(*this);
}

void Game::CreateOpponents() {
  for (int i = 0; i < 5; i++) {
    Opponent opponent(100 * i, 20) 
    opponents_.push_back(opponent);
  }
}

void Game::CreateOpponentProjectiles() {
  for (int i = 0; i < 5; i++) {
    OpponentProjectile o_proj(100 * i, 100);
    opponent_projectiles_.push_back(o_proj);
  }
}

void Game::CreatePlayerProjectiles() {
  for (int i = 0; i < 5; i++) {
    PlayerProjectile p_proj(100 * i, 450);
    player_projectiles_.push_back(p_proj);
  }
}

void Game::MoveGameElements() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i].GetIsActive()) {
      opponents_[i].Move(screen_);
    }
  }
  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i].GetIsActive()) {
      opponent_projectiles_[i].Move(screen_);
    }
  }
  for (int i = 0; i < player_projectiles_.size(); i++) {
    if (player_projectiles_[i].GetIsActive()) {
      player_projectiles_[i].Move(screen_);
    }
  }
}

void Game::FilterIntersections() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i].GetIsActive() && player_.GetIsActive() &&
      player_.IntersectsWith(opponents_[i])) {
        opponents_.erase(opponents_.begin() + i);
        opponents_[i].SetIsActive(false);
        player_.SetIsActive(false);
      } else {
        for (int j = 0; j < player_projectiles_.size(); j++) {
          if (opponents_[i].GetIsActive() &&
              player_projectiles_[j].GetIsActive() &&
              player_projectiles_[j].IntersectsWith(opponents_[i])) {
            opponents_[i].SetIsActive(false);
            player_projectiles_[j].SetIsActive(false);
          }
        }
      }
    }
    for (int i = 0; i < opponent_projectiles_.size(); i++) {
      if (opponent_projectiles_[i].GetIsActive() && player_.GetIsActive() &&
          player_.IntersectsWith(opponent_projectiles_[i])) {
        opponent_projectiles_[i].SetIsActive(false);
        player_.SetIsActive(false);
      }
    }
}

void Game::UpdateScreen() {
  screen_.DrawRectangle(0, 0, screen_.GetWidth(), screen_.GetHeight(), graphics::Color(255, 255, 255));
  if (player_.GetIsActive()) {
    player_.Draw(screen_);
  }
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i].GetIsActive()) {
      opponents_[i].Draw(screen_);
    }
  }
  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i].GetIsActive()) {
      opponent_projectiles_[i].Draw(screen_);
    }
  }
  for (int i = 0; i < player_projectiles_.size(); i++) {
    if (player_projectiles_[i].GetIsActive()) {
      player_projectiles_[i].Draw(screen_);
    }
  }
}

void Game::Start() { screen_.ShowUntilClosed(); }

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  if (event.GetMouseAction() == graphics::MouseAction::kMoved ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
        int nx = event.GetX() - player_.GetWidth() / 2;
        int ny = event.GetY() - player_.GetHeight() / 2;
        int ox = player_.GetX();
        int oy = player_.GetY();

        player_.SetX(nx);
        player_.SetY(ny);

        if (player_.IsOutOfBounds(screen_)) {
          player_.SetX(ox);
          player_.SetY(oy);
        }
      }
}

void game::OnAnimationStep() {
  MoveGameElements();
  FilterIntersections();
  UpdateScreen();
  screen_.Flush();
}
