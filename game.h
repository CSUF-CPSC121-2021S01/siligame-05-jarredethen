#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cpputils/graphics/image.h"
#include "opponent.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Game() : Game(800, 600) {}
  Game(int width, int height) : screen_(width, height) {}

  graphics::Image& GetGameScreen() { return screen_; }
  std::vector<Opponent>& GetOpponents() { return opponents_; }
  std::vector<OpponentProjectile>& GetOpponentProjectiles() {
    return opponent_projectiles_;
  }
  std::vector<PlayerProjectile>& GetPlayerProjectiles() {
    return player_projectiles_;
  }

  Player& GetPlayer() { return player_; }

  void Init();
  void CreateOpponents();
  void CreateOpponentProjectiles();
  void CreatePlayerProjectiles();
  void MoveGameElements();
  void FilterIntersections();
  void UpdateScreen();
  void Start();
  void OnMouseEvent(const graphics::MouseEvent& event) override;
  void OnAnimationStep() override;

 private:
  graphics::Image screen_;
  std::vector<Opponent> opponents_;
  std::vector<OpponentProjectile> opponent_projectiles_;
  std::vector<PlayerProjectile> player_projectiles_;
  Player player_;
};

#endif
