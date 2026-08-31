#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("saddle");
    set_short("%^ORANGE%^Dragon Saddle%^RESET%^");
    set_long("%^ORANGE%^This saddle is unusually large. It has a hole in the front of it, made to settle around a crest spike. It looks comfortably padded, and cushioned for the satisfaction of dragon and rider alike. %^BOLD%^%^WHITE%^P%^BLACK%^a%^RESET%^%^CYAN%^t%^RESET%^%^ORANGE%^t%^RESET%^%^BOLD%^%^WHITE%^e%^BLACK%^r%^RESET%^%^CYAN%^n%^RESET%^%^ORANGE%^s of many kinds adorn the sides and stirrups.
");
    set_id( ({"saddle"}) );
    set_type("belt");
    set_ac(1);
    set_weight(20);
    set_curr_value("gold",100+random(50));
    set_limbs(({ "torso" }));
    set("dragon wear", 1);
}

int query_auto_load()
{
 if (this_player()->query_level() < 20) return 0;
 if (this_player()->query_race() == "dragon") return 1;
 return 0;
}
