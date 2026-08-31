// - syphon -

#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
 ::create();
set_id(({"fountain", "overgrown fountain"}));
set_name("fountain");
set_short("an%^BOLD%^%^BLUE%^ overgrown fountain%^RESET%^");
set_long("A fountain carved of stone.  It was once probably beautiful but now the moss and weathering have damaged the stone to such a point you can't even imagine what the sculptor was trying to create.");  
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
this_player()->add_mp(random(30));
this_player()->add_sp(random(20));
this_player()->add_hp(random(20));
write("%^BOLD%^%^BLUE%^You drink from the fountain water.%^RESET%^");
 return 1;
}
