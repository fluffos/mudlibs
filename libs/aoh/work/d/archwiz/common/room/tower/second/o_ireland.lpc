#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

create()
{
    SetDomainDirectory("ireland");
    ::create();
    AddItem("/std/board",REFRESH_HOME,
      ([P_SHORT:"The Ireland Domain Board",
	P_LONG:"It carries 'd.ireland' (default) and all subgroups.\n",
	"Groups":(({"d.ireland","d.ireland.\\."}))]));
    SetOfficeName("Ireland Domain");
    AddExit("west","./south2");
}
