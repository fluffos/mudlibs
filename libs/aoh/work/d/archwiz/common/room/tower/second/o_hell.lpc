#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("hell");
	::create();
	SetOfficeName("Hell Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Hell Domain Board",
	    P_LONG:"It carries 'd.hell' (default) and all subgroups.\n",
	    "Groups":(({"d.hell","d.hell.\\."}))]));
	AddExit("east","./south1");
}
