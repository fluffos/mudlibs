#include "path.h"
#include <config.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort ("Learners Dormatory");
  SetIntLong (
"This is the dormatory of the learners, a darkened quiet room. "
"You see many beds here, and if you're lucky, you can also see someone "
"in them.\n"
"The main room is to the north.\n"
             );
  AddDetail (({"bed", "beds"}), 
"Lots of inviting beds. Currently there is noone sleeping here, though.\n"
            );
  AddExit ("north","./main");
  SetBright (MAX_SUNBRIGHT/3);
}
