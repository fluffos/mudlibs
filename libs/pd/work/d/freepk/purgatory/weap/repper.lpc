#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);

create() {
    ::create();
   set_short("Repper");
   set_name("%^BOLD%^%^RED%^Re%^RESET%^%^RED%^pp%^BOLD%^%^RED%^er%^RESET%^");
   set_id( ({"repper", "sword"}) );
   set_long ("An odd looking sword, one side has been horrible serrated and looks like you could saw through a tree with it. The other edge is so sharp it appears dull, but will cut through the finest of metals.");
   set_weight(20);
   set_curr_value("gold", 96);
   set_wc(11);
   set_ac(2);
   set("skill level", 75);
   set_type("blade");
   set_hit((: weapon_hit :));
    set_decay_rate(1000);
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 30) {
        write("%^RESET%^%^ORANGE%^The serrated edge of the blade rips "+atk->query_cap_name()+"'s belly open!%^RESET%^");
        say("%^RESET%^%^ORANGE%^"+(string)this_player()->query_cap_name()+" rips open the belly of "+atk->query_cap_name()+" with their sword.%^RESET%^");
       
result=(random(60))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 65) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 65) return 0;
   write("What in the hell are you doing with Jacks sword?");
   say(this_player()->query_cap_name()+" is a theif!!! Catch them!!", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
