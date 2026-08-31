//herbs
#include <std.h>
inherit OBJECT;

string type;
void set_type(string str);
string check_skills();

void init() {
  add_action("eat", "eat");
}

void create() {
 ::create();
   set_short("A strange herb");
   set_name("herb");
   set_long((: check_skills :));
   set_weight(2);
   set_value(0);
   set_id(({ "herb", "plant" }));
}

void set_type(string str) {
  type = str;
  set_id(({ "herb", "plant", str }));
}

string check_skills() {
  int skil;
  if(this_player()->query_subclass() != "ranger")
    return "It's a funny looking plant.\n";
  skil = this_player()->query_skill("nature");

  if(skil < 10)
    return "It's a funny looking plant.\n";
  if(skil < 20)
    if(type != "poison")
      return "It's a good plant for brewing.\n";
    else
      return "It would be dangerous to brew with this plant.\n";
  return "It appears to be a herb of "+type+".\n";
}

int eat(string str) {
  if(!id(str))
    return 0;
  if(this_player()->query_current_attacker()) {
    notify_fail("You are too busy to eat anything!\n");
    return 0;
  }
  write("You chew on the bitter herb.");
  say(this_player()->query_cap_name()+" chews on an herb and grimaces at the taste.");
  if(type == "poison") {
    this_player()->add_poisoning(20);
    write("You begin to feel nausious.");
    remove();
    return 1;
  }
  if(type == "healing") {
    this_player()->add_hp(20);
    remove();
    return 1;
  }
  if(type == "antidote") {
    this_player()->add_poisoning(-20);
    remove();
    return 1;
  }
}
