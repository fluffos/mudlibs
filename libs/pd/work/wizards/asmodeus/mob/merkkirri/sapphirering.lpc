#include <std.h>
inherit ARMOUR;

int uses;

void create() {
    ::create();
set_name("ring");
set_short("a %^BLUE%^sapphire%^BOLD%^YELLOW%^ ring%^RESET%^");
set_long("A beautiful ring with a %^BLUE%^sapphire%^RESET%^ setting.");
set_id(({"ring", "sapphire ring"}));
set_ac(1);
set_weight(1);
set_value(500);
set_type("ring");
set_limbs(({"left hand", "right hand"}));
// set_property("magic item", ({ "illuminate" }));
 uses=0;
}

int query_auto_load() {return 1; }

void init()
{
 ::init();
 add_action("my_use", "use");
}
int my_use(string str)
{
 if (str!="ring")
   {
    notify_fail("Use what?");
    return 0;
   }
 if (uses >= 15)
   {
    write("The ring is out of uses.");
    return 1;
   }
 uses++;
 write("You feel your blood being purified.");
this_player()->add_poisoning(-75);
 return 1;
}
 
