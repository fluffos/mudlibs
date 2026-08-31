// - syphon -

#include <kabaal.h>
#include <std.h>
inherit OBJECT;

void create() {
 ::create();
set_id(({"fountain", "stone fountain"}));
set_name("fountain");
set_short("a stone fountain");
set_long("A fountain carved of stone. It's in the shape of an enormous beast, "
         "half eagle, half lion. It stands prominently as if looking over the "
         "area. A plaque is embedded on the base of the fountain.");  
}

int get() { return 0; }

int init()
{
 ::init();
   add_action("goDrink", "drink");
}

int goDrink(string str)
{
if (str!="fountain") return 0;
 if (this_player()->query_disable())
   {
    write("You cannot drink that fast.");
    return 1;
   }
 this_player()->set_disable();
this_player()->add_mp(random(10));
this_player()->add_sp(random(10));
this_player()->add_hp(random(10));
write("The water from the stone fountain refreshes you.");
 return 1;
}
