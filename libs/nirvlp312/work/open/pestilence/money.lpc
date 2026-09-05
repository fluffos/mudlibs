#include "/players/pestilence/ansi.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("funny money");
  set_alias("money");
  set_short("Funny money for Pesty's Strip Club");
  set_long(
"This is fake money used inside of Pesty's Strip Club.  It is used\n"+
"to tip strippers and can be 'exchanged' at the bar for coins.\n"
  );
  set_weight(1);
  set_value(10);
}

init() {
  add_action("tip_stripper","tip");
  add_action("cmd_barter","exchange");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("bill",environment(this_player()))) {
      write("Bill says: You sure your all done here?\n"+
            "Bill says: A few of the strippers might like some more tips.\n"+
            "Bill gives you 750 coins for your funny money.\n");
      this_player()->add_money(750);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("exchange what?\n");
}

tip_stripper(arg) {
   if(!arg) { notify_fail("Tip who?\n");
       return 0;}
   if(arg == "stripper"){
    if(present("stripper",environment(this_player()))) {
      write("Stripper walks up to you, and rubs her tits in your face.\n"+
            "She then takes the funny money from your mouth with her boobs\n"+
            "Stripper says: Thank you sweety.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
}
else
{
       notify_fail("Tip who?\n");
      return 0;
}
}
