#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"sword", "blade"}));
set_name("blade");
set_short("%^BLUE%^Diam%^CYAN%^ond Blad%^CYAN%^ed Long%^BLUE%^sword%^RESET%^");
set_long("A Sword used by the commanders of the armies. This sword's blade is
made of diamond dust. Light and deadly, the blade seems to be able to slice
through bodies like a hot knife through butter.");
set_curr_value("electrum",100);
set_weight(40);
set_wc(10);
set_ac(1);
set_type("blade");
set_hit( (: weapon_hit :) );
set_hands(1);
set_wield("You swing your sword around to get accustomed to its light
weight.");
set_unwield("You sheath the sword and unwield it.");
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("You break through your enemy's defenses and deal a brutal blow!");
say((string)this_player()->query_cap_name()+" %^RED%^SLAMS%^RESET%^ his blade right into the enemy's weak spot!");
result=(random(20))+((this_player()->query_level()/2));
return result;
}
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
