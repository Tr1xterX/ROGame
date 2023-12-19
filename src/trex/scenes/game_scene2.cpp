#include "trex/scenes/game_scene2.h"
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
void GameScene2::OnCreate() {
    auto levelReader = std::make_unique<TextLevelReader>();
    levelReader->ReadLevel("/home/trixter/CLionProjects/GameProjectESC/levels/level2", engine.GetEntityManager());

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<PrecollisionSystem>();
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<ObstaclesSystem>(width_);
  sys->AddSystem<ControlSystem>(controls);
  sys->AddSystem<CollisionSystem>();
  //sys->AddSystem<GameOverSystem>(ctx_);
  sys->AddSystem<StatisticSystem>();
}
void GameScene2::OnRender() {
  engine.OnUpdate();
    if (controls.IsPressed(TK_Q)) {
        ctx_->scene_ = "game";  // Переход на вторую игровую сцену
    }
}
void GameScene2::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene2::GameScene2(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}

//cactus->Add<MovementComponent>(Vec2(0.25f, 0.0f), LeftVec2);
