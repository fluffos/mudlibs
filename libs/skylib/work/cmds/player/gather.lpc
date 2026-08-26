
#include <move_failures.h>

inherit COMMAND_BASE;

// #define NO_DECAY 1

mixed cmd(string str) {
    object *items, *moved = ({ }), *left = ({ });
    int i;

    //printf("str = %O\n", str);
    if (!stringp(str) || (str == ""))
        return notify_fail("Syntax: gather <plant>\n");
    items = "/handlers/gathering"->gather_item(str, TP);
    //printf("items = %O\n", items);
    if (!sizeof(items))
        return notify_fail("You couldn't find any " + str + ".\n");
    for (i = 0; i < sizeof(items); i++) {
        if (items[i]->move(TP) == MOVE_OK) {
            moved += ({ items[i] });
        } else if (items[i]->move(environment(TP)) == MOVE_OK) {
            left += ({ items[i] });
        } else {
            items[i]->move("/room/rubbish");
        }
    }
    if (sizeof(moved)) {
#ifdef NO_DECAY
        moved->set_decay_speed(0);
#endif
        write("You gather " + query_multiple_short(moved) + ".\n");
        say(TP->short() + " gathers some things.\n");
        event( environment( this_player() ), "gather",
          this_player(), str, moved );
    }
    if (sizeof(left))
        write("You found but couldn't get " + query_multiple_short(left) +
          ".\n");
    return 1;
}
