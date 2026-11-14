#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("iof");
	::create();
	SetOfficeName("'Plex' Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Plex Domain Board",
	    P_LONG:"It carries 'd.plex' (default) and all subgroups.\n",
	    "Groups":(({"d.plex","d.plex.\\."}))]));
	AddExit("west","./north1");
}
