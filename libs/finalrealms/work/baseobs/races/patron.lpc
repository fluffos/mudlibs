inherit "/std/races/standard";
inherit "/secure/patrons";
#include "light_defs.inc"

void setup() {
  set_long("Patrons are the creators of the mud.\n");
  set_name("patron");
  set_light_limits(LIGHT_PATRON_LOW, LIGHT_PATRON_HIGH);
}

// Fix by Radix, December 14, 1995
string query_desc(object ob) {
  return "The immortal Patron of "+query_patronage(ob->query_name())+".\n";
}
