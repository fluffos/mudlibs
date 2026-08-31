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
   set_long("%^BOLD%^%^WHITE%^The Purgatory General Store.\n"
"%^BOLD%^%^BLACK%^Welcome to the General Store, the walls are lined with swords "
"%^BOLD%^%^BLACK%^and other weapons of mass destruction. The glass counter at "
"%^BOLD%^%^BLACK%^the back of the store houses some of the more deadlier items. "
"%^BOLD%^%^BLACK%^Yvehc the shopkeeper sits in the back waiting for more "
"%^BOLD%^%^BLACK%^vic...ummm customers to walk through his doors.");
   set_smell("default", "The smell of iron and weapon oil wafts in the air.");
   set_listen("default", "The sound of breathing comes from all around.");
   set_exits(([
       "north" : ROOMS"purgatory4",
   ]));

   set_items((["counter"   : "A small glass case that runs the width of the shop.",
               "walls"  : "Weapons and other items have been pegged to the walls of the shop."]));



}
void reset() {
   ::reset();
   if(!present("shopkeeper"))
   new(MOBS"shopkeeper")->move(this_object());
}
