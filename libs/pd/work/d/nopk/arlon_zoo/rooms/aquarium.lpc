#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The Aquarium");
    set("long",	"You've entered a building housing a huge aquarium.  "+
      "Various aquatic creatures are swimming behind the transparant wall."+
      "  To one side you see a couple of divers donning suits and diving"+
      " into the tank.");
    set_exits( ([ "south" : ROOMS"zoopath2" ,
	"dive" : ROOMS"tank20" , ]) );
    set_items( ([ "building": "Its a huge shell made of what appears to be tinted "+
	"glass.  Light seems to emminate from it.",
	"aquarium":"It's a giant see-through tank, filled with all sorts of creatures.", 
	"wall":"You can see lots of creatures swimming on the other side.",
	"diver": "She is instructing a visitor on the responsibilities of diving into the tank."]) );
    set_listen("default", "You hear people talking about the sealife on display.");
}
