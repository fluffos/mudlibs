#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
     set_name("Viewing Room");
     set_short("Viewing Room");
     set_long("The Pool.\n"
"Hidden deep within the Hall lies a room with mystical "
"properities that have been pried from the minds of tortured "
"demons. Blood trickles down the walls and from the ceiling to "
"gather in a pool carved into the ground. ");
     set_properties(([
        "light"       : 2,
        "no bump"     : 1,
        "town"        : 1,
        "no steal"    : 1,
        "no scry"     : 1,
        "no gate"     : 1,
]));
 set_exits( (["up" : ROOMS"darksoul/hall"]) );
    set_items( ([
        "wall"  : "Empty eyed skulls streaked with blood stare back at you and fleshless hands wave to you from their places in the walls.",
        "ceiling" : "Streaked with blood the bones of the dead seem to cave inward twards you.",
        "blood" : "Running rivers of blood flow from the walls and ceiling to form a huge pool in the middle of the room."
      ]) );
}
void reset() {
 ::reset();
  if (!present("pool", this_object()))
    new(ROOMS"darksoul/obj/pool")->move(this_object());
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
    write(env->query_long()+"\n");
    return 1;
}
