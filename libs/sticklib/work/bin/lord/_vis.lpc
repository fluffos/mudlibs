#include <lord.h>
/*
	Lord command:	vis
	Syntax:		vis
	Conditions:
		User must be level 30 or above.
		User must be able to move.
	Effects:
		Turns the user visiable.
*/
int vis_cmd()
{
    if ((int)TP->query_level() < 30)
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    TP->vis();

    return 1;

}
