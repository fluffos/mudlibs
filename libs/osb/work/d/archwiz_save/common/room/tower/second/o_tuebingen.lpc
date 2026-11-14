#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

void create() {
	SetDomainDirectory("tuebingen");
	::create();
        SetOfficeName("Tuebingen Domain");
        AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Tuebingen Board",
	    P_LONG:"It carries 'd.tuebingen' (default) and all subgroups.\n",
	    "Groups":(({"d.tuebingen","d.tuebingen.\\."}))]));
	AddExit("east","./west2");
}
