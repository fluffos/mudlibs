#include <lord.h>
/*
	Lord command:	first aid
	Syntax:		first aid <player>
	Conditions:
		User must be level 35
		User must be able to move
		User must have required spell points
		Target must be in the same room
		Target must have less than 0 hp
	Effects:
		Heals target AID_HEAL hps.
*/
int first_cmd(string str)
{
    string tmp;
    string tname, mname;
    object target;

    if (((int)TP->query_level() < 35) && !(CODER))
	return 0;

    if(!str)
    {
	notify_fail("Usage: first aid <player>\n");
	return 0;
    }

    if(!sscanf(str,"aid %s",tmp))
    {
	notify_fail("Usage: first aid <player>\n");
	return 0;
    }

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    target=present(tmp,environment(TP));
    if(!target)
    {
	notify_fail("No such player here.\n");
	return 0;
    }
    tname = (string)target->query_name();
    mname = (string)TP->query_name();

    if(target->query_npc())
    {
	notify_fail("You can only give first aid to players.\n");
	return 0;
    }

    if(target->query_ghost() || target->query_dead())
    {
	notify_fail("It's to late that person is dead already.\n");
	return 0;
    }

    if(target->query_hp() > 0)
    {
	notify_fail(capitalize(str)+" does not need healing.\n");
	return 0;
    }

    if(SP < CO_AID)
    {
	notify_fail(SP_MES);
	return 0;
    }

    TM("You give first aid to " +tname+ ".");

    tell_room(environment(TP),mname+" gives first aid to "+
      tname+".\n",({ TP,target }));

    tell_object(target,mname+" gives you first aid.\n");

    TP->add_sp(-CO_AID);
    target->heal_self(AID_HEAL);

    TM(tname+" seems to feel better.");

    log_file(AID_FILE,capitalize((string)TP->query_real_name())+"gave first aid to"+
      capitalize((string)target->query_real_name()+"\n"));

    return 1;
}
