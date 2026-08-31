#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
create() {
::create();
set_id(({"slayer", "dragon slayer","sword"}));
set_name("Dragon Slayer");
set_short("%^BOLD%^%^BLACK%^Dragon %^WHITE%^Slayer%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This sword has been passed down from "
"drow to drow for ages, on the handle is the name of the person "
"that holds this sword in the chain at the moment, it reads "
"Meroini, General of the Drow Army.");
set("skill level", 200);
set_weight(25);
set_curr_value("gold", 200);
set_wc(13);
set_ac(2);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^%^BLACK%^You feel Ancient Powers rush into your body.");
set_unwield("%^BOLD%^%^BLACK%^The powers seem to vanish.");



set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(300) < 1 && !this_player()->is_player()) {
   write("Your sword breaks from the force of the blow!!!");
   this_object()->remove();
}
if(random(100) > 93) {
write("%^BOLD%^%^BLUE%^Your Blade slices through your foe with ease!");
say("%^BOLD%^%^BLACK%^Dragon %^WHITE%^Slayer %^RESET%^%^ORANGE%^slices through its foe with ease!");
result=(random(30))+((this_player()->query_level()/2));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 if(this_player()->query_level() < 25) return 0;
 return 1;
}

