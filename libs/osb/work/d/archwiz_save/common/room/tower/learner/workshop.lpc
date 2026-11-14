#include "path.h"

inherit "/std/room";

create()
{
  ::create();
  SetIntShort("Learners workshop");
  SetIntLong(
"This is a rather great room. Its enforced walls give notice of "
"the not uncomplicated experiments which the learners perform here "
"to get the skills and knowledge of a true wizard. "
"Oddly, there are also some workbenches fixed to the floor. "
"A door leads west into the main room.\n"
    );
  AddDetail(({"workbenchs","workbenches"}),
"These are workbenches of the type used in steel works and similar "
"companies. One of the equipping wizards definitely has strange "
"ideas about the training of apprentices.\n"
    );
  AddDetail("workbench",
"As you look closer at one of the workbenches, you notice "
"a small sign reading '=RJ='.\n"
    );
  /* 'Workbench' was the name of Amiga's GUI, Mateeses favourite computer
   * at the time of the writing. '=RJ=' was the signature of R.J. Mical,
   * the author of Amigas windowing system 'Intuition'.
   */
  AddExit("west","./main");
}
