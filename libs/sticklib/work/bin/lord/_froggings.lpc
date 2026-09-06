#include <lord.h>
/*
	Lord command:	froggings
	Syntax:		froggings
	Conditions:
		User must be level 31
	Effects:
		Displays the latest people to be frogged/unfrogged
*/
int froggings_cmd()
{
    if ((int)TP->query_level() < 31 && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!tail(FROGGINGS))
    {
	notify_fail("Currently no froggings/unfroggings listed.\n");
	return 0;
    }

    return 1;
}
