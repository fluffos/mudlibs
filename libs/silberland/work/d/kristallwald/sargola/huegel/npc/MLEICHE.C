inherit "std/thing";

#include <properties.h>
#include <moving.h>
#include "../def.h"

create()
{
  if (!is_clone(ME)) return;
  ::create();
  SetProp (P_SHORT, "Eine halb verweste Leiche");
  SetProp (P_LONG, BS("Du kannst nicht mehr viel erkennen, aber sie ist "
  	+"schrecklich zugerichtet. Der Mensch, der hier liegt muss nach "
  	+"schlimmen Kampf gen Himmel gefahren sein...\n"));
  	
  AddDetail(({"statur","mensch"}),
  	BS("Du kannst nur vermuten, dass es aufgrund der Statur ein Mensch "
  	+"sein muesste."));

  SetProp (P_NAME, "Leiche");
  SetProp (P_GENDER, FEMALE);
  SetProp (P_NOGET, 1);

  AddId ( ({"leiche" }) );
 
}
