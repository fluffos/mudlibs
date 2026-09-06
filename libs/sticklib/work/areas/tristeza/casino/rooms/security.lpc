/*********************************************************************
 security.c - security room 

 Things to do:
    - Hide the master key?
    - Code a way to view the profits of all the casino machines
      from here.

*********************************************************************/

#include <room.h>
#include <key_defs.h>
#include "../casino.h"

void
create_room()
{
    int i;

    set_short("Security and surveilance room.");
    set_long(
      "You are in a long, low room high in the casino building.  The northern\
 end of the room looks out over the huge gambling hall.  From here, the\
 gaming tables and machines are clearly visible, and no action of a\
 gambler below could go un-noticed.  A sign is painted on one wall.");

    set_items(([
	"sign" : "Security - keep a close watch on all hobbits\
 for theft and other offences."]));

    set_exits(([
	"down" : AREA_PATH+"rooms/entrance"
      ]));

    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

    /** lets try 4 bouncers for now.  **/
    /** They are tough, so this might **/
    /** prove to be too many.         **/
    for ( i=0; i<4; i++ )
	add_monster( ({ AREA_PATH+"npc/employee",  
	    ({ "set_name", "bouncer" }),
	    ({ "set_id",   "bouncer" }),
	    ({ "set_hp", 4000        }),
	    ({ "set_keep_hb", -2     }),
	    ({ "set_short","A casino bouncer" }), 
	    ({ "set_long","The bouncer is a large man dressed\
 in a fine tuxedo.  He has no visible weapon, but carries\
 himself with an air of poise and confidence.  You sense that\
 in a fight you would want him on your side." }) }),
	  "Bouncer arrives.", 1);


    /** The key to the door that provides **/
    /** access to the wheel of misfortune **/

    add_object( ({ KEY_FILE, 
	({ "set_type","casino master" }),
	({ "set_code","casino_storage_key" }),
	({ "set_long","It is a master key for the casino." })
      }) , 0, 1 );   

    replace_program( ROOM_FILE );
}

