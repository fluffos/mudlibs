#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sword", "enchanted sword", "blade"}));
set_name("sword");
set_short("%^BOLD%^GREEN%^enchanted sword%^RESET%^");
set_long("This is a plain sword made of steel that has been enchanted using some minor magicks.  They are cheap yet powerful and are widely used among blood warrior commanders.");
set_weight(16);
set_value(250);
set_wc(15);
set_ac(1);
set("skill level", 100);
set_type("blade");
set_hands(1);
}

int query_auto_load() {
if(this_player()->query_level() < 20) return 0;
return 1;
}
