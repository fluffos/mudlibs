inherit "/std/room";
#include <rooms.h>
#include <moving.h>
#include "path.h"

QueryIntLong() {
	string str;
	int rdelta;
	str = 
"You are in a huge cavern. The sound of many footsteps is heard, as you enter "
"the cave. As you stand still, the footsteps stop also. There is a vertical "
"slit to the southeast, and you can enter another room to the west.\n";
	rdelta = DAMROOM->reservoir_delta();
	if (rdelta == 0)
		str += "The room is filled with the sound of rushing water, so loud you can't "
			"understand your own words!\n";
	else if (rdelta < 0)
		str += "There is a sound so horribly loud, you will probably become deaf!\n";
	return str;
}

int try_se() {
  if (!this_player()) return 0;
  if (this_player()->QueryDex() < 15) 
      write("There is nothing to hold on in the slit.\n");
    else
      this_player()->move(SLITROOM,M_GO,"into the slit#");
  return 1;
}


create() {
  ::create();
  SetIntShort("Loud Room");
  SetIndoors(1);
  AddDetail(({"slit","narrow slit","narrow, vertical slit","vertical slit"}),
    "A narrow, vertical slit. There is hardly anything you could use to hold on.\n");
  AddDetail(({"cave","loud room","room","huge cavern","cavern"}),#'IntLong);
  SetIntNoise("It's not very quiet in here.\n");
  AddExit("west","./round_room");
  AddExit("southeast",#'try_se);
}

init()
{
	::init();
	add_action("echoall","",1);
}


echoall(str)
{
	int rdelta;
	string totalstr;
	rdelta = DAMROOM->reservoir_delta();
	if (rdelta > 0) return 0;
	if (query_verb() == "west" || query_verb() == "southeast" || query_verb() == "look" || query_verb() == "l")
		return 0;
	totalstr = query_verb();
	if (str) 
		totalstr += " "+str;
	write("The walls echo: "+totalstr+" "+explode(totalstr," ")[<1]+" "+
			explode(totalstr," ")[<1]+" .......\n");
	return 1;
}
