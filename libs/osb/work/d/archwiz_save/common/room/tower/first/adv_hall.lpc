inherit "/std/room";

#include "path.h"
#include <moving.h>
#include <rooms.h>
#include <properties.h>
#include <secure/wizlevels.h>

int go_east() {
  if (!this_player()) return 0;
  if(this_player()->QueryIsNPC()) return 1;
  if(!IS_IMMORTAL(this_player())) {
    write(
"Your hear a soft voice in your mind: "
"Currently you are not of high enough level to enter.\n");
    }	
    else {
      write("You step through the magic field.\n");
      this_player()->move(TOWER("first/west_corr"),M_GO,"east");
      }
  return(1);
}

void create() {
	::create();
	SetIntShort("Hall of Adventurers");
	SetIntLong(
"You are in the Hall of Adventurers in the Tower of Administration. "
"To the west a big gate leads out to the street. An illuminating "
"field blocks the way to the east. You can see a large voting table "
"through the doorway to the south.\n");
	AddExit("west",	CITY("boul2"));
	AddExit("south", "./voting_room");
	AddExit("east",#'go_east);
	AddItem("/std/board",REFRESH_HOME,
	  ([P_SHORT:"The Central Player Board",
	    P_LONG:"This is the Central Player Board of Nightfall. "
"You may discuss everything you need to know on it.\n",
	    "Groups":({"players", "players.\\.*"})]));
	AddDetail("field", 
"It's an illuminating field that blocks the way further east. "
"The field sparkles in many beautiful colours.\n");
	AddDetail("gate",
"It's a huge doorway leading out.\n");
	AddItem(MONSTER("debugtool"),REFRESH_DESTRUCT);
	SetExplorable(1);
}
