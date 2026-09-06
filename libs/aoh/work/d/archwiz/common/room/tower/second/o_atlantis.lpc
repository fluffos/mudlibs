#include <rooms.h>
#include <properties.h>
#include "path.h"

inherit STD("d_office");

void create() {
	SetDomainDirectory("atlantis");
	::create();
	SetOfficeName("Atlantis Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Atlantis Domain Board",
	    P_LONG:"It carries 'd.atlantis' (default) and all subgroups.\n",
	    "Groups":(({"d.atlantis","d.atlantis.\\."}))]));
	AddExit("north","./west2");
}
