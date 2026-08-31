#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("ring of the damned");
    set("id", ({"ring"}) );
    set("short","%^FLASH%^%^RED%^R%^BOLD%^i%^BLACK%^n%^RESET%^%^FLASH%^g %^RED%^o%^BOLD%^f %^BLACK%^t%^RESET%^%^FLASH%^h%^RED%^e %^BOLD%^D%^BLACK%^a%^RESET%^%^FLASH%^m%^RED%^n%^BOLD%^e%^BLACK%^d%^RESET%^"); 
    set("long", "%^BLUE%^This ring was given to Agent by his father the day before he left to aid his clan in a great battle with the Dwarves of Roston.");
    set_weight(1);
    set_type("ring");
    set_limbs(({"finger"}));
    set_ac(0);
    set_curr_value("gold",300);
    set_wear("%^CYAN%^You wear your fathers gift to you and feel as if he is by your side.%^RESET%^");
    set_remove("%^BLACK%^%^BOLD%^The happiness fades and sorrow fills your heart.%^RESET%^");

}

int query_auto_load() {
    if(this_player()->query_name() == "agent") return 1;
}
