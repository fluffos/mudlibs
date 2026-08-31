#include <std.h>

inherit OBJECT;
void init() {
    ::init();
    add_action("look_picture", "look");
}
void create() {
    set_name("Picture");
    set("id", ({ "picture" }) );
    set_short("A Picture");
    set("long", "This is a visage of what most of the people who step into this office get to see.");
    set_prevent_get("");
}
int look_picture(string str) {
    if(!str) {
        notify_fail("look at what?\n");
        return 0;

    }
    if(str != "picture") {
        notify_fail("You can't look at that!\n");
        return 0;
    }
    

    write(@ENDTEXT
                               ,-.
          ___,---.__          /'|`\          __,---,___
       ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
     ,'        |           ~'\     /`~           |        `.
    /      ___//              `. ,'          ,  , \___      \
   |    ,-'   `-.__   _         |        ,    __,-'   `-.    |
   |   /          /\_  `   .    |    ,      _/\          \   |
   \  |           \ \`-.___ \   |   / ___,-'/ /           |  /
    \  \           | `._   `\\  |  //'   _,' |           /  /
     `-.\         /'  _ `---'' , . ``---' _  `\         /,-'
        ``       /     \    ,='/ \`=.    /     \       ''
                |__   /|\_,--.,-.--,--._/|\   __|
                /  `./  \\`\ |  |  | /,//' \,'  \
               /   /     ||--+--|--+-/-|     \   \
              |   |     /'\_\_\ | /_/_/`\     |   |
               \   \__, \_     `~'     _/ .__/   /
                `-._,-'   `-._______,-'   `-._,-'
ENDTEXT);


   return 1;
}
int get() { return 0; }
