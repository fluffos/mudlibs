#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_name("axe");
    set_short("Waraxe - Grungdel's Undying Rage");
    set_type("axe");
    set_weight(33);
    set_hands(2);
    set_long("The waraxe is a huge weapon, built for those possessing unearthly strength, such as 

the demons of the underworld. The weapon stands at five feet tall, from the base of the hilt to 

the tip of each of the blades, with a shaft of some unknown black wood and blades crafted from 

black obsidian glass. The axe has two blades, one on each side, each of which bears great 

serrations along the bladed end. A woodsman's axe this is not. It is said that this weapon bears 

a fraction of the soul of the greatest mortal warrior known to the underworld, a mighty giant by 

the name of Grungdel who traded her soul for demonic power in the form of this weapon, among 

other things.");
   set_id(({ "waraxe","grungdel","rage","undying rage","axe" }));
   set_wc(16);
   set_curr_value("gold", random(100)+750);
   set_hit((: this_object(), "weapon_hit" :));
}

int query_auto_load() { if(this_player()->query_level() > 49) {return 1; }}

int weapon_hit() {

    int result;
    object ob;
    ob=(object)this_player()->query_current_attacker();
    if(random(10) > 7) {
      result = this_player()->query_stat("strength") + (this_player()->query_skill("attack")/5);
      message("info", ""+this_player()->query_cap_name()+" slashes at "+ob->query_cap_name()+" 

with two great sweeps of "+this_player()->query_possessive()+" waraxe.", environment(ob), ({ob, 

this_player()}));
      write("You make two heavy strikes at "+ob->query_cap_name()+" with your waraxe.", 

this_player());
      message("info", ""+this_player()->query_cap_name()+" slashes at you with two great sweeps 

of "+this_player()->query_possessive()+" waraxe.", environment(ob), ({ob, this_player()}));
      if(present("crazie",this_player()))
      {
        write("%^BOLD%^%^RED%^You roar ferociously!");
        message("berserk","%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" roars 

ferociously!",environment(this_player()),this_player());
        result = result*3/2;
      }
      return result;
    }
}
