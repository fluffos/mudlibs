#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

create()
{
    SetDomainDirectory("avalon");
    ::create();
    AddItem("/std/board",REFRESH_HOME,
      ([P_SHORT:"The Avalon Domain Board",
	P_LONG:"It carries 'd.avalon' (default) and all subgroups.\n",
	"Groups":(({"d.avalon","d.avalon.\\."}))]));
    SetOfficeName("Avalon Domain");
    AddExit("south","./west2");
    AddExit("north","/d/avalon/common/village/place");
    AddDoor("east","/players/sique/workroom","small door","This door leads into Sique's workroom.\n",0,1);
}
