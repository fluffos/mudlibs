#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"hammer", "a flaming hammer","flaming hammer", "ahammer"}));
set_name("hammer");
set_short("%^YELLOW%^A %^RESET%^%^RED%^F%^BOLD%^%^RED%^l%^BOLD%^%^RED%^a"
"%^RESET%^%^RED%^m%^BOLD%^%^RED%^i%^RESET%^%^RED%^n%^BOLD%^%^RED%^g "
"%^RESET%^%^ORANGE%^h%^YELLOW%^a%^RESET%^ORANGE%^m%^YELLOW%^m%^RESET%^%^ORANGE%^e%^YELLOW%^r%^RESET%^");
set_long("%^RED%^This Hammer was formed and giving to the master "
"of the flames, the one that caries this hammer is one bad mofo.");
set_weight(30);
set_value(0);
set_wc(13);
set_ac(1);
set_type("blunt");
set_hands(1);
set_wield("%^BOLD%^%^RED%^Your hear voices say: He's the one they call 'the one bad mofo'.");
set_unwield("%^RED%^The voices grummble and stop.");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 75) {
write("%^BOLD%^%^RED%^The Flames on the hammer rage and engulf its foe!");
say("%^BOLD%^%^RED%^The Flames on the hammer seem rage and engulf its foe!");
result=(random(25))+((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }

