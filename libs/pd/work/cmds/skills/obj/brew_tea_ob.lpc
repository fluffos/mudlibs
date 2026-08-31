//tea that can be brewed - NS
// made it a drink - Nulvect 20080515
#include <std.h>
inherit DRINK;

string check_short();
string check_long();
void check_extra();

void create() {
 ::create();
   set_name("tea");
   set_weight(2);
   set_value(0);
   set_short( (: check_short :) );
   set_long( (: check_long :) );
   set_id(({ "tea", "potion", "herbal tea" }));
   set_empty("cup");
   set_my_mess("You sip on some warm tea.");
   set_your_mess("sips on some tea.");
   set_strength(2);
   set_type("soft drink");
   set_extra( (: check_extra :) );
}

string query_tea_type() { return query_property("tea_type") || "unknown"; }

void do_antidote() {
  if (this_player()) this_player()->add_poisoned(-35);
}

string check_short() {
  if (this_player() && this_player()->query_skill("nature") >= 70+random(40))
    return "warm "+query_tea_type()+" tea";
  return "warm tea";
}
string check_long() {
  if (this_player() && this_player()->query_skill("nature") >= 70+random(40))
    return "A warm cup of "+query_tea_type()+" tea.";
  return "A warm cup of tea.";
}

void check_extra() {
  switch (query_tea_type()) {
    case "antidote": do_antidote(); break;
  }
}
