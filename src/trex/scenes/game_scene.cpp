#include "trex/scenes/game_scene.h"
#include <trex/components/collider_component.h>
#include <trex/components/control_component.h>
#include <trex/components/player_control_component.h>
#include <trex/systems/collision_system.h>
#include <trex/systems/game_over_system.h>
#include <trex/systems/control_system.h>
#include "lib/math/vec2.h"
#include "trex/components/movement_component.h"
#include "trex/components/obstacle_component.h"
#include "trex/components/texture_component.h"
#include "trex/components/transform_component.h"
#include "trex/systems/movement_system.h"
#include "trex/systems/obstacles_system.h"
#include "trex/systems/rendering_system.h"
#include "trex/components/statistic_component.h"
#include "trex/components/coin_component.h"
#include "trex/systems/statistic_system.h"
#include "trex/level_reader.h"
#include "trex/systems/precollision_system.h"
#include "trex/components/precolider_component.h"

/**
 * На каждую игровую сцену приходится свой набор сущностей и систем
 * Так, например, здесь у нас есть сущности игрока, кактусов и земли,
 * у каждой сущнности есть свой набор компонентов
 * (обратите внимание, что и аргументы у каждого соответствующие)
 *
 * После инициализации всех сущностей (а они хранятся в движке ECS),
 * происходит инициализация всех необходимых систем. Как и сущности,
 * они хранятся в движке ECS. Благодаря этому, при вызове OnUpdate()
 * у сцены достаточно вызвать только обновление движка ECS
 *
 * После того, как сцена заканчивает свою работу, содержимое движка ECS
 * очищается, чтобы другая сцена могла заполнить его своими компонентам
 * и системами
 */
void GameScene::OnCreate() {

    auto levelReader = std::make_unique<TextLevelReader>();
    levelReader->ReadLevel("/home/trixter/CLionProjects/GameProjectESC/levels/level1", engine.GetEntityManager());
    /*
    {

        auto player = engine.GetEntityManager()->CreateEntity();
        player->Add<TransformComponent>(Vec2(0, 8));
        player->Add<TextureComponent>('@');
        player->Add<MovementComponent>(ZeroVec2, RightVec2);
        player->Add<JumpComponent>(step_size_ , ground_y_);
        player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_RIGHT, TK_LEFT);
        player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
        player->Add<StatisticComponent>(0,0,0);
        player->Add<ObstacleComponent>();
    }

  {
    auto coin = engine.GetEntityManager()->CreateEntity();
    coin->Add<TransformComponent>(Vec2(30, 10));
    coin->Add<TextureComponent>('%');
    coin->Add<ObstacleComponent>();
    coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    coin->Add<CoinComponent>(10);
  }
  {
    auto coin = engine.GetEntityManager()->CreateEntity();
    coin->Add<TransformComponent>(Vec2(55, 8));
    coin->Add<TextureComponent>('%');
    coin->Add<ObstacleComponent>();
    coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    coin->Add<CoinComponent>(10);
  }
  {
    auto coin = engine.GetEntityManager()->CreateEntity();
    coin->Add<TransformComponent>(Vec2(70, 7));
    coin->Add<TextureComponent>('%');
    coin->Add<ObstacleComponent>();
    coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    coin->Add<CoinComponent>(10);
  }

  for (int i = 0; i < width_; i++) {
    auto ground = engine.GetEntityManager()->CreateEntity();
    ground->Add<TransformComponent>(Vec2(i, 5));
    ground->Add<TextureComponent>('#');
  }
    for (int i = 0; i < width_; i++) {
        auto ground = engine.GetEntityManager()->CreateEntity();
        ground->Add<TransformComponent>(Vec2(i, 22));
        ground->Add<TextureComponent>('#');
    }
     */

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<ObstaclesSystem>(width_);
  sys->AddSystem<ControlSystem>(controls);
  sys->AddSystem<CollisionSystem>();
  sys->AddSystem<PrecollisionSystem>();
  //sys->AddSystem<GameOverSystem>(ctx_);
  sys->AddSystem<StatisticSystem>();
}
void GameScene::OnRender() {
  engine.OnUpdate();
  //engine.GetEntityManager()->DeleteEntity(3);
    if (controls.IsPressed(TK_Q)) {
        ctx_->scene_ = "game2";  // Переход на вторую игровую сцену
    }
}
void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene::GameScene(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}

//cactus->Add<MovementComponent>(Vec2(0.25f, 0.0f), LeftVec2);
