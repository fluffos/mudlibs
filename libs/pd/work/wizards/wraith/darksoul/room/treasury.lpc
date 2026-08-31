#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Dark Soul Treasury");
     set_short("Dark Soul Treasury");
     set_long("%^BOLD%^%^WHITE%^The Treasury of the Dark Souls.\n"
"%^BOLD%^%^BLACK%^It looks as if a %^BOLD%^%^RED%^ma%^RESET%^%^RED%^s%^BOLD%^%^RED%^s%^RESET%^%^RED%^ac%^BOLD%^%^RED%^re%^BOLD%^%^BLACK%^ has gone on in this room. Severed "
"%^BOLD%^%^BLACK%^heads and limbs lie scattered, stiff with rigormortis. The "
"%^BOLD%^%^BLACK%^stench of death and decay blankets the area causing large "
"%^BOLD%^%^BLACK%^%^WHITE%^hordes of flies %^BLACK%^to swarm upon the pools of sticky %^BOLD%^%^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ and "
"%^BOLD%^%^BLACK%^rotting flesh. ");
     set_night_long("description");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"filename"]) );


    set_items( ([
        "blood"  : "%^BOLD%^%^BLACK%^This blood was spilt by the members who caught theives trying to steal from them.",
        "flesh" : "%^BOLD%^%^BLACK%^The torn and ripped peices of would be theives litter the ground around you."
      ]) );

}

