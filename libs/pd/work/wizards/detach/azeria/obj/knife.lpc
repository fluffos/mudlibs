#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"knife", "eradicater","dagger"}));
set_name("Eradicater");
set_short("%^BOLD%^%^BLACK%^Era%^YELLOW%^dic%^BLACK%^ater");
set_long("The blade shines in a deep black, surrouned by a yellow glow. This knife was formed in the depths of hell, it is told it has the power to slay Arch-Angels.");
set("skill level", 75);
set_weight(5);
    set_curr_value("gold",150+random(40));
set_wc(13);
set_ac(2);
set_type("knife");
set_hands(1);
set_wield("%^BOLD%^%^BLACK%^You feel your Demonic power rage.");
set_unwield("%^BOLD%^%^BLACK%^You feel at ease.");



set_hit((: this_object(), "weapon_hit" :));


}
int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100)  > 69) {
write("%^BOLD%^%^BLACK%^Era%^YELLOW%^dic%^BLACK%^ater slices into your opponents neck spraying %^BOLD%^%^RED%^blood%^BLACK%^ all over you!");
say("%^BOLD%^%^BLACK%^ "+this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^Era%^YELLOW%^dic%^BLACK%^ater slices into his opponents neck spraying %^BOLD%^%^RED%^blood%^BLACK%^ all over him. ");
 
result= (random(90)+10);      
this_player()->add_sp(result);
result=(random(80))+((this_player()->query_level()));
;
        return result;
    }
}
int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
