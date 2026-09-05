#ifndef __LDMUD__ /* New code below - Rumplemintz */
int full;

id(str) {
    if (str == "beer" && full)
  return 1;
    return str == "bottle";
}

short() {
    if (full)
  return "bottle of beer";
    return "empty bottle";
}

/* The shop only buys empty bottles ! */

query_value()
{
    if (!full) return 10;
    return 0;
}

long() {
    write(short() + ".\n");
}

reset(arg) {
    if (arg)
        return;
    full = 1;
}

drink(str)
{
    if (str && str != "beer" && str != "from bottle")
  return 0;
    if (!full)
  return 0;
    if (!call_other(this_player(), "drink_alcohol", 2))
  return 1;
    full = 0;
    write("It is really good beer!\n");
    say(call_other(this_player(), "query_name", 0) +
  " drinks a bottle of beer.\n");
    return 1;
}

init() {
    add_action("drink","drink");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
#else
/* a bottle of beer */

#include "/include/mudlib.h"
inherit DRINK;

void reset(status arg) {
  set_name("beer");
  set_empty_container("bottle");
  set_short("Bottle of Beer");
  set_long("The beer is help in an amber bottle.\n");
  set_weight(1);
  set_value(10);
  set_consumer_msg("It is really good beer!\n");
  set_room_msg("@@query_name:$this_player()$@@ drinks a bottle of beer.\n");
  set_alco_drink(1);
  set_strength(2);
}

#endif

