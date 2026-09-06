#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("archwiz");
	::create();
	SetOfficeName("Archwiz Domain");
	AddExit("north","./west1");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Archwiz Domain Board",
	    P_LONG: "It carries 'd.archwiz' (default) and all subgroups.\n",
	    "Groups":(({"d.archwiz","d.archwiz.\\."}))]));
}
