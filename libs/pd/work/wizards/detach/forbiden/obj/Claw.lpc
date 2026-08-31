#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"claw", "wolf claw"}));
set_name("Wolf Claw");
set_short("%^%^BOLD%^%^WHITE%^Wo%^RESET%^%^GREEN%^l%^RESET%^f %^BOLD%^%^WHITE%^Cl%^RESET%^%^GREEN%^a%^RESET%^w%^RESET%^");
set_long("%^RESET%^%^GREEN%^This Claw is 8 inches long, it shines with a silver tint.");
set_weight(20);
set_value(70);
set_wc(11);
set_ac(1);
set_type("knife");
set_hands(1);
set_wield("The Beast Rages within you.");
set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 93) {
write("%^BOLD%^%^WHITE%^Your Claw slashes across your opponents face opening a wide cut!");
say(" "+this_player()->query_cap_name()+"'s %^BOLD%^%^WHITE%^Claw slashes his opponents face
spraying blood into "+this_player()->query_cap_name()+"'s face!"); 
result=(random(30))+((this_player()->query_level()/2));
atk->set_paralyzed(random(3));
return result;
}

return 0;
}

int query_auto_load() {
  if(this_player()->query_level() > 35) return 1;
  return 0;
}
