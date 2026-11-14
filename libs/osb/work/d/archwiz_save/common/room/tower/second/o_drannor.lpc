#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("d_office");

create()
{
    SetDomainDirectory("drannor");
    ::create();
    AddItem("/std/board",REFRESH_HOME,
      ([P_SHORT:"The Myth Drannor Domain Board",
	P_LONG:"It carries 'd.drannor' (default) and all subgroups.\n",
	"Groups":(({"d.drannor","d.drannor.\\."}))]));
    SetOfficeName("Myth Drannor Domain");
    AddExit("north", "./south2");
    AddExit("west","/d/drannor/common/city/reg22/castle/members/c-s-1-1");
}
