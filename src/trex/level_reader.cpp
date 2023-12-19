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
#include "trex/ilevel-reader.h"
#include "trex/level_reader.h"
#include <iostream>
#include <fstream>
#include "trex/components/precolider_component.h"
#include "trex/systems/precollision_system.h"
#include "trex/components/wall_component.h"
#include "trex/components/food_component.h"
#include "trex/components/payer_component.h"

using namespace std;

void TextLevelReader::ReadLevel(const std::string& filePath, EntityManager* entityManager) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        // Обработка ошибки открытия файла
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    int y = 0;
    while (std::getline(file, line)) {
        //std::cout << "reading start 1" << std::endl;
        for (int x = 0; x < static_cast<int>(line.size()); ++x) {
            //std::cout << "reading start 2" << std::endl;
            char symbol = line[x];
            if (symbol == '@') {
                auto player = entityManager->CreateEntity();
                player->Add<TransformComponent>(Vec2(x, y));
                player->Add<TextureComponent>('@');
                player->Add<MovementComponent>(ZeroVec2, RightVec2);
                player->Add<JumpComponent>(1,2);
                player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_RIGHT, TK_LEFT);
                player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
                player->Add<StatisticComponent>(0, 100, 666);
                player->Add<ObstacleComponent>();
                player->Add<PreColliderComponent>(OnesVec2, ZeroVec2);
                player->Add<PlayerComponent>();
                // std::cout << "player spawned";
            } else if (symbol == '$') {
                auto coin = entityManager->CreateEntity();
                coin->Add<TransformComponent>(Vec2(x, y));
                coin->Add<TextureComponent>('$');
                coin->Add<ObstacleComponent>();
                coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
                coin->Add<CoinComponent>(10);
                // std::cout << "money spawned";
            } else if (symbol == '#') {
                auto wall = entityManager->CreateEntity();
                wall->Add<TransformComponent>(Vec2(x, y));
                wall->Add<TextureComponent>('#');
                wall->Add<PreColliderComponent>(OnesVec2,ZeroVec2);
                wall->Add<WallComponent>();
                // std::cout << "wall spawned";
            } else if (symbol == '%') {
                auto food = entityManager->CreateEntity();
                food->Add<TransformComponent>(Vec2(x, y));
                food->Add<TextureComponent>('%');
                food->Add<ObstacleComponent>();
                food->Add<PreColliderComponent>(OnesVec2, ZeroVec2);
                food->Add<FoodComponent>(20);
                // std::cout << "food spawned";
            }
        }
        ++y;
        // std::cout << "Reading str complite!" << std::endl;
    }
    std::cout << "Reading is end!" << std::endl;

}

