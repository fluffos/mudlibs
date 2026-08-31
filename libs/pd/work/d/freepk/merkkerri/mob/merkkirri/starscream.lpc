#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
create() {
::create();
set_id(({"Starscream", "starscream", "sword", "blade", "claymore"}));
set_name("sword, Starscream");
set_short("%^RESET%^%^ORANGE%^Star%^BOLD%^%^RED%^sc%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^eam%^RESET%^");
set_long("Forged by a forgotten smith of ages past and sent from the heavens along the tail of a shooting star, %^ORANGE%^Star%^BOLD%^%^RED%^sc%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^eam%^RESET%^ still carries a reputation as one of the finest swords ever crafted.");
set_weight(18);
set_curr_value("gold",225);
set("skill level", 150);
set_wc(12);
set_ac(2);
set_type("blade");
set_wield("%^ORANGE%^Star%^BOLD%^%^RED%^sc%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^eam%^RESET%^'s blade begins to %^BOLD%^%^BLACK%^smoke%^RESET%^.");
set_unwield("The %^BOLD%^%^BLACK%^smoke%^RESET%^ stops flowing upon %^ORANGE%^Star%^BOLD%^%^RED%^sc%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^eam%^RESET%^'s blade.");
set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("%^ORANGE%^You %^BOLD%^%^RED%^SLIT%^RESET%^%^ORANGE%^ your foe deeply opening up a large wound!");
say((string)"%^ORANGE%^"+this_player()->query_cap_name()+"'s sword %^ORANGE%^Star%^BOLD%^%^RED%^sc%^RESET%^%^ORANGE%^%^r%^BOLD%^%^RED%^eam%^RESET%^ %^BOLD%^%^RED%^SLITS%^RESET%^ORANGE%^ deeply opening a large wound!%^RESET%^");
result=(random(20))+((this_player()->query_level()/2));
if(random(100) > 90) {
write("%^BOLD%^%^RED%^The numbing pain of the wound disables your attacker!%^RESET%^%^ORANGE%^");
say("%^BOLD%^%^RED%^The terrible pain causes a disabling blow!");
atk->set_paralyzed(random(2));
return result;
}
}
}
int query_auto_load() {
if(this_player()->query_class() != "fighter") return 0;
if(this_player()->query_level() < 30) return 0;
 return 1; 
}
