#include <lord.h>
/*
	Lord command:	predict
	Syntax:		predict
	Conditions:
		User must be level 37 or above.
		User must be able to move.
		User must have required spell points.
	Effects:
		Gives the user a rough estimate on when
			the next reset will occour in 
			thier current location.
*/
int predict_cmd()
{
    int when;
    string tmp;

    if ((int)TP->query_level() < 37 && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail("You are unable to move.\n");
	return 0;
    }

    if(SP < CO_PREDICT)
    {
	notify_fail(SP_MES);
	return 0;
    }

    tell_room(environment(TP),TP->query_name()+" concentrates very hard.\n",({TP}));
    TM("You concentrate hard...");

    if (!environment(TP) || random(15) > LL)
    {
	notify_fail("...but nothing is revealed this time.\n");
	TP->add_sp(-CO_PREDICT/2);
	return 0;
    }

    when = query_next_reset(environment(TP)) - time();

    if(random(100 + LL) < 20)
	when = 1 + random(9500); /* Fumble */

    when = (when  / 60);
    when = (when  / 5) * 5;

    tmp = "...and feel that ";

    switch(when)
    {
    case 0..5:
	tmp += "you had better not blink or you will miss it.";
	break;
    case 6..10:
	tmp += "just hold on, it's not gonna be too long.";
	break;
    case 11..15:
	tmp += "you feel a quiver in your bones.. probably soon.";
	break;
    case 16..20:
	tmp += "hmm...  maybe you might wanna go get a drink.";
	break;
    case 21..40:
	tmp += "you need to lie down for a nap.";
	break;
    default:
	tmp += "it's time to get out the sleeping bag bed down for the night.";
	break;
    }

    TM(tmp);
    TP->add_sp(-CO_PREDICT);

    return 1;
}
