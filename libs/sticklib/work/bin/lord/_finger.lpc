#include <lord.h>

/* 
	Lord command:	finger
	Syntax:		finger <player>
	Conditions:
		User must be level 42 or above
		User must have required SP
	Effects:
		Displays the output of the finger
		   command to the calling user
*/

int finger_cmd(string str)
{
    if(((int)TP->query_level() < 42) && !(CODER))
	return 0;

    if(!str) {
	notify_fail("Usage: finger <player>\n");
	return 0;
    }

    if(!(CAN_MOVE(TP))) {
	notify_fail(MOVE);
	return 0;
    }

    if(SP < CO_FINGER) {
	notify_fail(SP_MES);
	return 0;
    }

    if(CODER) {
	if(!FINGER->show_coder(str)) {
	    notify_fail("No such player.\n");
	    return 0;
	} else return 1;
    }

    if(!FINGER->show_mortal(str,TP)) {
	notify_fail("No such player.\n");
	return 0;
    }

    TP->add_sp(-CO_FINGER);
    return 1;
}
