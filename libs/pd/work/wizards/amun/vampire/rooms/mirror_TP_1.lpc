#include <std.h>
#include <vampq.h>
inherit ROOM;
string make_a_long();
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1 ]));
    set("short", "Hall of Mirrors");
    set_long( (: make_a_long :) );
    set_items((["mirrors" : "%^BOLD%^%^WHITE%^Mirrors line the walls making it hard to find the exits.%^RESET%^", "reflection" : "%^BOLD%^%^WHITE%^You look at yourself in the mirror.%^RESET%^" ]));
    set_exits( ([ "east" : VR"mirror_TP_2", "north" : VR"mirror_TP_4" ]) );
    set_invis_exits( ({"north", "east"}) );
    skip_obvious();
}
string make_a_long() {
    return "%^BOLD%^%^BLACK%^The room is full of mirrors. All that can be seen is your reflection, making it hard to move around the area. \n\n\n%^BOLD%^%^WHITE%^The reflection of, "+this_player()->query_cap_name()+" is here.%^RESET%^";
}
