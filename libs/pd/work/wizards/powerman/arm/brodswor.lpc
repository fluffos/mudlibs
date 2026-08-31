#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sword", "blade", "broadsword"}));
set_name("%^RED%^blood %^BOLD%^bathed %^RESET%^blade");
set_short("a %^RED%^blood-%^BOLD%^stained%^RESET%^ broadsword");
set_long("A steel broadsword bathed in the blood of its victims, made to be so
wide as to help defend against enemies. It is quite heavy to hold in one hand
but if the soldiers can do it, so can you.");
set_curr_value("electrum",200);
set_weight(60);
set_wc(10);
set_ac(1);
set_type("blade");
set_hands(1);
set_wield("You strain but eventually wield the sword on one arm.               
You feel an urge to kill, maim, and slaughter.");
set_unwield("Your senses return as you let go of the sword.");
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
