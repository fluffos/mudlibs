#include <std.h>
#include <purgatory.h>
inherit ROOM;
void create() {
   ::create();
   set_name("Purgatory Shop");

   set_properties((["light"         :2, 
                    "night light"   :3, 
                    "no teleport"   :1,
                    "no magic"      :1,
                    "no attack"     :1,]));
   set_short("Purgatory Shop");
   set_long("%^BOLD%^%^WHITE%^The Purgatory Tavern.\n"
"%^BOLD%^%^BLACK%^Welcome to The Tavern, the walls are lined bottles, "
"%^BOLD%^%^BLACK%^dishes, and other serving utensils. The glass bar at "
"%^BOLD%^%^BLACK%^the back of the room is thick and sturdy. "
"%^BOLD%^%^BLACK%^Vlandross the barkeep sits in the back waiting for more "
"%^BOLD%^%^BLACK%^vic...ummm customers to walk through his doors.");
   set_smell("default", "The smell of food and drink wafts in the air.");
   set_listen("default", "The sound dishes clanking comes from the back room.");
   set_exits(([
       "south" : ROOMS"purgatory4",
   ]));

   set_items((["bar"   : "A large glass counter that runs the width of the room.",
               "walls"  : "Shelves have been pegged to the walls of the tavern."]));



}
void reset() {
   ::reset();
   if(!present("barkeep"))
   new(MOBS"barkeep")->move(this_object());
}
