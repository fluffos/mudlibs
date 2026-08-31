#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The Brigand's Pub");
    set("long",
        "You are in the Brigand's Pub.\n"
        "The pub can get a bit rowdy at times, but you can still manage "
        "to sit down and have a drink, and maybe even grab some grub.");
    set_items(
        ([
	  "bar" : "The Brigand's Pub.",
    ]) );
set_exits( (["out" : ROOMS"wdovin3",
"east"  : ROOMS"fighter/berserker/berserker_join"]) );
    
}

void reset() {
  ::reset();
  if(!present("rocko")) 
    new(MOB"rocko")->move(this_object());
}

