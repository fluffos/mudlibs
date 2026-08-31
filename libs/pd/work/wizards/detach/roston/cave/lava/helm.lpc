#include <std.h>
#include <roston.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("lava helm");
 
 

set_short("%^BOLD%^RED%^L%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^v"
          "%^RESET%^%^ORANGE%^a "
    "%^BOLD%^%^RED%^H%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^l%^RESET%^%^ORANGE%^m%^RESET%^");
    set_long("This is a one of a kind helmet, its made from "
             "%^BOLD%^%^RED%^lava%^RESET%^rock.");
    set_id( ({ "helm" , "lava helm" }) );
    set_ac(1);
    set_mass(30);
    set_value(2);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 0;
}

