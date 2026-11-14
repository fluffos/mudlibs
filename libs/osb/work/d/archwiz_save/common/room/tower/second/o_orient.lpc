#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("orient");
	::create();
	SetOfficeName("Orient Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Orient Board",
	    P_LONG:"It carries 'd.orient' (default) and all subgroups.\n",
	    "Groups":(({"d.orient","d.orient.\\."}))]));
	AddExit("east","./north1");
}
