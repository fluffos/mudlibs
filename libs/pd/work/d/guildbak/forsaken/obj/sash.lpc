#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("forsaken sash");
    set_short("%^BOLD%^%^WHITE%^S%^BOLD%^a%^BLACK%^s%^WHITE%^h %^BLACK%^o%^WHITE%^f F%^BLACK%^or%^WHITE%^s%^BLACK%^a%^WHITE%^ken%^RESET%^");
    set_long("Sewn from the finest silk and imbued with the grandest magick, this "
      "sash is good protection.");
    set_id(({"sash"}));
    set_ac(5);            
    set_mass(5);
    set_curr_value("gold", 500);
    set_type("sash");
    set_limbs(({"torso"}));
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
