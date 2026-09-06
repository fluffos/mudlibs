/* The default workroom for new wizards. It's copied to their homedir */

#ifndef NAME
#define NAME "Someone"
#endif

#include <stdrooms.h>
#include <properties.h>

inherit "/std/room";

public varargs void create() {
  ::create();
  Set(P_INT_SHORT, "The workroom of " NAME);
  Set(P_INT_LONG, "This is the workroom of " NAME ".\n"
      "Since " NAME " is just a new wizard, it is completely empty, but "
      "nevertheless quite comfortable.\n"
  );
  AddExit("out", STARTROOM);
}
