#include "trex/systems/rendering_system.h"
#include <BearLibTerminal.h>
#include "lib/ecs/entity_manager.h"
#include "trex/components/texture_component.h"
#include "trex/components/transform_component.h"
#include "trex/math-utils.h"
#include "trex/components/statistic_component.h"

void RenderingSystem::OnUpdate() {
    for (auto& e : GetEntityManager()) {
        if (e.Contains<TransformComponent>() && e.Contains<TextureComponent>()) {
            auto texture = e.Get<TextureComponent>();
            auto transform = e.Get<TransformComponent>();

            terminal_color("white");
            terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
            //std::cout << "RENDERING*** '" << std::endl;
            terminal_color("white");
        }
        if (e.Contains<StatisticComponent>()) {
            terminal_color("yellow");
            auto st = e.Get<StatisticComponent>();
            terminal_printf(1, 1, "Coins %d", st->coins_);
            terminal_printf(1, 2, "Food %d", st->food_);
            terminal_printf(10, 2, "Health %d", st->health_);
            terminal_printf(10,1, "Steps %d", st->steps_);
            terminal_color("white");
            terminal_printf(30, 2, "PRES Q. and u can go next lol)))");
        }
    }
}
void RenderingSystem::OnPreUpdate() {
  terminal_clear();
}
void RenderingSystem::OnPostUpdate() {
  terminal_refresh();
}
RenderingSystem::RenderingSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}
