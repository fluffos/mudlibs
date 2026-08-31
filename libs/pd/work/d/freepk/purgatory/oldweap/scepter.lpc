inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^YELLOW%^The Queens Scepter%^RESET%^");
   set_name("%^BOLD%^%^YELLOW%^The Queens Scepter%^RESET%^");
   set_id( ({"scepter"}) );
   set_long ("%^BOLD%^%^YELLOW%^The Queens scepter is lined in gold and looks very dented from recent use.");
   set_weight(90);
   set_curr_value("gold", 100);
   set_wc(12);
   set_ac(2);
   set("skill level", 175);
   set_type("blunt");
   //set_hit((: this_object(), "weapon_hit" :));
    set_decay_rate(2000);
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^YELLOW%^You bring the sceptar crashing down on "+atk->query_cap_name()+"'s head   ");
        say("%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+" brings their scepter crashing down on "+atk->query_cap_name()+"'s head.");
       
result= (random(60)+35);

    }
}
int query_auto_load() { if (this_player()->query_level() > 60) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "Queen Shorla") return 0;
   write("Only the queen may wield this.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
