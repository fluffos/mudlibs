#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"cutlass", "vampric cutlass"}));
set_name("Cutlass");
set_short("%^BOLD%^%^BLACK%^V%^WHITE%^a%^RED%^m%^RESET%^%^RED%^p"
"%^BOLD%^%^RED%^r%^WHITE%^i%^BLACK%^c %^BOLD%^%^BLACK%^C%^WHITE%^u"
"%^RED%^t%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^WHITE%^s%^BLACK%^s%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This Cutlass is made of a element not known "
"to this world. It still has a deep %^RESET%^%^RED%^red%^BOLD%^%^WHITE%^ "
"blood stain on the hilt of this cutlass.");
set_weight(20);
set_value(0);
set_wc(14);
set_ac(1);
set_type("blade");
set_hands(1);
set_unwield("%^BOLD%^%^WHITE%^Your eyes return to normal, you see the world in a light.");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 75) {
write("%^BOLD%^%^RED%^Your %^BLACK%^C%^WHITE%^u%^RED%^t%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^WHITE%^s%^BLACK%^s%^RED%^ slashes your opponent, flinging blood all over your face!");
say("%^BOLD%^%^RED%^ "+this_player()->query_cap_name()+"'s %^BLACK%^C%^WHITE%^u%^RED%^t%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^WHITE%^s%^BLACK%^s %^RED%^slashes %^RED%^his opponent and flings blood into "+this_player()->query_cap_name()+"'s face!"); 
result=(random(25))+((this_player()->query_level()));
return result;
}
}

int query_auto_load() {return 1; }

void make_death(object tp) {
   write("%^RED%^The evil in your soul explodes, and your body can't handle it.");
   tell_room(environment(tp), tp->query_cap_name()+" explodes!!!", ({ tp }));
   tp->die();
   this_object()->remove();
}

int check_anti(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "leviathas") {
     write("%^RED%^Your hand touches the stain on the hilt, your eyes roll back in your head and glow a deep red color. You see the world through your new eyes.");
     return 0;
   }
   write("%^BOLD%^%^BLACK%^Evil grips your soul.");
   call_out("make_death", 10, this_player());
   return 0;
}

void init() {
 ::init();
   add_action("check_anti", "wield");
}
