#include <lord.h>
/*
	Lord command:	invis
	Syntax:		invis
	Conditions:
		User must be level 35 or above.
		User must be able to move.
	Effects:
		Turns the user invisiable.
*/
int invis_cmd()
{
    if ((int)TP->query_level() < 35)
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(TP->query_invis()) {
	notify_fail("You are invisible already\n");
	return 0;
    }

    if(SP < CO_INVIS) {
	notify_fail(SP_MES);
	return 0;
    }

    TP->add_sp(-CO_INVIS);

    call_out("invis_off",
      (int) TP->query_level() / 2 + random(16), TP);
    // Was 6 + random(20))
    TP->invis();

    return 1;
}

void
invis_off(object ob)
{
    if (ob)
	if (ob->query_invis()) ob->vis();
}
