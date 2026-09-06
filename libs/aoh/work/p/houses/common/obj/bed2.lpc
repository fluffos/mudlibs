/************************************************************/
/* This file has been done by Joern for the Woodland Domain */
/************************************************************/
/* Last Update: September 27th '94      [Joern]             */
/************************************************************/

inherit "std/thing";

create(){
 ::create();
 SetShort("a bed with satin bed linen");
 SetLong("It looks very comfortable! You can sleep in it.\n");
 AddId("bed");
 AddId("satin bed");
 AddAdjective("comfortable");
 SetWeight(20000);
 SetValue(2000);
 SetNoGet("You can't steal the bed!\n");
}

init() {
 ::init();
 add_action("rest","sleep");
}

rest() {
  write("You enjoy a nice nap.\n");
  say(this_player()->QueryName()+" sleeps in the bed.\n", this_player());
  return 1;
}
