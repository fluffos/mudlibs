inherit "std/room";

#include <moving.h>
#include <rooms.h>
#include <config.h>

create() {
  ::create();
  SetIntShort("Dam Lobby");
  SetIntLong(
"This room appears to have been the waiting room for groups touring "
"the dam. There is an open doorway to the east marked ``PRIVATE'' and "
"a path leading north over the top of the dam.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"room","dam lobby","lobby","waiting room"}),#'IntLong);
  AddDetail(({"doorway","open doorway"}),"It is marked as ''PRIVATE''\n");
  AddDetail(({"path"}),"It leads over the top of the dam.\n");
  AddDetail("dam","You should go north to have a better view.\n");
  AddExit("east","./dam_maintance");
  AddExit("north","./dam");
//	AddSpecialItem("config_matchbook",REFRESH_REMOVE);
  reset();
}

object config_matchbook()
{
    object chest, money, necklace;
    chest = clone_object("obj/chest");
    chest->SetIds(({"matchbook"}));
    chest->SetAds(({"small"}));
    chest->SetShort("a small matchbook");
    chest->SetLong("A heavy wooden chest with iron bands.\n");
    chest->move(this_object(),M_SILENT);

    return chest;
}

set_the_light(stat) {
	if (stat == 1) {
		SetBright(MAX_SUNBRIGHT/2);
		tell_room (this_object(),"The lights go on.\n");
	}
	else {
		SetBright(-10);
		tell_room (this_object(),"The lights go out.\n");
	}
}
