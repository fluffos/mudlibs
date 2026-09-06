#include <lord.h>

/*
	Lord command:	uunfrog
	Syntax:		unfrog <player>
	Conditions:
		User must be level 28 or above.
		User must be able to move.
		User must have required number of SP
		Target must be a player.
	Effects:
		Removes the frog curse from a player.
*/

int unfrog_cmd(string str)
{
    object target;

    if (((int)TP->query_level() < 28) && !(CODER))
	return 0;

    if(!str)
    {
	notify_fail("Usage: unfrog <player>.\n");
	return 0;
    }

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!(target=present(lower_case(str),environment(TP))))
    {
	notify_fail("You cannot seem to find a "+str+" here.\n");
	return 0;
    }

    if(target->query_npc())
    {
	notify_fail("You try hard but don't seem to be able to affect that monster.\n");
	return 0;
    }

    if(!target->query_frog())
    {
	notify_fail("But "+str+" is not a frog.\n");
	return 1;
    }

    if(SP < CO_UNFROG)
    {
	notify_fail(SP_MES);
	return 0;
    }

    str = capitalize(str);

    /* Notify the involved parties */
    tell_room(environment(TP),TP->query_name()+" removes the frog curse from "+
      target->query_name()+".\n",({TP,target}));
    TM("Ok.  You remove the frog curse from "+str+".");
    tell_object(target,TP->query_name()+" removes the frog curse from you!\n");

    /* Actually do the command */
    target->frog_curse(0);
    TP->add_sp(-CO_UNFROG);

    /* Log the unfrogging */
    log_file(FROG,str + " unfrogged by " + (string)TP->query_real_name() +
      " at " + ctime(time()) + "\n");

    return 1;
}
