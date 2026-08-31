#include <mjungle.h>
#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"claw", "insidious claw"}));
set_name("claw");
set_short("an insidious claw");
set_long("The claw is actually two small blades approximately half a meter in length each, attached to a steel gauntlet.  Each blade is serrated and surely causes dreadful wounds.  Due to the design of the claw, a user well trained in bare-handed combat would have more success than someone trained in the use of blades or knives.");
set_weight(10);
set_curr_value("gold",54);
set_wc(8);
set_ac(1);
set_type("melee");
set_hands(1);
set_wield("%^BOLD%^RED%^You slide the gauntlet onto your hand and strap it securely into place.%^RESET%^");
set_unwield("%^BOLD%^RED%^You unstrap the gauntlet and remove your claw.%^RESET%^");
set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("%^BOLD%^RED%^The claw %^BOLD%^BLACK%^slashes%^BOLD%^RED%^ your foe deeply!%^RESET%^");
say((string)"%^BOLD%^RED%^"+this_player()->query_cap_name()+"'s claw %^BOLD%^BLACK%^slashes%^BOLD%^RED%^ deeply as it strikes!%^RESET%^");
result=(random(15))+((this_player()->query_level()/2));
return result;
}
}

int CheckArmour (string str) {
     object ob;
     if (!str) return 0;
     ob = present(str, this_player());
     if (!ob || ob != this_object()) return 0;
     if (this_player()->query_armour("right hand") != ({ })) {
     write("You cannot wear the claw with any other glove.");
     return 1;
}
return 0;
}

void init() {
 ::init();
   add_action("CheckArmour", "wear");
}

int query_auto_load() {return 1; }
