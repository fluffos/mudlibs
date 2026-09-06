/*********************************************************************
 entrance.c - Casino lobby 

 Things to do:
    - Make Bubba block players trying to leave the casino
      if they are aggro to dealers, bouncers, etc.

    - Code a "top list" of jackpot winners, etc.

*********************************************************************/

#include <room.h>
#include "../casino.h"


void
create_room()
{
    set_short("Entrance lobby.");

    set_long(
      "This is the entrance lobby to the Joker\'s casino. \
 Rich carpets and fine tapestries testify to the profitability of\
 harnessing the gullability of the masses.  To the north, the lobby\
 narrows to a single checkpoint, where casino security personnel can\
 filter out the unwanted elements from legidimate clientele.\
 A sign is prominently displayed near the casino entrance \
 \n \
  NOTICE: This casino has been closed by the administration due to \
profuse cheating. "
    );


    set_exits(([
#ifdef OPEN
	"north" : AREA_PATH+"rooms/casino_s",
	"up"    : AREA_PATH+"rooms/security",
#endif
	"south" :"/areas/tristeza/virtual/S12_4"
      ]));

    /** Lets warn the players about what    **/
    /** might happen to them if they steal  **/
    /** or attack employees - Its virtually **/
    /** a certain MK if the bouncers come.  **/ 

    set_items(([ "sign" : 
	"Welcome to the Joker's Casino!  Please note the following casino\
 house rules:\n\n\
    - It is not our policy to issue refunds.  However, please\
 notify us if a machine is broken so it can be fixed.\n\n\
    - The casino security does not tolerate violence against\
 casino employees.\n\n\
    - Security also tries to watch for patrons who steal, and\
 offenders will be prosecuted.\n\n\
    - Stealing or attempting to steal from other casino patrons\n\n\
 will not be tolerated.\n\n\
These rules are here for your protection, and for our continued\
 success.  We hope your experience at the Joker's Casino will\
 be pleasurable.\n\n\
 Thank you,\n\
 the Management" ]));


    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);

#ifdef OPEN
    add_monster( ({ AREA_PATH+"npc/employee",
	({ "set_name", "bubba" }),
	({ "set_id",   ({ "bubba", "doorman" }) }),
	({ "set_short","Bubba the doorman" }),
	({ "set_long",
	  "Bubba is an extremely fat man who's job is to control\
 access in and out of the casino.  His immense girth makes\
 him especially suited to this task, as he might even be\
 capable of blocking the entire entrance with his enormous\
 tuxedo-clad bulk." }),
	({ "add_block","up","all",0,0,
	  ":%<me.name>% prevents you from going up.",
	  ":%<me.name>% prevents %<him.name>% from going up.",
	  0,0 }), 
	({ "load_chat", 3, ({
	    "Bubba says: Huh-huh-huh-hi! I-I-I-I'm Buh-Buh-Buh-Buh-Bubba!",
	    "Bubba says: Buh-better nuh-nuh-not stuh-steal i-in the cuh-cuh-casino!" }) }),

	({ "add_object", AREA_PATH+"objects/abacus", "abacus",
	  0, 5, "Bubba takes the abacus." })
      }),
      "Bubba arrives.", 1);


    set_commands( ([ "north":"north_cmd" ]) );

    /** load the security room so that   **/
    /** bouncers will exist after reboot **/

    call_other( AREA_PATH+"rooms/security", "" );  /** load the security room **/
#endif

}




/****************************************************************************
  Lets prevent players younger than 10 days from entering the casino.
  This might help stop 2nd chars from clogging up the machines and causing lag.
*****************************************************************************/

status north_cmd()
{
    if (( (int)(this_player()->query_age()) < 92400 )  /** 92.4K seconds = 10 days **/
      &&((int)(this_player()->query_level())< 30 ))  /** lets add lvl factor since **/
	/** sometimes age bugs.       **/
    {
	this_player()->tell_me("Bubba prevents you from entering the casino!");
	tell_here( "Bubba prevents "+this_player()->query_name()
	  +" from entering the casino.", this_player());

	tell_here("Bubba says: Yuh-You are tuh-tuh-too yuh-young to puh-play\
 in the cuh-cuh-cuh-casino.");

	return 1;
    }
    return 0;
}

