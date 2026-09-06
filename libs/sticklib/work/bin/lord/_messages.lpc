#include <lord.h>
/*
	Lord command:	messages
	Syntax:		messages <optional number>
	Conditions:
		User must be level 30 or above.
		User must be able to move.
	Effects:
		Without an argument it displays the possiable messages.
		With an argument it sets the users vis/invis to
			the specified #.
*/
int messages_cmd(string str)
{
    if ((int)TP->query_level() < 30)
	return 0 ;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(str)
	TP->mmsgs(str);
    else
	TP->show_msg();

    return 1;
}
