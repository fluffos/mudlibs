#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("daydream");
	::create();
	SetOfficeName("Daydream Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Daydream Domain Board",
	    P_LONG:"This board carries 'd.daydream' (default) and all subgroups.\n",
	    "Groups":(({"d.daydream","d.daydream.\\."}))]));
	AddExit("west","./north2");
}
