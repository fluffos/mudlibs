#include <lord.h>
/*
	Lord command:	signings
	Syntax:		signings
	Conditions:
		User must be level 30 or above
	Effects:
		Displays the latest signings of lords
			to higher levels
*/
int signings_cmd()
{
    if (((int)TP->query_level() < 30) && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!tail(SIGNINGS))
    {
	notify_fail("Cannot access the signings log currently.\n");
	return 0;
    }

    return 1;
}
