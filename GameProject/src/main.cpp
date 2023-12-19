#include <BearLibTerminal.h>
#include <string>

#include "./obj-manager.h"
#include "./i-level-reader.h"
#include "./text-level-reader.h"

int main() {
    terminal_open();
    terminal_refresh();

    bool game_over = false;
    const std::string LEVEL_FILE_PATH = "/home/trixter/CLionProjects/GameProject/levels/level1";

    Control control;
    Player player{control, 10, 10};
    ObjectManager objectManager{&player};

    ILevelReader* levelReader = new TextLevelReader(LEVEL_FILE_PATH);
    levelReader->readLevel(objectManager);
    //  delete levelReader;

    while (!control.IsExit() && !game_over) {
        terminal_clear();

        control.Update();
        player.Update();
        objectManager.Update();

        terminal_printf(1, 0, "steps: %d", player.GetStep());
        terminal_printf(1, 1, "coins: %d", player.GetCoinsCollected());
        terminal_printf(1, 2, "hunger: %d", player.GetHunger());

        if (player.IsDead()) {
            terminal_color("red");
            terminal_printf(1, 2, "Died of hunger!!!");
            terminal_color("white");
            game_over = true;
        } else {
            if (player.GetHunger() < 50) {
                terminal_color("yellow");
                if (player.GetHunger() < 20) {
                    terminal_color("red");
                }
            }
            terminal_printf(1, 2, "hunger: %d", player.GetHunger());
            terminal_color("white");
        }

        terminal_refresh();
    }
    terminal_read();
    terminal_close();
    return 0;
}
