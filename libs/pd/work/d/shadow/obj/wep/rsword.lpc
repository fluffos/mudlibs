#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

int weapon_hit(object attacker);

void create() {
  ::create();

  set_id(({"slayer","drow slayer","sword"}));
  set_name("drow slayer");
  set_short("A Drow Slayer");
  set_long("This sword kills those nasty drows with ease.");
  set_weight(15);
  set_curr_value("gold", 105);
  set_hit( (: weapon_hit :) );
  set_ac(1);
  set_wc(10);
  set_type("blade");
  set_decay_rate(500);
}

int weapon_hit(object attacker) {
  object tp = environment();
  if (random(100) >= 80) {
    if ((string)attacker->query_race() == "drow") {
      write("Your Drow Slayer glows with a %^BOLD%^%^YELLOW%^H%^WHITE%^o%^YELLOW%^l%^WHITE%^y%^YELLOW%^ l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t%^RESET%^ as it destroys your opponent.");
      say(tp->query_cap_name()+"'s Drow Slayer %^YELLOW%^glows%^RESET%^ with a holy light.", attacker);
      message("info",tp->query_cap_name()+" strikes you viciously with "+tp->query_possessive()+" %^YELLOW%^glowing%^RESET%^ Drow Slayer!", attacker);
      return random(20)+20;
    }
  }
  else return 0;
}
