#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On a black sand beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "Steam and heat rise upwards from the burning black sand on the beach. "
     "The beach ends at this point, where a darkened marsh begins. Black sand "
     "leads south, towards the ocean. A small hill signals the begining of the "
     "marsh.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The air is humid and hot as a result of the burning black sand meeting "
     "the cool waters of the marsh to the north. Ocean waves can be heard "
     "crashing onto the beach from the south.");
   set_items(([
     "marsh" : "The dark marsh begins here.",
     "sand"  : "The sand begins to become a thinner mix, then disperses all "
               "together at the begining of the marsh.",
     "hill"  : "There is a hill right between the marsh and beach.",
     "waves" : "They crash onto the beach to the south."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "south" : ROOMS"beach3",
      "north" : ROOMS"marsh1",
   ]));
}

string *query_tracks() { return ({ }); }
