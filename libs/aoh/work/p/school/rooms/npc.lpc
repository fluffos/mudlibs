// TODO: room descriptions

#include <school.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("LPC Examples: NPC's");
  SetIntLong(" -- LPC Examples: NPC's -- \n"
   "This room contains some some example NPC's written especially "
   "to help with learning LPC.\n"
   "Read the source files for each one, as they are heavily commented. "
   "You can find the files in /p/school/examples/npc/, or try:\n"
   "'xmore $h.joe'.\n");

  AddExit("examples", "/p/school/rooms/example");

  AddItem("/p/school/examples/npc/questions");
  AddItem("/p/school/examples/npc/basic");

  CheckExit("examples", DACT_CHECK);
}

// We don't want the npc leaving and roaming about the school

int CheckAction( string action, string verb, string arg, int method )
{

  if("exit" == action && "examples" == verb &&
      this_player()->Query(P_IS_NPC) )
  {
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}
