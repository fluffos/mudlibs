/* Extension of my Home Room */

#include "/players/mateese/mydefs.h"

#include <config.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort ("Western part of Mateese's home");
  SetIntLong (
"This is Mateese's home: a medium sized room, extending further to the east.\n"+
"It is completely empty here, there is just one large window here, showing\n"+
"the dark sky. You realize that the room must be high above the athmosphere.\n"+
"Nevertheless, there is a balcony outside, accessible through a magic field.\n"
              );
  AddExit ("west", MR+"homebalcon");
  AddExit ("east", MR+"home");
  AddDetail ("window", "You see the dark sky and some stars.\n");
  AddDetail ("balcony", "Enter and and see...\n");
  AddDetail ("field", "A field sealing off the room, but trespassable.\n");
  AddRoomCmd ("west", "fwest"); /* will return 0 */
  Set(P_INDOORS, 1);
  SetBright (MAX_SUNBRIGHT/4);
}

fwest(str) {
  if (str) return 0;
  write ("You wiggle through the magic field.\n");
  return 0;
}
