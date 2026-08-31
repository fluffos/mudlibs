#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"stick", "branch"}));
set_name("%^GREEN%^%^BOLD%^branch%^RESET%^");
set_short("%^GREEN%^A Branch%^RESET%^");
set_long("A Branch. Try to hide yourself within Burham Woods with this.");
set_curr_value("electrum",20);
set_weight(10);
set_wc(5);
set_type("blunt");
set_hit( (: weapon_hit :) );
set_hands(1);
set_wield("You hold this branch and feel more camouflaged.");
set_unwield("You feel less stupid and more exposed.");
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("You push the %^GREEN%^branch%^RESET%^ into your enemy's face!");
say((string)this_player()->query_cap_name()+"'s %^GREEN%^branch%^RESET%^ catches the enemy in the face.");
result=(random(20))+((this_player()->query_level()/2));
return result;
}
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
