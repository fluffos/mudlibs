#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("vecna");
	::create();
	SetOfficeName("Vecna's Realm");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Vecna's Realm Board",
	    P_LONG:"It carries 'd.vecna' (default) and all subgroups.\n",
	    "Groups":(({"d.vecna","d.vecna.\\."}))]));
	AddExit("south","./east2");
}
