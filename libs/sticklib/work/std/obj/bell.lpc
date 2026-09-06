/* This object is a historical leftover... Treat is as such. */

#include <treasure.h>
#include <generic_rooms.h>

#include "/areas/tristeza/DEFS.h"

int hunch_back; /* Is hunchback back? */

void
create_treasure()
{
    hunch_back = 2;
    set_name("bronze bell");
    set_id(({ "bell", "enormous bronze bell" }));
    set_short("Enormous bronze bell");
    set_long("The finest craftmanship you have seen in enormous bronze bells\
 before. A rope is tied to the bell.");
    set_weight(10000);
    call_out("start",10);
}

void
reset_treasure()
{
    hunch_back=2;
}

void
start()
{
    int hour;

    hour = nature()->query_hour();
    hour++;
    if(hour==24)
	hour=0;
    nature()->add_timerequest(hour,0,"start_bong");
}

void
init_treasure()
{
    add_action("pull","pull");
    add_action("untie","untie");
}

int
untie(string str)
{
    if (!str || !id(str, 0, this_player()))
	return 0;
    this_player()->tell_me("You cannot do that!");
    return 1;
}

status
pull(string str)
{
    if (!str || !id(str, 0, this_player()))
	return 0;
    if (present("hunchback",environment())) {
	this_player()->tell_me("Hunchback steps in front of you and gnarls.");
	return 1;
    }
    this_player()->tell_me("Ok.");
    call_out("pull_rope",1);
    return 1;
}

status
pull_rope(int who)
{
    string mess,*rooms;
    int i;

    if (!environment())
	return 0;

    if (who && environment() && !present("hunchback",environment())) {
	if(hunch_back==1) {
	    hunch_back=0;
	    return 1;
	}
	if(hunch_back==2)
	    hunch_back=1;
    }

    /* Rooms in which the BONG is heard: */
    /* The better way probably would be to scan through all players
     * and see if they're in the main town area.
     */
    rooms = ({
      GENERIC_ROOM_CHURCH,
      CITY_DIR+"S6_6",
      CITY_DIR+"S7_6",
      CITY_DIR+"S8_6",
      CITY_DIR+"S6_7",
      CITY_DIR+"S7_7",
      CITY_DIR+"S8_7",
      CITY_DIR+"S6_8",
      CITY_DIR+"S7_8",
      CITY_DIR+"S8_8" 
    });

    mess="You hear a 'GONNNGGGG!' from the tower beside the temple yard.\n"; 
    if (who)
	environment()->tell_me("Hunchback pulls the rope.\n\
GOOOOOOOONNNNNNNNNNNNNNGGGGGGGGGGGGGGGGGGGG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    while(i<sizeof(rooms)) {
	if(rooms[i])
	    rooms[i] -> tell_here(mess);
	i++;
    }
    return 1;
}

void
start_bong()
{
    call_out("pull_rope",1,1);
    call_out("start",2);
}
