#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"slayer","drow slayer","sword"}));
  set_name("drow slayer");
  set("short","A Drow Slayer");
  set("long","This sword kills those nasty drows with ease.");
  set_weight(15);
    set_curr_value("gold", 200);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_ac(1);
  set_wc(14);
  set_type("blade");
  set_decay_rate(500);
}

int weapon_hit(object attacker) {
  if(random(10) <= 2){
    if((string)attacker->query("race") == "drow"){
      write("Your Drow Slayer glows with a %^BOLD%^%^YELLOW%^H%^WHITE%^o%^YELLOW%^l%^WHITE%^y%^YELLOW%^ l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t%^RESET%^ as it destroys your opponent.");
      say(this_player()->query_cap_name()+" growls as their Drow Slayer %^YELLOW%^glows%^RESET%^ with a holy vengance.", attacker);
      message("info",this_player()->query_cap_name()+" strikes you viciously with their %^YELLOW%^glowing%^RESET%^ Drow Slayer!", attacker);
      return random(40)+20;
    }
  }
    else return 0;
}
