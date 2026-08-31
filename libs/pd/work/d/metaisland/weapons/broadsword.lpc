#include <std.h>
#include <metallicana.h>
inherit WEAPON;

void create() {
    ::create();
    set_name("BroadSword");
    set_short("%^BOLD%^%^WHITE%^Br%^RESET%^%^RED%^oadSw%^BOLD%^%^WHITE%^ord%^RESET%^");
    set_long("A sturdy sword, although the edges are blunt and cant cut through much.");
    set_id(({"sword", "broadsword"}));
    set_mass(64);
    set_curr_value("gold", 101);
    set_type("blade");
    set_wc(9);
    set_ac(0);
}
int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
