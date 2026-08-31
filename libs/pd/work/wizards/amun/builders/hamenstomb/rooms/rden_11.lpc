#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^ORANGE%^This room is different than the others, it has wood flooring under the light cover of sand. The wood is loose and looks to be glowing with %^BOLD%^%^BLACK%^black light%^RESET%^%^ORANGE%^. In the corner of the room small, insects can be found making their way through the floor boards. This place gives off an eerie feeling. \n");
    set_items( ([ "shadows": "%^BOLD%^%^BLACK%^You can see bright yellow eyes glaring at you watching you from the shadows.%^RESET%^" ]) ); 
    set_exits( ([ "north" : ROOMS+"rden_10" ]) );
}
void reset() {
    ::reset();
    if (!present("sphinx", this_object()))
	new(MON+"criosphinx")->move(this_object());
}
