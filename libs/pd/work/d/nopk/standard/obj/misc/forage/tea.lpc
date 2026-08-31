//tea that can be brewed - NS
#include <std.h>
inherit OBJECT;

string type;
void set_type(string str);
string query_type();

void init() {
  add_action("drink", "drink");
}

void set_type(string str) {
  type = str;
}

string query_type() { return type; }

void create() {
 ::create();
   set_name("tea");
   set_weight(2);
   set_value(0);
   set_id(({ "tea", "potion", "herbal tea" }));
}

int drink(string str) {
  if(!id(str))
    return 0;
  if(this_player()->query_current_attacker()) {
    notify_fail("You are too busy to drink anything!\n");
    return 0;
  }
  write("You sip on some nice warm tea.");
  say(this_player()->query_cap_name()+" sips on some tea and smiles.");
  if(type == "poison") {
    this_player()->add_poisoning(40);
    write("You begin to feel nausious.");
    remove();
    return 1;
  }
  if(type == "healing") {
    this_player()->add_hp(40);
    remove();
    return 1;
  }
  if(type == "antidote") {
    this_player()->add_poisoning(-40);
    remove();
    return 1;
  }
}
