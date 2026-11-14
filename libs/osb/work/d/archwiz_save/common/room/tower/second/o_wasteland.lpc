#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("wasteland");
	::create();
	SetOfficeName("Wasteland Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Wasteland Domain Board",
	    P_LONG:"It carries 'd.wasteland' (default) and all subgroups.\n",
	    "Groups":(({"d.wasteland","d.wasteland.\\."}))]));
	AddExit("south","./east1");
}
