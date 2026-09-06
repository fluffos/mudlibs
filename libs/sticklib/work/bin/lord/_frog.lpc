#include <lord.h>
#include <room_defs.h>

/*
	Lord command:	frog
	Syntax:		frog <player>
	Conditions:
		User must be level 29 or above.
		User must be able to move.
		User have to be in a non-pk area.
		User must have required number of SP.
		Target must be a player.
		Target must be below our level.
	Effects:
		Casts the frog curse on a player.
*/

int frog_cmd(string str)
{
    object target;

    if (((int)TP->query_level() < 29) && !(CODER))
	return 0;

    if(!str)
    {
	notify_fail("Usage: frog <player>.\n");
	return 0;
    }

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!(target=present(lower_case(str),environment(TP))))
    {
	notify_fail("You search about but can't seem to find a "+str+" here.\n");
	return 0;
    }

    if(target->query_npc())
    {
	notify_fail("Sorry, but you can don't that to a monster\n");
	return 0;
    }

    if(!environment(target)->query(NO_PK))
    {
	notify_fail("That only works in non-playerkilling areas!\n");
	return 0;
    }

    if(target->query_frog())
    {
	notify_fail("But, "+str+" is a frog already.\n");
	return 0;
    }

    if(target->query_lord() > LL)
    {
	notify_fail("You can frog only lesser players.\n");
	return 0;
    }

    if(target->query_coder_level())
    {
	notify_fail("You can NOT frog coders.\n");
	return 0;
    }

    if(SP < CO_FROG)
    {
	notify_fail(SP_MES);
	return 0;
    }

    str = capitalize(str);

    /* Notify the involved parties */
    tell_room(environment(TP),TP->query_name()+" casts a frog curse on "+
      target->query_name()+".\n",({TP,target}));
    TM("Ok.  You cast the frog curse on"+str+".");
    tell_object(target,TP->query_name()+" casts a frog curse on you!\n");

    /* Actually do the command */
    target->frog_curse(1);
    TP->add_sp(-CO_FROG);

    /* Record keeping as usual */
    log_file(FROG,str + " frogged by " + (string)TP->query_real_name()+ " at " + ctime(time()) + "\n");

    return 1;
}
