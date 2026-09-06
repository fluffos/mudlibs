/* Chamber of the Eternity */
#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Chamber of the Eternity");
    set_long("You almost lose consciousness when you realize where you have\
 just arrived. For this is indeed the Chamber of the Eternity, in the chellar\
 of Death himself. There is a huge black door on the east wall.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([ "west" : AREA_TRISTEZA+"death/chellar1" ]));
    set_items(([
	"door" : "You feel ultimate terror, for there is a writing in black letters on\
 the door: 'ETERNITY'. There's also a small closed hatch on the door.",
	"hatch" : "You do not dare to look closely, but it is closed."
      ]));
    set_commands(([ "open" : "open_cmd" ]));
}

int
open_cmd(string str)
{
    if ( !str ) return 0;
    if ( strstr(str,"door")!=-1) 
    {
	this_player()->tell_me(
	  "What a foolish thing to try! Anyway, there's no handle.");
	return 1;
    }

    if ( strstr(str,"hatch")==-1) return 0;

    /* The most stupid thing one can possibly do is to open the hatch
       of eternity in the chellars of death. Such a feat of heroic
       idiocy should actually be rewarded by permanent death, removing
       of players '.o' file. We are not SO cruel this time. And everyone
       will, of course, try to open that hatch...
     */
    this_player()->tell_me("An irresistable force sucks you through the\
 hatch. The hatch is far too small for a man-sized thing to pass. You are\
 squashed into thick paste - very dead.");

    /* Not even a corpse remains - nasty... */
    move_object(this_player(), AREA_TRISTEZA+"death/eternity");
    this_player()->add_hp(-50000, 1);

    /* Log 'em suckers */
    log_file("eternity.fools",(string)this_player()->query_real_name()
      +" perished at "+AREA_TRISTEZA+"death/chellar2 at "
      + ctime(time()) + "\n");

    return 1;
}

