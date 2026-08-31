#include <std.h>
inherit WEAPON;

create() {
::create();
set_id(({"knife", "bone knife"}));
set_name("knife");
set_short("%^BOLD%^%^WHITE%^B%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n"
     "%^RESET%^%^ORANGE%^e %^BOLD%^%^WHITE%^K%^RESET%^%^ORANGE%^n"
     "%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^e%^RESET%^");
set_long("%^BOLD%^%^BLACK%^This knife was made from the tail bone "
         "of the great Fire Dragon.");
set_weight(10);
set_value(60);
set_wc(13);
set_ac(3);
set_type("knife");
set_hands(1);
set_wield("%^BOLD%^%^WHITE%^You feel the power of the knife fill your body.");
set_unwield("%^RED%^You feel the power of the knife leave you.");
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}

