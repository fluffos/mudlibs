inherit "/std/weapon";
#include <castlewall.h>
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("%^BOLD%^%^BLACK%^Majiked Shortsword%^RESET%^");
   set_name("%^BOLD%^%^BLACK%^Majiked Shortsword%^RESET%^");
   set_id( ({"sword", "shortsword", "short sword"}) );
   set_long ("Foreged by the Dark Magi of Purgatory, this sword has only been given out to the best of swordsmen.");
   set_weight(50+random(50));
   set_curr_value("gold", 25+random(75));
   set_wc(8);
   set_ac(1);
   set("skill level", 200);
   set_type("blade");
   set_hit((: weapon_hit :));

   set_wield("%^BOLD%^%^BLACK%^The Dark Majiks tear at your soul as you wield the blade.%^RESET%^");
   set_unwield("%^RESET%^%^CYAN%^You gasp in relief as you unwield the blade.%^RESET%^");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) > 90) {
        write("%^BOLD%^%^WHITE%^The majiks in the sword reach out and cleave "+atk->query_cap_name()+"'s soul in twine.%^RESET%^");
        say("%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+"'s sword blasts "+atk->query_cap_name()+" with a burst of majik. .");
       
result=(random(20))+((this_player()->query_level()/2));

    }
}
int query_auto_load() {
  if (this_player()->query_level() > 45)
  if (this_player()->query_subclass() == "ranger") return 0;
  return 1;
}

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 45) return 0;
   write("This belongs to the %^BOLD%^%^BLACK%^Dark %^WHITE%^Archers%^RESET%^!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
