#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
   ::create();
   set_name("Dark Souls selling");
   set_items((["corpses"   : "%^RESET%^%^ORANGE%^A pile of roting corpses%^RESET%^",
               "blood"  : "%^RESET%^%^RED%^Pools of blood all over%^RESET%^"]));
   set_properties(([
     "light":2, "night light":2, "no attack":1, "no magic":1, 
     "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));

   set_short("Dark Souls Shop");
   set_long("%^BOLD%^%^BLACK%^Swords, daggers, and other weapons of mass destruction hang "
"%^BOLD%^%^BLACK%^from the walls alongside the skulls of slain enemies. A "
"%^BOLD%^%^BLACK%^shapely leg can be seen through the screen in the back as the "
"%^BOLD%^%^BLACK%^storekeeper comes up to the counter with a curse at the "
"%^BOLD%^%^BLACK%^interruption. Anubis fidgets behind the counter waiting to "
"%^BOLD%^%^BLACK%^buy or sell you anything you need...but make your exchange quick. /n"
"%^BOLD%^%^WHITE%^Death fills the room. ");
   set_smell("default", "The smell of iron and weapon oil wafts in the air.");
   set_listen("default", "Heavy panting can be heard nearby.");
   set_exits(([
       "north" : DARKSOUL"helgrath/hall",
   ]));
}
void reset() {
   ::reset();
   if(!present("anubis"))
   new(DARKSOUL"mon/annubis")->move(this_object());
}
