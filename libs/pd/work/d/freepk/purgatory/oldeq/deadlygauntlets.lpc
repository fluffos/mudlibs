inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^");
   set_name("%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^");
   set_id( ({"gauntlets"}) );
   set_long ("%^CYAN%^Made for combat, these gauntlets have small spikes on the knuckles to deliver damaging punches.");
   set_weight(90);
   set_curr_value("gold", 121);
   set_wc(10);
   set_ac(3);
   set("skill level", 150);
   set_type("melee");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("You wear a pair of %^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^");
   set_unwield("You remove a pair of %^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 8) {
        write("%^BOLD%^%^WHITE%^You punch %^RESET%^"+atk->query_cap_name()+"%^BOLD%^%^WHITE in the face with your %^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^%^BOLD%^%^WHITE%^.");
        say("%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+" punches %^RESET%^"+atk->query_cap_name()+"%^BOLD%^%^WHITE%^ in the face with their %^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^%^BOLD%^%^WHITE%^.");
       
result= (random(46)+100);

    }
}
int query_auto_load() { if (this_player()->query_level() > 100) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_race() == "lich") return 0;
   write("No, no, no.. you've got it all wrong. You may not wield the %^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^ad%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^Ga%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^ts%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wielding something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}

