#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("Serrated Dagger");
   set_name("Serrated Dagger");
   set_id( ({"dagger"}) );
   set_long ("The long jagged edges of this dagger would leave a very messy cut in sombody.");
   set_weight(12);
   set_curr_value("gold", 121);
   set_wc(12);
   set_ac(2);
   set_type("knife");
   set_hit((: weapon_hit :));
    set_decay_rate(1000);

}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^Your daggers rips open a nasty looking wound in your opponent.%^RESET%^");
        say("%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+" rips open a nasty looking wound in "+atk->query_cap_name()+".");
       
result= (random(60)+(this_player()->query_level()));
    }
}
int query_auto_load() { if (this_player()->query_level() > 65) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 65) return 0;
   write("Wielding this sword would not be a good idea.");
   say(this_player()->query_cap_name()+" looks confused.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}

