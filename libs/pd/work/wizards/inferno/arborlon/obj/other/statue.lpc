// - Syphon  -
#include <lib.h>

inherit OBJECT;

void init() {
/*    ::init(); */
    add_action("read", "read");
}

void create() {
::create();
  set_short("%^MAGENTA%^a large statue%^RESET%^");
  set_name("statue");
  set_weight(5000);
  set_long("The large statue stands upwards of twenty feet tall. "
           "It is crafted in the image of lord Magnus, half-god. "
           "Magnus was the fierce paladin king, who liberated the "
           "Darkhold area from the forces of evil. This statue is "
           "of the finest craftsmenship. There is a plaque attatched "
           "to the base of the statue.");
  set_id(({"statue", "large statue"}));
  set_prevent_get("It's way too heavy to carry!.");
}

int read(string str) {
   if (str=="plaque") {
      write(
       "This statue is dedicated to all those who died in the war to "
       "claim Darkhold, and to the high lord, Magnus himself. This land "
       "has been declared the peaceful meeting-place of all the races. "
       "It has been fortold that when the elders of every race gather "
       "together in this place, the quest for immortal power will be "
       "unleashed upon the realms, and a common mortal shall be proven "
       "to be the incarnation of death, time, and life. This adventurer "
       "(the rest is scratched away)");
   return 1;
   }
}
