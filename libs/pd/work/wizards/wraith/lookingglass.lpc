#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("A looking glass");
   set_short("A looking glass");
   set_long("Looking at the glass, it seems that you could be swallowed whole. Framed with gold and silver this strange looking object can be used to <find> certain people.");
   set_value(0);
   set_weight(500);
   set_id(({ "glass" }));
}

void init() {
    ::init();
add_action("find", "find");
}

int look(string str) {
mixed strr;
    object env;
    if(!str) return notify_fail("Find whom?\n");
    if(!find_player(str)) return notify_fail("No such person.\n");
strr = find_player(str);

    env = environment(strr);
    if(env->query_property("no scry") || env->query_property("no teleport"))
        return notify_fail("The glass stays cloudy.\n");
    if(wizardp(strr)) { notify_fail("The stays cloudy.\n");
        return 0;
    }
    write(env->query_short()+"\n");
    return 1;
}



