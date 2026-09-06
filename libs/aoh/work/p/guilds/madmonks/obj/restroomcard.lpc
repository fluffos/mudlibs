// similar to the hotel-card
// made by magictcs 20 may 97

#include <config.h>
#include <properties.h>
#include <stdrooms.h>

inherit "std/thing";

string home;

create() {
  ::create();
  SetShort(0);                     // invisible
  /* This default setting will be overwritten */
  home = this_player()->QueryHome();
}

simple_obj() { replace_program("/p/guilds/madmonks/obj/restroomcard"); }

init() {
  ::init();
  call_out("wake_up",3); 
}

int wake_up() {
  write(
    "You wake up well rested in the restroom of the Madmonks Guild.\n"
    "Welcome back to the game!\n");
  home=(string)Query(P_AUTOOBJECT); /* Has been saved */
  this_player()->SetHome(home); /* Set the player's home back */
  call_out("mach_putt",1);
  return 1;
}

void mach_putt() {
  destruct(this_object());
}

SetNewHome(str) {
  Set(P_AUTOOBJECT,(str));
}

