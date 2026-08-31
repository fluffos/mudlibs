#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"sword", "sword of the unholy", "unholy sword", "blade"}));
set_name("sword");
set_short("%^MAGENTA%^Sw%^GREEN%^%^BOLD%^BLACK%^o%^RESET%^GREEN%^rd %^BOLD%^BLACK%^o%^RESET%^GREEN%^f %^MAGENTA%^th%^GREEN%^e %^MAGENTA%^Un%^GREEN%^h%^BOLD%^BLACK%^o%^RESET%^GREEN%^ly%^RESET%^");
set_long("The %^MAGENTA%^Sw%^GREEN%^%^BOLD%^BLACK%^o%^RESET%^GREEN%^rd %^BOLD%^BLACK%^o%^RESET%^GREEN%^f %^MAGENTA%^th%^GREEN%^e %^MAGENTA%^Un%^GREEN%^h%^BOLD%^BLACK%^o%^RESET%^GREEN%^ly%^RESET%^MAGENTA%^ is a gift from Asmodeus.%^RESET%^  "
"%^MAGENTA%^However his gifts often come with a price...  It is short for a sword but has a wide blade similar to a claymore.  Several runes are etched into the dark metal and %^ORANGE%^glow%^MAGENTA%^ softly.  The hilt is made of a hardened bone wrapped scantily with leather straps.%^RESET%^");
set_weight(17);
set_value(0);
set_wc(11);
set_ac(2);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^GREEN%^Asmodeus speaks to you: %^BOLD%^BLACK%^Serve me well in life or you shall serve me in Hell.%^RESET%^");
set_unwield("%^BOLD%^GREEN%^The %^BLACK%^darkness%^GREEN%^ fades away.%^RESET%^");
set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 75) {
write("%^MAGENTA%^The runes on the sword %^ORANGE%^flare%^MAGENTA%^ and the sword burns as it cuts!%^RESET%^");
say("%^RESET%^%^MAGENTA%^The runes of unholy sword %^ORANGE%^flare%^RESET%^MAGENTA%^ causing it to burn as it cuts!%^RESET%^");
result=(random(25))+((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }
