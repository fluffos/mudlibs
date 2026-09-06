/* Changed this to PK-room. Quite funny if raider can beat
the crap outta saint and priests can't attack him. */

#include "priest_room.h"
#include <gender.h>
#include "/areas/tristeza/DEFS.h"

int gates_shut;

void shut_gates(int i) {
    gates_shut = i;
    if(gates_shut) tell_here("The north gates close, leaving you outside.");
    else tell_here("The north gates open, allowing you passage.");
}

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(IN_CITY);
    //    set(NO_PK); 
    set_short("The entrance to the cathedral");
    set_long(

      "This is the entrance room to the mighty cathedral of " GOD_NAME ". The \
floor is made of priceless mosaic tile, taken from the destroyed halls of \
Old Freel. On the walls hand tapestries, depicting the early history of the \
order.");

    add_monster(PRIEST_MON_DIR "saint",
      "Guardian saint appears from nowhere.",1);

    set_items(([
	({"tile", "mosaic"}) : "Priceless tile take (some say looted) from the \
halls of Old Freel.",
	({"tapestry", "tapestries"}): "Depicting the early history of the \
Priests of Boccob the tapestries are mostly faded with age, but you can see \
hints of three different sects, and a great war between them.",
      ]));

    set_exits(([
	"north" : PRIEST_ROOM_DIR "hall",
	"south" : CITY_DIR "S11_7",
      ]));
    add_command("north", "north_cmd");
    add_command("south", "south_cmd");

    gates_shut = 0;
}


int north_cmd() {
    object me;
    string my_guild;

    me = this_player();
    if(gates_shut == 1) {
	me->tell_me("The gates are shut, you cannot go that way. ");
	return 1;
    }

    if(present("priest_saint", this_object())
      && (!this_player()->query_coder_level()))
    {
	my_guild = (string) me->query_guild();
	if((!my_guild) || (my_guild == GN_PRIEST))
	    return 0;
	if(GUEST_D->query_guest(me->query_real_name()))
	    return 0;

	me->tell_me("Guardian Saint tells you: Heathens like you are not \
allowed to enter this sacred cathedral.");
	tell_here(":Guardian Saint says something to %<me.capname>%.",
	  0,0,me,me,0,0);
	return 1;
    }

    return 0;
}


init_room() {
    object me, mon;

    mon = present("priest_saint", this_object());
    if(!mon) return;

    me = this_player();
    if(me->query_guild() != GN_PRIEST) return;
    switch(query_verb()) {
    case "north":
	me->tell_me("Guardian Saint tells you: Welcome, dear " +
	  ((me->query_gender() == G_MALE) ? "brother." : "sister."));
	break;
    }
}


south_cmd() {
    object mon;

    mon = present("priest_saint", this_object());
    if(!mon) return;

    if(this_player()->query_guild() != GN_PRIEST) return 0;
    this_player()->tell_me("Guardian Saint tells you: Farewell, \
fellow priest!");
    return 0;
}
