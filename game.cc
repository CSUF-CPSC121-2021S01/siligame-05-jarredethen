#include "game.h"
#include <iostream>
#include "cpputils/graphics/image_event.h"

void Game::Init() {
  player_.SetX(375);
  player_.SetY(500);
  CreateOpponents();
  screen_.AddMouseEventListener(*this);
  screen_.AddAnimationEventListener(*this);
}

void Game::CreateOpponents() {
  for (int i = 0; i < 5; i++) {
    std::unique_ptr<Opponent> opponent =
        std::make_unique<Opponent>(100 * i, 20);
    opponents_.push_back(std::move(opponent));
  }
}

void Game::MoveGameElements() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive()) {
      opponents_[i]->Move(screen_);
    }
  }
  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->GetIsActive()) {
      opponent_projectiles_[i]->Move(screen_);
    }
  }
  for (int i = 0; i < player_projectiles_.size(); i++) {
    if (player_projectiles_[i]->GetIsActive()) {
      player_projectiles_[i]->Move(screen_);
    }
  }
}

void Game::FilterIntersections() {
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive() && player_.GetIsActive() &&
        player_.IntersectsWith(opponents_[i].get())) {
      opponents_[i]->SetIsActive(false);
      player_.SetIsActive(false);
      has_lost_ = true;
    } else {
      for (int j = 0; j < player_projectiles_.size(); j++) {
        if (opponents_[i]->GetIsActive() &&
            player_projectiles_[j]->GetIsActive() &&
            player_projectiles_[j]->IntersectsWith(opponents_[i].get())) {
          opponents_[i]->SetIsActive(false);
          player_projectiles_[j]->SetIsActive(false);
          score_++;
        }
      }
    }
  }
  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->GetIsActive() && player_.GetIsActive() &&
        player_.IntersectsWith(opponent_projectiles_[i].get())) {
      opponent_projectiles_[i]->SetIsActive(false);
      player_.SetIsActive(false);
      has_lost_ = true;
    }
  }
}

void Game::UpdateScreen() {
  screen_.DrawRectangle(0, 0, screen_.GetWidth(), screen_.GetHeight(),
                        graphics::Color(255, 255, 255));
  screen_.DrawText(0, 0, "Score: " + std::to_string(GetScore()), 20,
                   graphics::Color(0, 0, 0));
  if (has_lost_ == true) {
    screen_.DrawText(200, 200, "GAME OVER", 75, graphics::Color(255, 0, 0));
  }
  if (player_.GetIsActive()) {
    player_.Draw(screen_);
  }
  for (int i = 0; i < opponents_.size(); i++) {
    if (opponents_[i]->GetIsActive()) {
      opponents_[i]->Draw(screen_);
    }
  }
  for (int i = 0; i < opponent_projectiles_.size(); i++) {
    if (opponent_projectiles_[i]->GetIsActive()) {
      opponent_projectiles_[i]->Draw(screen_);
    }
  }
  for (int i = 0; i < player_projectiles_.size(); i++) {
    if (player_projectiles_[i]->GetIsActive()) {
      player_projectiles_[i]->Draw(screen_);
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
  if (event.GetMouseAction() == graphics::MouseAction::kPressed ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
    std::unique_ptr<PlayerProjectile> mouseAction =
        std::make_unique<PlayerProjectile>(player_.GetX(), player_.GetY());
    player_projectiles_.push_back(std::move(mouseAction));
  }
}

void Game::OnAnimationStep() {
  if (opponents_.size() == 0) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  screen_.Flush();
}

void Game::LaunchProjectiles() {  // ********************
  for (int i = 0; i < opponents_.size(); i++) {
    std::unique_ptr<OpponentProjectile> o_projectiles =
        opponents_[i]->LaunchProjectile();
    if (o_projectiles != nullptr) {
      opponent_projectiles_.push_back(std::move(o_projectiles));
    }
  }
}

int Game::GetScore() {  // *******************************
  if (!player_.GetIsActive()) {
    return 0;
  } else {
    return score_;
  }
}

void Game::RemoveInactive() {
  for (int i = opponents_.size() - 1; i >= 0; i--) {
    if (!opponents_[i]->GetIsActive()) {
      opponents_.erase(opponents_.begin() + i);
    }
  }
  for (int i = opponent_projectiles_.size() - 1; i >= 0; i--) {
    if (!opponent_projectiles_[i]->GetIsActive()) {
      opponent_projectiles_.erase(opponent_projectiles_.begin() + i);
    }
  }
  for (int i = player_projectiles_.size() - 1; i >= 0; i--) {
    if (!player_projectiles_[i]->GetIsActive()) {
      player_projectiles_.erase(player_projectiles_.begin() + i);
    }
  }
}
