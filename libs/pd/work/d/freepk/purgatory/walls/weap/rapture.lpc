inherit "/std/weapon";
#include <purgatory.h>
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("%^BOLD%^%^BLUE%^Sw%^WHITE%^or%^BLUE%^d%^WHITE%^ of %^BOLD%^%^RED%^Ra%^WHITE%^pt%^RED%^ur%^WHITE%^e%^RESET%^");
   set_name("Sword of Rapture");
   set_id( ({"rapture", "sword", "sword of raputre"}) );
   set_long ("A very decorative sword, jewels and moonstones adorn the hilt. The blade is made of a very decorative %^BOLD%^%^BLACK%^black%^RESET%^ steel and looks to be very sharp. A heron has been molded to the hilt and one engraved on the base of the blade.");
   set_weight(90);
   set_curr_value("gold", 50+random(50));
   set_wc(9);
   set_ac(2);
   set("skill level", 300);
   set_type("blade");
   set_hit((: weapon_hit :));

   set_wield("A feel of grace and power flows up through your arm as you wield the sword.");
   set_unwield("You sigh as you release the hilt of the Sword of Rapture.");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) > 90) {
        write("%^BOLD%^%^BLACK%^The dark steel of the blade slices easily through your foe!%^RESET%^");
    tell_room(environment(this_player()), "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+
      " slices easily through "+possessive(this_player())+" opponent with the "
      "%^BOLD%^%^BLUE%^Sw%^WHITE%^or%^BLUE%^d%^WHITE%^ of %^BOLD%^%^RED%^Ra%^WHITE%^pt%^RED%^ur%^WHITE%^e%^BOLD%^%^BLACK%^!%^RESET%^", ({ atk, this_player() }));
    tell_object(atk, "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" slices easily through your armour "
      "with "+this_player()->query_title_gender()+" sword!%^RESET%^");
       
result=(random(20))+((this_player()->query_level()/2));

    }
}
int query_auto_load() { if (this_player()->query_level() > 50) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 83) return 0;
   write("You would hurt yourself if you tried this sword out.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
