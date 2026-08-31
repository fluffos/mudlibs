#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 0);
   set_short("Below Melissa Praxis' coffin");
   set_long("The warm and sticky air presses against your skin. "
            "The walls about you are made of a thick soil, so thick "
            "in fact that it would muffle any scream. Shadows dance "
            "about you, taunting and jeering at you. The soft ground "
            "is warm and dull. The grave's stench is almost overpowering "
            "here. Messengers of evil can chant here.");
   set_smell("default", "The smell of death and decay fills the air. ");
   set_smell("grave", "Almost enough to knock you out!");
   set_items(([
          "ground" : "It is unstable and soft.",
	  "soil" : "The cold, black soil is so thick, it could muffle "
                   "any scream.",
          "air" : "Warm and sticky, it adds an eerie feel to the area.",
          "dirt" : "A horrible fealing comes over you.",
          "under" : "You are six feet under.",
          "secret" : "Which way will you go?",
	  "grave" : "The grave is horribly empty and sad."]));
    set_listen("default", "Faint whispers fill the air");
    set_listen("whispers", "The secret is near.. The secret is here..");
    set_exits(([
                "east" : ROOMS"cemetary/coffin5",
                "south" : ROOMS"cemetary/coffin4",
                "north" : ROOMS"cemetary/coffin8",
                "northwest" : ROOMS"cemetary/coffin3",
                "southwest" : ROOMS"cemetary/coffin2",
                "southeast" : ROOMS"cemetary/coffin9",
                "northeast" : ROOMS"cemetary/coffin7",
                "west" : ROOMS"cemetary/coffin6",
"down" : "/d/nopk/tirun/clergy/kataan/kataan_join" ]));
   set_invis_exits(({ "down" }));
}

int blocked() {
   write("You are far too disoriented to do that.");
   return 1;
}

int muffle() {
   write("Your screams are muffled by the thick soil!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
      "'s screams are muffled by the thick soil!", ({ this_player() }));
   return 1;
}

int chant(string str) {
   if (this_player()->query_class() != "kataan") return 0;
   if (!str) {
      write("Chant what?");
      return 1;
   }
   message("info", "%^ORANGE%^"+this_player()->query_cap_name()+" chants:%^RESET%^ "+str, users());
   return 1;
}

void init() {
 ::init();
   add_action("blocked", "peer");
   add_action("blocked", "survey");
   add_action("muffle", "shout");
   add_action("muffle", "scream");
   add_action("chant", "chant");
}
