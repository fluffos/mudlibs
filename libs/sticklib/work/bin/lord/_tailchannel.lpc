#include <lord.h>
#include <room_defs.h>
/*
	Lord command:	tailchannel
	Syntax:		tailchannel
	Conditions:
		User must be a lord.
	Effects:
		Displays the last few lord channel messages.
*/
int tailchannel_cmd()
{
    int lines;

    if ((LL < SQUIRE) && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if((lines=file_lines(LORD_CHANNEL))<0 ||
      environment(TP)->query(ROOM_ISOLATED))
    {
	notify_fail("Lord channel log currently empty.\n");
	return 0;
    }

    cat(LORD_CHANNEL,lines-10,11);

    return 1;
}

