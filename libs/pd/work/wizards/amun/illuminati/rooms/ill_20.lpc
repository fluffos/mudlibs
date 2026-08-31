#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack" : 1, "no magic" : 1, "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1, "no steal" : 1 ]));
    set("short", "ILLUMINATI");
    set("long","");
    set_exits( ([ "southeast" : ILLROOM "ill_board", "northeast" : ILLROOM "ill_21", "northwest" : ILLROOM "ill_22","southwest" : ILLROOM "ill_23", "up" : ILLROOM "ill_24", "down" : ILLROOM "ill_13" ]) );
}
