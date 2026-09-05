
#include "/players/wren/ansi.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("pouch");
  set_alias("pieces");
  set_short("clinking pouch");
  set_long(
"A black leather draw-string pouch. The clinking of coins and \n"+
"valuables can be heard when you shake it. The minting is not \n"+
"of this realm so you will need to convert it to Nirvana's  \n"+
"gold standard. Seek out someone to exchange them. \n"
  );
  set_weight(2);
  set_value(1500+random(1000));
}

init() {
  add_action("cmd_exchange","exchange");
}

cmd_exchange(str) {
  if(str="pouch") {
    if(present("comorant",environment(this_player()))) {
      write("Cormorant picks through the platinum and silver coins.  \n"+
            "He scrawls "+value+" in coins on a scrap of velum.\n"+
            "and says,\"I'll have to knock off some value for the \n"+
            "exchange but I assure you it is a fair deal.\"\n");
      this_player()->add_money(value);
      this_player()->add_weight(-2);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Exchange what?\n");
}
