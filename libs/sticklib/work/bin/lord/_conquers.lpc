#include <lord.h>

/* 
	Lord command:	conquers
	Syntax:		conquers
	Conditions:
		User must be level 28 or higher
	Effects:
		Displays the latest conquers
*/
int conquers_cmd()
{
    if (((int)TP->query_level() < 28) && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!tail(CONQUERS))
    {
	notify_fail("No one has conquered anyone recently.\n");
	return 0;
    }

    return 1;
}
