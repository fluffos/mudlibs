//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>
#include <money.h>
#include <treasury.h>

inherit TREASURY;

void create() {
    ::create();
    set_guild("darksoul");
    set_name("Dark Soul Treasury");
    set_short("Dark Soul Treasury");
    set_long("%^BOLD%^%^WHITE%^The Treasury of the Dark Souls.%^RESET%^\n"
"%^BOLD%^%^BLACK%^It looks as if a %^RED%^ma%^RESET%^%^RED%^s%^BOLD%^%^RED%^sac%^BOLD%^%^RED%^re%^BLACK%^ has gone on in this room. Severed "
"%^BOLD%^%^BLACK%^heads and limbs lie scattered, stiff with rigor mortis. The "
"%^BOLD%^%^BLACK%^stench of death and decay blankets the area causing large "
"%^BOLD%^%^WHITE%^hordes of flies%^BLACK%^ to swarm upon the pools of sticky %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BLACK%^ and "
"%^BOLD%^%^BLACK%^rotting flesh.");
   set_properties(([
     "light":2, "night light":2, "no attack":1, "no magic":1, 
     "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));

    set_exits( (["north" : DARKSOUL"hall"]) );


    set_items( ([
        "blood"  : "%^BOLD%^%^BLACK%^This %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d %^BLACK%^was spilt by the members who "
        "caught theives trying to steal from them.",
        "flesh" : "%^BOLD%^%^BLACK%^The torn and ripped peices of would be "
        "theives litter the ground around you."
      ]) );

}
