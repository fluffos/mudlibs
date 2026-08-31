#include <std.h>
#include <sindarii.h>
inherit VAULT;

void create() {
    ::create();
    set("short", "The Tirun sewers");
    set("long",
      "You are underneath the town of Tirun inside their "
      "small sewer system.  There is a manhole to the surface above "
      "you.");
    set_smell("default", "The sewers stink of humanoid waste.");
    set_door("manhole",ROOMS"yard","up",0);
    set_exits( 
	      (["east" : ROOMS"sewer",
		"up" : ROOMS"yard"]) );
    set_property("light", 0);
    set_property("indoors", 1);
    set_items(
        ([ "manhole" : "It is a hole that leads to the surface."]) );
}

void reset() {
  ::reset();
    if(!present("sword")) 
      new(WEP"sword")->move(this_object());
}

