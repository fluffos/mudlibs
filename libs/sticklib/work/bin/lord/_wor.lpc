#include <lord.h>
#include <room_defs.h>
/*
	Lord command:	wor
	Syntax:		wor
	Conditions:
		User must be level 34 or above.
		User must be able to move.
		User must be in a room that allows teleport.
		User must have at least the minimum spell point cost.
	Effects:
		Moves the user to the church

*/

int wor_cmd()
{
    int cost;

    if (((int)TP->query_level() < 34) && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail("You are unable to move.\n");
	return 0;
    }

    if(environment(TP)->query(PREVENT_TELEPORT) ||
      environment(TP)->query(ROOM_ISOLATED))
    {
	notify_fail("Word of Recall does not work here.\n");
	return 0;
    }


    /* Calculate the cost */
    /* Was like this
	    if(SP > CO_WOR)
		    cost = (int)TP->query_sp();
	    else 
		    cost = CO_WOR;
    */
    //Now it works as it should have //Frobozz
    if(SP >= CO_WOR)
	cost = SP;
    else {
	TM("You don't have enough spell points.");
	return 1;
    }


    /* Tell everyone about the move */
    tell_room(environment(TP),TP->query_name()+" mumbles a word and is surrounded in darkness.\n"+
      "With a bright flash light returns to the room but"+TP->query_name()+"is missing.\n",({TP}));
    TM("You mumble an incantation.\n\
Darkness flows around you.\n\
Suddenly light returns and you are somewhere else.");

    /* Do the move */
    TP -> move_player("X", "/room/church");
    TP->add_sp(-cost);

    return 1;
}
