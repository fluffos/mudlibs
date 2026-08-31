#include <std.h>
inherit ARMOUR;

int rubs;

void create() {
    ::create();
set_name("ring");
set_short("%^RESET%^ORANGE%^a %^ORANGE%^s%^BOLD%^BLACK%^n%^RESET%^ORANGE%^a%^%^BOLD%^RED%^k%^RESET%^WHITE%^e%^ORANGE%^b%^BOLD%^BLACK%^a%^RESET%^RED%^BOLD%^n%^RESET%^ORANGE%^d ring%^RESET%^");
set_long("BOLD%^WHITE%^A platinum ring with a band shaped in the form of a coiled snake.  There is a %^RESET%^RED%^ruby%^BOLD%^WHITE%^ set in the snakes eye.");
set_id(({"ring", "snakeband ring"}));
set_ac(1);
set_weight(1);
set_value(500);
set_type("ring");
set_limbs(({"left hand", "right hand"}));
rubs=0;
}

int query_auto_load() {
if(this_player()->query_class() != "fighter") return 0;
return 1; }

void init()
{
 ::init();
 add_action("my_rub", "rub");
}
int my_rub(string str)
{
 if (str!="ring")
   {
    notify_fail("Rub what?");
    return 0;
   }
 if (rubs >= 10)
   {
   write("The ring seems to be out of magic.");
    return 1;
   }
 rubs++;
 write("You feel a rush of energy flow through you.");
this_player()->add_sp(random(100));
 return 1;
}
 
