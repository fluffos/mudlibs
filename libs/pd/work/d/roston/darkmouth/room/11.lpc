#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
::create();
   set_name("The Caverns");
   set_items((["wall"   : "%^BOLD%^%^BLACK%^You wonder why your looking at a wall if your lost"]));
   set_properties((["light":2, "night light":2]));
   set_short("The Caverns");                      
   set_long("%^BOLD%^%^BLACK%^S%^WHITE%^o%^BLACK%^m%^WHITE%^e "
           "%^BLACK%^W%^WHITE%^h%^BLACK%^e%^WHITE%^r%^BLACK%^e "
           "%^WHITE%^I%^BLACK%^n %^WHITE%^T%^BLACK%^h%^WHITE%^e "
"%^BLACK%^C%^WHITE%^a%^BLACK%^v%^WHITE%^e%^BLACK%^r%^WHITE%^n%^BLACK%^s.

The Caverns lead to the: %^BOLD%^BLACK%^north, east, south, west");
set_exits( ([ "north" : DMROOM"11",
              "south" : DMROOM"10",
              "west"  : DMROOM"23",           
              "east" : DMROOM"24"]));

set_invis_exits(({"north","south","west","east"}));


skip_obvious();
}
 void reset() {

     if(!present("dragon"))
       {
       new(DMMOB"sss")->move(this_object());
      new(DMMOB"troll")->move(this_object()); 
      }

}                                                                              

