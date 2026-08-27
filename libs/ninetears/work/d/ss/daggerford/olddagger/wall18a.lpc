#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(100);
	set_short("Wall street");
	set_long("You are on Wall street. "+
"This area looks as though it has been recently under construction.  "+
"Just to the north, you see a new building, still surrounded by boards and "+
"bits of construction equipment.  There is a large sign on the building "+
"which reads Daggerford Medical Clinic.  Hmm...sounds like a name you'll "+
"want to remember.\n");
        add_exit("north",ROOM+"clinic", "door");
        add_exit("east", ROOM+"wall19", "corridor");
        add_exit("west", ROOM+"wall18", "corridor");
        add_item("clinic", "The newly-opened Daggerford Clinic offers a wide "+
"variety of services...well, no it doesn't, really.  The only thing is offers "+
"is that if some big ol' ugly monster beats the snot out of you, they will "+
"patch you up (for a not-inconsequential fee, of course).  If you are "+
"really good, they might even send the monster a nasty letter or "+
"something.\n\n");
	set_monster(NUM, "city");
	set_zone("city");
}
