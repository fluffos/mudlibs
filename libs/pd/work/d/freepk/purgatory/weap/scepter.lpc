#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("%^BOLD%^%^YELLOW%^The Queens Scepter%^RESET%^");
   set_name("%^BOLD%^%^YELLOW%^The Queens Scepter%^RESET%^");
   set_id( ({"scepter"}) );
   set_long ("%^BOLD%^%^YELLOW%^The Queens scepter is lined in gold and looks very dented from recent use.");
   set_weight(20);
   set_curr_value("gold", 100);
   set_wc(13);
   set_ac(2);
   set("skill level", 175);
   set_type("blunt");
   set_hit((: weapon_hit :));
    set_decay_rate(2000);
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^BOLD%^%^YELLOW%^You bring the sceptar crashing down on "+atk->query_cap_name()+"'s head   ");
        say("%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+" brings their scepter crashing down on "+atk->query_cap_name()+"'s head.");
       
result=(random(60))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 85) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 85) return 0;
   write("Only the queen may wield this.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
