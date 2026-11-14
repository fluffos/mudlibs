/*
**
**  
**
** 
**
**  [m] Mateese
*/

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <rooms.h>

#define LOGFILE MPL+""
#define VERSION ""

inherit "/std/room";

/*-------------------------------------------------------------------------
*/

create() {
  room::create();
  SetIntShort ("");
  SetIntLong (
"\n"
              );
  AddExit ("dir", "roomfile");
  AddSpecialExit ("dir", "lfun_name");
  AddDetail ("detail", "description\n");
  AddSpecialDetail ( ({ "spotlight", "spot", "light" }), "lfun_name");
  AddRoomCmd ("verb", "lfun");
  AddItem ("item", REFRESH_);
  /* SetIntLight(1); */
  Set(P_INDOORS, 1);
}

init() {
  room::init();
}

/*************************************************************************/
