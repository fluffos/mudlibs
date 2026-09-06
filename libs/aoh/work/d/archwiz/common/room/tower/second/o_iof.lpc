#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("iof");
	::create();
	SetOfficeName("'Island of Fighters' Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The IOF Domain Board",
	    P_LONG:"It carries 'd.iof' (default) and all subgroups.\n",
	    "Groups":(({"d.iof","d.iof.\\."}))]));
	AddExit("west","./north1");
}
