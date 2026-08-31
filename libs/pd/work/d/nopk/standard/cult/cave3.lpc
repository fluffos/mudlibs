#include <std.h>
#include <sindarii.h>
inherit VAULT;

void look_door();
void look_doort();

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "A three-way fork in the road");
    set("long",
	"The cave slopes downwards a bit here. There is a slight passage leading "
	"back up onto the ground level in the ceiling. The cave comes to a three-"
	"way fork in the road right here. There are two steel doors, one west, "
	"and the other east. A passage goes south deeper into the cave."
    );
    set_items(([
	"doors"  : "Two thick doors",
	"door 1" : (: look_door() :),
	"door 2" : (: look_doort() :),
    ]));
    set_exits(([
	"up"    : ROOMS"cult/cave2",
        "west"  : ROOMS"cult/wchamber",
	"east"  : ROOMS"cult/echamber",
	"south" : ROOMS"cult/cave4",
    ]));
   set_door("door", ROOMS"cult/wchamber", "west", "key ring");
   set_door("door", ROOMS"cult/echamber", "east", "key ring");
}

void look_door() {
  if(query_open("door 1")) message("my_action", "It is open.", this_player());
    else message("my_action", "It has been closed.", this_player());
}

void look_doort() {
  if(query_open("door 2")) message("my_action", "It is open.", this_player());
    else message("my_action", "It has been closed.", this_player());
}

void reset() {
 ::reset();
   if (!present("punk")) {
     new(ROOMS "cult/mob/punk")->move(this_object());
     new(ROOMS "cult/mob/punk")->move(this_object());
   }
}
