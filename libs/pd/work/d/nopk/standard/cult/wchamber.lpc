#include <std.h>
#include <sindarii.h>
inherit VAULT;

void look_door();

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Western chamber in the cave");
    set("long",
	"This chamber of the cave is closed off from the rest by a thick steel "
	"door. The walls and ground are the stone of the cave, that have been "
	"chipped and carved away to form this chamber."
    );
    set_items(([
	"door" : (: look_door() :),
	"chamber" : "A small chamber in the cave."
    ]));
    set_exits(([
	"east" : ROOMS"cult/cave3"
    ]));
   set_door("door", ROOMS"cult/wchamber", "east", "key ring");
}

void look_door() {
  if(query_open("door 1")) message("my_action", "It is open.", this_player());
    else message("my_action", "It has been closed.", this_player());
}

void reset() {
 ::reset();
   if (!present("craz")) {
     new(ROOMS "cult/mob/craz")->move(this_object());
   }
}
