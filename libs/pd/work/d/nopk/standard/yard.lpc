#include <std.h>
#include <sindarii.h>
inherit VAULT;

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set_property("indoors", 1);
    set("short", "An old, boarded up house");
    set("day long",
      "Only a few beams of sunlight enter this old, dark, boarded up house. The "
      "boards over the windows make it hard for any light at all to enter this "
      "room. The ground is dirty and broken glass litters the ground."
    );
    set("night long",
      "Through the boarded up windows, a few pinpoints of light can be seen in "
      "the dark night sky. Because of the heavily boarded windows, only a very "
      "small ammount of star light manages to enter the room."
    );
/*    set_door("manhole", ROOMS"sewer_ent","down",0);
    set_string("manhole","open","You open the manhole cover to the sewers.\n");
    set_open("manhole", 0);
    ROOMS"sewer_ent"->set_open("manhole", 0);*/
    set_exits( 
	      (["west" : ROOMS"sveros2", ]));
//		"down" : ROOMS"sewer_ent"]) );
    set_items(([
    ]));
//	(["alley" : "It looks beautiful here.",
//	  "manhole" : (: this_object(), "look_at_manhole" :) ]) );
}

void reset() {
  ::reset();
    if(!find_living("beggar") || !environment(find_living("beggar")))
	new(MOB"beggar")->move(this_object());
/*    if(query_reset_number() != 1) {
      set_open("manhole", 0);
      ROOMS"sewer_ent"->set_open("manhole", 0);
    }*/
}
/*
void look_at_manhole() {
    if(query_open("manhole"))
	 write("You can see a hole leading down into the sewers by it.");
    else write("It is covering up an entrance into the sewer.");
}

*/
