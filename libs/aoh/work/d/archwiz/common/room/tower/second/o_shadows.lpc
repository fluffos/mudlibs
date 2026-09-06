/*
* The domain-office of Shadows
* by Thragor, Lord of Shadows, 03mar94
*/

#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");
 
void create()
{
  SetDomainDirectory("shadows"); // Must come first
  ::create();
  SetOfficeName("Shadows Domain");
   AddItem("/std/board",REFRESH_HOME,
     ([P_SHORT:"The Domain-Board of Shadows",
       P_LONG:"This is a dirty table made of rock and some slaves engrave new notes\n\
here. At the top of the table you see in big letters: D.SHADOWS.\n",
       "Groups":(({"d.shadows","d.shadows.\\."}))]));
  AddExit("north","./east2");
}
