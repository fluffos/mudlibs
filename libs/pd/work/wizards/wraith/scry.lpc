#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_name("blah");
    set_long("blah room");
}

void init() {
    ::init();
add_action("view", "view");
}

int view(string str) {
mixed strr;
    object env;
    if(!str) return notify_fail("Scry who?\n");
    if(!find_player(str)) return notify_fail("No such person.\n");
strr = find_player(str);
    env = environment(strr);
    write(env->query_short()+"\n");
    return 1;
}
