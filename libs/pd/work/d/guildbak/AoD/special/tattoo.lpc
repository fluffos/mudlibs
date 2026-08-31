#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
    set_name("%^BOLD%^%^BLACK%^A%^WHITE%^o%^BLACK%^D %^WHITE%^T%^BLACK%^at%^WHITE%^t%^BLACK%^o%^WHITE%^o%^RESET%^");
    set("id", ({"tat", "tattoo", "AoD", "necklace"}) );
    set("short","%^BOLD%^%^BLACK%^A%^WHITE%^o%^BLACK%^D %^WHITE%^T%^BLACK%^at%^WHITE%^t%^BLACK%^o%^WHITE%^o%^RESET%^"); 
    set("long", "%^BOLD%^%^BLACK%^A tattoo given to all new members of the %^WHITE%^A%^BLACK%^rmy %^WHITE%^O%^BLACK%^f %^WHITE%^D%^BLACK%^arkness. It
is simple and to the point, 3 letters %^RED%^-%^BLACK%^A%^WHITE%^o%^BLACK%^D%^RED%^- %^BLACK%^scrawled onto the wearers neck.%^RESET%^");
    set_weight(15);
    set_type("necklace");
    set_limbs(({"torso"}));
   set_ac(1);
    set_curr_value("gold",300);
    set("dragon wear", 1);
    set_wear("%^BOLD%^%^CYAN%^Ouch! %^BLACK%^Those tattoo needles hurt but now you're AoD for life!");
    set_remove("Your tattoo fades away!");

}
int query_auto_load() {
    if (this_player()->query_guild()=="AoD") return 1;

}
