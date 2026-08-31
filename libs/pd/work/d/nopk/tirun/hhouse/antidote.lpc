#include <std.h>
#include <tirun.h>
#include <locations.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("potion");
    set_short("%^RESET%^%^BOLD%^Strange potion%^RESET%^");
    set_long(
        "The bottle has a small label on it:\n\n\n\t\tAntidote.\n");
    set_weight(2);
    set_id(({"potion","strange potion","good_potion_QO", "antidote"}));
}

void init() {
  ::init();
  add_action("drink", "drink");
}

int drink(string str) {
  if(!str) return 0;

  if(this_object() != present(str, this_player()))
    return notify_fail("Drink what?\n");

  write("You throw your head back and down the antidote.");
  say(this_player()->query_cap_name()+" drinks a potion.");
  write("%^ORANGE%^Your stomach feels warm and tingly.%^RESET%^");
  say(this_player()->query_cap_name()+" smiles and holds "+possessive(this_player())+" stomach.");
  if(present("bad_potion_QO", get_object(TEMP_LOC)))
    write("You feel the potions interact...  but the antidote fails you!");
  return 1;
}
