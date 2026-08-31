#include <std.h>
#include <roston.h>
inherit WEAPON;


create() {
::create();
    set_id(({"knife","dark souls knife","darksouls knife"}));
    set_name("dark souls knife");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
              "%^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s "
               "%^WHITE%^K%^BLACK%^n%^WHITE%^i%^BLACK%^f%^WHITE%^e"
                "%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This Knife was formed from the "
              "Soul of a %^BLACK%^Ancient%^WHITE%^ warrior.");
    set_mass(7);
    set_curr_value("copper", 88);
    set_wc(5);

    set_type("knife");
    set_wield("%^BOLD%^%^BLACK%^The Power of past souls fills you.");
    set_unwield("%^BOLD%^%^WHITE%^You feel the power of the souls leave "
                "you.");
    set_hands(1);    
}

/*
int weapon_hit(object ob)
{
 if ( ob->query_guild() != "darksoul" )
   {
    message("info",
      "%^BOLD%^%^BLACK%^Dark Souls Knife glows and a deep black mist begins to fill the room, as souls devour everything.\n", environment(ob));
    return 10000;
   }
 return 1;
}
*/


