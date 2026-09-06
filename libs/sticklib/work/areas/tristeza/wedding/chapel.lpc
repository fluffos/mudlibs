
#include <room.h>
#include "weddings.h"
inherit "basic/misc/emote";   
#define TP this_player()
int y;


void
create_room(){

    set(NO_PK);
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_INDOORS);
    set_short("The wedding chapel");
    set_long("You are standing in a picturesque wedding chapel. The front of the \
chapel has an archway entrance, opening up to a red carpeted aisle, \
surrounded on both sides by several pews. At the back of the chapel, \
the alter is hand carved and covered with numerous flower \
arrangements and sparkling white candles. The evening sun \
streaming in through the stained glass windows, on either side \
of the chapel, casts brief colored sparkles on the pews. The smell of \
roses and jasmine is carried through the room on a soft breeze.");
    set_exits((["town":"/room/church"]));
    set_commands(([
	"helpchapel":"helpchapel",
	"emote":"emote_cmd",
	"toss":"toss_cmd"
      ]));
}


helpchapel(){
    TP->tell_me("This chapel was coded for mud weddings. I have \
just started coding it. So there are limited commands available.\n\
toss rice = tosses rice at the couple after the ceremony is over\n\
Best Wishes,\n\
Minx");

    return 1;
}

toss_cmd(string what){
    int z;	
    if (what == "set"){
	y++;
	return 1;
    }

    if (what == "rice"){
	if (!y){
	    TP->tell_me("You must wait until the ceremony is over.");
	    return 1;
	}

	if (y == 1) {
	    z = random(4);
	    if (z == 0)tell_here((string)TP->query_name()+" \
tosses rice into the air.");
	    if (z == 1) tell_here((string)TP->query_name()+" \
tosses rice at the bride and the groom.");
	    if (z == 2) tell_here((string)TP->query_name()+" \
tosses rice at the happy couple.");
	    if (z == 3) tell_here((string)TP->query_name()+" \
tosses rice missing the bride and groom completely.");
	    if (z == 4) tell_here((string)TP->query_name()+" \
tosses rice.");
	    return 1;
	}

	TP->tell_me("Toss what?");
	return 1;
    }
} 
