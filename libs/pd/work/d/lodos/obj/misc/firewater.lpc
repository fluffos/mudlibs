#include <std.h>
inherit DRINK;

void create() {
 ::create();
   set_name("firewater");
   set_type("soft drink");
   set_strength(2);
   set_weight(2);
    set_curr_value("gold", 2);
   set_short("a glass of firewater");
   set_empty_name("glass");
}

int drink_me(string str) {
   if (!str || present(str, environment(this_object())) != this_object())
     return 0;
   write("Blah!");
   return 0;
}

void init() {
 ::init();
   add_action("drink_me", "drink");
}
