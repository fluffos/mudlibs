/* Lobby of the Brotherhood vs. Lords */
#include <room.h>
#include <areas.h>
#define PASSWORD "keblghmn"
#define TP this_player()

void
create_room()
{
    int i;
    set_short("Lobby");
    set_long(
      "This is a lobby into some private club. An archway to the east\
 leads into the building, and the exit is to the west.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set_exits(([
	"east" : AREA_TRISTEZA+"bvl/hall",
	"west" : AREA_TRISTEZA+"virtual/S10_2"
      ]));
    set_commands(([
	"east" : "east_cmd",
	"keblghmn" : "east_cmd",
	"say"	: "say_cmd"
      ]));
    for ( i=0;i<4;i++)
	add_monster(AREA_TRISTEZA+"bvl/guard","Guard arrives.",1);
}

status
say_cmd(string str)
{
    if ( !str || strstr(str,PASSWORD)==-1) return 0;
    TP->tell_me("Ok.");
    tell_here(TP->query_name()
      +" mutters something.",TP);
    command(PASSWORD,TP);
    return 1;
} 

status
east_cmd() 
{
    if(query_verb() == PASSWORD)
    {
	if(TP && TP->query_lord() &&
	  !TP->query_coder_level())
	    return 0;
	if(present("bvl_guard",this_object()))
	{
	    tell_here( "The guards let "+TP->query_name()
	      +" pass. \"Death to Lords\", one says and salutes "
	      +TP->query_name()+".", TP);
	    TP->tell_me("The guards let you pass.\
 \"Death to Lords\", one says and salutes you.");
	}
	TP->move_player("east#"+AREA_TRISTEZA+"bvl/hall");
	return 1;
    }
    else
    if(present("bvl_guard",this_object()))
    {
	TP->tell_me("One of the guards blocks your way and\
 says: What's the password?");
	tell_here(
	  "One of the guards blocks "+TP->query_name()
	  +"'s way and says: What's the password?",TP);
	/* Level 1..18 people may be told it */
	if(TP->query_level()<random(20))
	    TP->tell_me(
	      "Another guard winks and whispers: It's "+PASSWORD+". Death to Lords!");
	tell_here("Another guard winks and whispers something to "
	  +TP->query_name()+".", TP);
	return 1;
    }
}
