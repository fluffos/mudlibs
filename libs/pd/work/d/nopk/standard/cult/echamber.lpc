#include <std.h>
#include <sindarii.h>
inherit VAULT;

void look_door();

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Eastern chamber in the cave");
    set("long",
	"This is the eastern chamber in the part of the cave just below the "
	"ground level. A thick steel door has been set up in the doorway west, "
	"giving this room some degree of privacy from the rest of the cave."
    );
    set_items(([
        "door 1" : (: look_door() :),
	"chamber" : "It has been carved into the depths of the cave.",
	"privacy" : "Just a little.."
    ]));
    set_exits(([
        "west" : ROOMS"cult/cave3",
    ]));
   set_door("door", ROOMS"cult/wchamber", "west", "key ring");
}       
      
void look_door() {
  if(query_open("door 2")) message("my_action", "It is open.", this_player());
    else message("my_action", "It has been closed.", this_player());
}   

void reset() {
 ::reset();
   if (!present("anarchin")) {
     new(ROOMS "cult/mob/anarchin")->move(this_object());
   }
}
