/*
This is an example of an item that can be bartered.  Bartering
is preferred over simply 'cash'ing an item, because it requires
the player to go to a little more work to get the full value
of an item.  In general, an item should not have a cash or
barter command if its value is less than 1000 coins.
				-Feldegast
*/

#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("silk");
  set_alias("spidersilk");
  set_short("Spidersilk");
  set_long(
"This bundle of slightly sticky silk was almost certainly\n"+
"made by a giant spider due to its great volume and\n"+
"thickness.  You could probably 'barter' this with the\n"+
"right person.\n"
  );
  set_weight(2);
  set_value(4500+random(1000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("bedira",environment(this_player()))) {
      write("Bedira looks interested in your bundle of spidersilk, but\n"+
            "negotiates its price down to "+value+" coins.  He smiles\n"+
            "and says,\"If you manage to get any more, bring it to me.\n"+
            "Spidersilk is an excellent binder of magical energies.\"\n");
      this_player()->add_money(value);
      this_player()->add_weight(-2);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
