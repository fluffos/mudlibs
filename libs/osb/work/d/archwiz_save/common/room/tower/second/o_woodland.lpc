#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("woodland");
	::create();
	SetOfficeName("Woodland Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Woodland Domain Board",
	    P_LONG:"It carries 'd.woodland' (default) and all subgroups.\n",
	    "Groups":(({"d.woodland","d.woodland.\\."}))]));
	AddExit("west","./south1");
}
