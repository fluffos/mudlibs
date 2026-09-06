#include <lord.h>

/*
	Lord command:	shop
	Syntax:		shop
	Conditions:
		User must be level 32 or above.
		User must be in the church(entrance)
		   to be able to teleport to the shop.
	Effects:
		Moves user from the church to the shop
*/

int shop_cmd()
{
    if (((int)TP->query_level() < 32) && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(object_name(environment(TP))!="room/church")
    {
	notify_fail("You must be in the church to do this.\n");
	return 0;
    }

    /* Do the actual command */
    TP->move_player("Vteleports into the Travelling Shop#players/rincewind/shop");

    return 1;
}
