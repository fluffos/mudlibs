/* The blcony outside of my home. */

#include "/players/mateese/mydefs.h"

#include <config.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort ("The balcony outside");
  SetIntLong (
"You are standing on a balcony hewn out of the mountains rocks. It is quite\n"+
"cold here, and the only lighting comes from the stars around and above.\n"+
"Below you see the clouds in the upper layers of the athmosphere.\n"
              );
  AddExit ("east", MR+"homeextend");
  AddDetail ("stars", "All those stars...\n");
  AddDetail (({"cloud", "clouds"}), "They shape and move as you watch.\n");
  Set(P_INDOORS, 1);
  SetBright (MAX_SUNBRIGHT/10);
}
