#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("%^BLACK%^%^BOLD%^A da%^WHITE%^r%^BLACK%^k, hoo%^WHITE%^de%^BLACK%^d cloak%^RESET%^");
    set("id", ({"cloak", "dark", "hooded"}) );
    set("short","%^BLACK%^%^BOLD%^A da%^WHITE%^r%^BLACK%^k, hoo%^WHITE%^de%^BLACK%^d cloak%^RESET%^"); 
    set("long", "%^BLACK%^%^BOLD%^This cloak seems to be the deepest, darkest black you have ever
seen. It is very light weight and doesnt seem to move at all in the wind.%^RESET%^");
set_weight(20);
set_type("cloak");
set_limbs(({"torso","right arm", "left arm"}));
set_ac(2);
set_curr_value("gold",300);
set_wear("%^BLACK%^%^BOLD%^As you wear the cloak you feel much stealthier than before%^RESET%^.");
set_remove("%^BLACK%^%^BOLD%^You step out of the shadows and remove your cloak%^RESET%^");

}
int query_auto_load() {
        if (this_player()->query_guild()=="AoD") return 1;

}

