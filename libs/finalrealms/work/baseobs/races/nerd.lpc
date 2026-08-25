inherit "/std/races/standard";

string *inedible;

void setup() {
  set_long("A nerd is the most intelligent but also the stupiest "                        "character on FR-MUD.\n");
  set_name("nerd");
   set_light_limits(-200,200);
  reset_get();
}

void set_racial_bonuses() {
  previous_object()->adjust_bonus_int(45);
  previous_object()->adjust_bonus_dex(60);
  previous_object()->adjust_bonus_str(60);
  previous_object()->adjust_bonus_wis(-20);
  previous_object()->adjust_bonus_con(60);
  inedible = ({ "skull", "teeth" });
}

int query_skill_bonus(int lvl, string skill) {
  if (skill == "fighting")
    return 1300;
  if (skill == "faith")
    return 11300;
  if (skill == "other")
    return 1300;
  return 1000;
}

string query_desc(object ob) {
  if ((int)ob->query_gender() == 1)
    return "You want to smile when you see a nerd like him, but you know he " 
           "won't like it..\n";
  return "You can't understand why a girl can be such a nerd.\n";
}

int query_eat(string type) {
  return (member_array(type, inedible) == -1); 
}
