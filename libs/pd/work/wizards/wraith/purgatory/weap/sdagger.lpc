inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("Serrated Dagger");
   set_name("Serrated Dagger");
   set_id( ({"dagger"}) );
   set_long ("The long jagged edges of this dagger make it look like it would leave a very messy cut in sombody.");
   set_weight(90);
   set_curr_value("gold", 121);
   set_wc(11);
   set_ac(2);
   set_type("knife");
   set_hit((: this_object(), "weapon_hit" :));


}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^Your daggers rips open a nasty looking wound in your opponent.%^RESET%^");
        say("%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+" rips open a nasty looking wound in "+atk->query_cap_name()+".");
       
result= (random(290)+35);
    }
}
int query_auto_load() { if (this_player()->query_level() > 55) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() =="Royal Assassin") return 0;
   write("This is not for you!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}

