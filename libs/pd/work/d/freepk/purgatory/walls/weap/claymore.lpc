inherit "/std/weapon";
#include <purgatory.h>
int weapon_hit(object atk);
 
create() {
    ::create();
   set_name("Runed Claymore");
   set_short("%^RESET%^%^GREEN%^Ru%^CYAN%^ne%^GREEN%^d %^BOLD%^%^WHITE%^Claymore%^RESET%^");
   set_id( ({"sword", "claymore", "runed claymore"}) );
   set_long ("%^BOLD%^%^BLACK%^This sword is a good 4 foot long. %^RESET%^%^GREEN%^En%^CYAN%^cha%^GREEN%^nt%^CYAN%^ed %^BOLD%^%^RED%^r%^BLACK%^un%^RED%^es%^BLACK%^ have been engraved down the length of the blade, enhancing its strength.%^RESET%^");
   set_weight(40+random(30));
   set_curr_value("gold", 70+random(20));
   set_wc(9);
   set_ac(2);
   set("skill level", 300);
   set_type("blade");
   set_hit((: weapon_hit :));

   set_wield("You stagger under the weight of the sword as you wield it.");
   set_unwield("Your arm feels numb as you let go of the hilt.");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^BOLD%^%^BLACK%^The %^RED%^r%^BLACK%^un%^RED%^es%^YELLOW%^ glow%^BLACK%^ as you slice deep into "+atk->query_cap_name()+".%^RESET%^");
        say("%^BOLD%^%^BLACK%^The %^RED%^r%^BLACK%^un%^RED%^es%^BOLD%^%^BLACK%^ on "+(string)this_player()->query_cap_name()+"'s sword %^BOLD%^%^YELLOW%^glow%^BLACK%^ as they slice "+atk->query_cap_name()+".%^RESET%^");
       
result=(random(40)+100)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 83) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 83) return 0;
   write("You would not be able to move if you wielded this sword.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
