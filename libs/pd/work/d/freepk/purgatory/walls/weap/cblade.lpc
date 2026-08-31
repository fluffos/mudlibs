inherit "/std/weapon";
#include <purgatory.h>
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("%^BOLD%^%^WHITE%^Crystal Blade%^RESET%^");
   set_name("Crystal Blade");
   set_id( ({"blade", "crystal blade"}) );
   set_long ("A strange type of weapon that has been made entirely out of crystal. Its edges look very sharp.");
   set_weight(45+random(50));
   set_curr_value("gold", 95);
   set_wc(8);
   set_ac(2);
   set("skill level", 300);
   set_type("blade");
   set_hit((: weapon_hit :));
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
write("%^BOLD%^%^WHITE%^The crystal flashes, blinding your opponent for a moment%^RESET%^");
    tell_room(environment(this_player()), "%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+
      " crystal blade flashes "+possessive(this_player())+" opponent blinding them for a moment.", ({ atk, this_player() }));
    tell_object(atk, "%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+" flashes you with  "
      ""+this_player()->query_title_gender()+" crystal blade!%^RESET%^");
result= (random(100)+100);
       if(random(100)> 5) { 
          query_wielded()->query_current_attacker()->set_paralyzed(3);}

    }
}
int query_auto_load() { if (this_player()->query_level() > 83) return 1; }
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 83) return 0;
   write("NO! You would cut yourself!!");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
