#include "std.h"

   object party;
    int new;
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

#undef EXTRA_INIT
#define EXTRA_INIT\
   extra_init();
extra_reset() {
       if (!new) {
         move_object(clone_object("obj/partylist"),this_object());
   party = clone_object("obj/partyob.c");
   move_object(party, this_object());
   new = 1;
}
}
ONE_EXIT("room/shop.c", "west",
  "The party room",
  "This room looks like a meeting area. Adventurers gather here to form\n" +
  "partys to go out and seek their fortune in groups rather than alone.\n" +
  "If there is no party object here press the button on the wall.\n"+
  "If you wish to form a party, have the player you want to be your leader\n"+
  "pick up the party object and add members and set shares to make the party\n"+  "The only exit is west.\n", 1)
extra_init() {
  add_action("press","press");
  add_action("press","push");
 }
press(str) {
  if(str!="button") return 0;
  if(present("party",this_object())) {
   write("There already is one in the room!\n");
   return 1;
  }
    party = clone_object("obj/partyob.c");
   move_object(party, this_object());
   say("An object appears in a puff of smoke.\n");
   write("An object appears in a puff of smoke.\n");

   return 1;
 }
