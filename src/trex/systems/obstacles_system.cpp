#include "trex/systems/obstacles_system.h"

#include "lib/ecs/entity_manager.h"
#include "trex/components/obstacle_component.h"
#include "trex/components/transform_component.h"
#include "trex/components/coin_component.h"
#include "trex/components/collider_component.h"
#include "lib/ecs/engine.h"
#include "lib/ecs/system_manager.h"
#include "trex/components/payer_component.h"
#include "trex/components/player_control_component.h"
#include "trex/components/precolider_component.h"
#include "trex/components/movement_component.h"
#include "trex/components/wall_component.h"
#include "trex/components/food_component.h"

/**
 * Пример использования компонента как тэга - ObstacleComponent
 * позволяет отфильтровать сущности по факту наличия возможности столкновения
 */
bool ObstaclesSystem::Filter(const Entity& entity) const {
  return entity.Contains<ObstacleComponent>() && entity.Contains<TransformComponent>();
}

void ObstaclesSystem::OnUpdate() {
    for (auto &entity1: GetEntityManager()) {
        for (auto &entity2: GetEntityManager()) {
            if (entity2.Contains<PlayerControlComponent>()) {
                if (entity1.Contains<CoinComponent>() && entity1.Contains<ColliderComponent>()) {
                    auto cc = entity1.Get<ColliderComponent>();
                    auto mc = entity1.Get<CoinComponent>();
                    auto tc = entity1.Get<TransformComponent>();
                    mc->coin_multi_ = 0;
                    for (const auto &collision: cc->GetCollisions()) {
                        if (collision->Contains<PlayerControlComponent>()) {
                            mc->coin_multi_ = 1;
                            tc->pos_.x = -1;
                            tc->pos_.y = -1;
                        }
                    }
                }
            }
        }
    }
    for (auto &entity1: GetEntityManager()) {
        for (auto &entity2: GetEntityManager()) {
            if (entity2.Contains<PlayerControlComponent>()) {
                if (entity1.Contains<FoodComponent>() && entity1.Contains<ColliderComponent>()) {
                    auto cc = entity1.Get<ColliderComponent>();
                    auto fc = entity1.Get<FoodComponent>();
                    auto tc = entity1.Get<TransformComponent>();
                    fc->food_multi_ = 0;
                    for (const auto &collision: cc->GetCollisions()) {
                        if (collision->Contains<PlayerControlComponent>()) {
                            fc->food_multi_ = 1;
                            tc->pos_.x = 99;
                            tc->pos_.y = 99;
                        }
                    }
                }
            }
        }
    }/*
    for (auto &entity1: GetEntityManager()) {
        for (auto &entity2: GetEntityManager()) {
            if (entity1.Contains<MovementComponent>() && entity1.Contains<PlayerControlComponent>()) {
                auto mc = entity1.Get<MovementComponent>();
                if (entity2.Contains<WallComponent>() && entity2.Contains<PreColliderComponent>()) {
                    auto pc = entity2.Get<PreColliderComponent>();
                    for (const auto &collision: pc->GetCollisionsUp()) {
                        if (collision->Contains<PlayerControlComponent>()) {
                            mc->checkwalkUp_ = false;
                        }
                    }
                    for (const auto &collision: pc->GetCollisionsDown()) {
                        if (collision->Contains<PlayerControlComponent>()) {
                            mc->checkwalkDown_ = false;
                        }
                    }
                    for (const auto &collision: pc->GetCollisionsLeft()) {
                        if (collision->Contains<PlayerControlComponent>()) {
                            mc->checkwalkLeft_ = false;
                        }
                    }
                    for (const auto &collision: pc->GetCollisionsRight()) {
                        if (collision->Contains<PlayerControlComponent>()) {
                            mc->checkwalkRight_ = false;
                        }
                    }
                }
            }
        }
    }*/
}


ObstaclesSystem::ObstaclesSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                               float starting_point)
    : ISystem(entity_manager, system_manager), starting_point_(starting_point) {}
