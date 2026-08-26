// File: _bury.c
// Date: July 23rd, 1997.
// Purpose: To get rid of them smelly things known as corpses.
// Original Initative: Nightmask
// Fixed by Cyanide
// (04-06-98) Chronos added a help() function.

#include <mudlib.h>
inherit DAEMON;

int cmd_bury(string str) {
  object corpse;

   if (!str) {
     write("Bury what?\n");
  return 1;
 }
   corpse = present("dead body", environment(TP));
   if (str == "corpse" && (corpse)) {
     write("You bury a corpse in the ground.\n");
     say(TPN+" buries a corpse in the ground.\n");
     corpse->remove();
     return 1;
  }
   return 0;
 }

string help() {
  return @ENDHELP
Usage: bury corpse

This command allows you to bury a corpse.  Eeew.
ENDHELP
  ;
}
