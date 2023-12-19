#include "trex/scenes/title_scene.h"
#include <BearLibTerminal.h>
void TitleScene::OnCreate() {}
void TitleScene::OnRender() {
  terminal_clear();
  terminal_print(1, 1, "Hello! IT IS BROKEN GAME\n Press Enter to start\n");
  terminal_print(1, 3, "You can take coin and NEVER DIE \n Becouse IT IS BROKEN GAME\n");
  terminal_print(1, 4, "lets eating and gathering gold!");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "game";  // переходим на другую сцену
  }
  terminal_refresh();
}
void TitleScene::OnExit() {}
TitleScene::TitleScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}
