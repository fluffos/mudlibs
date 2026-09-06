/*--------------------------------------------------------------------------
 *  /p/school/school.c --  LPC Learning Center
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <rooms.h>
#include <school.h>

int tutorials();


inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort(
   "The LPC Learning Center");
  SetIntLong(
   "This is the Learning Center for New Wizards of Age of Heroes. "
   "Any of our LPC coding tutorials can be accessed from this "
   "room. To see a list of the tutorials currently available, "
   "type 'tutorials'.\n"
   "The areas branch out from here into: tutorials, examples (nothing "
   "else at the moment).\n"
   "You can return to this room at any time by typing 'school' (as long "
   "as you are still in one of the school rooms).\n");

  AddExit("tutorials", TUTORIAL("editor1/han_ed") );
  AddExit("examples", ROOMS("example") );

}
