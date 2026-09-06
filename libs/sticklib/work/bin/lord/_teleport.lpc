#include "/sys/interactive_info.h"

#include <lord.h>
#include <conditions.h>
#include <room_defs.h>
/*
	Lord command:	teleport
	Syntax:		teleport to player
	Conditions:
		User must be level 36 or above.
		User must be able to move.
		Both users must be in locations that allow teleport.
	Effects:
		Moves the calling user to the location of
			the specified target.
*/
int teleport_cmd(string str)
{
    string tmp;
    object target,here,there;

    if((int)TP->query_level() < 36)
	return 0;

    if(!str)
    {
	notify_fail("Usage: teleport to <player>.\n");
	return 0;
    }

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!sscanf(str,"to %s",tmp))
    {
	notify_fail("Usage: teleport to <player>.\n");
	return 0;
    }

    tmp=lower_case(tmp);
    target=find_player(tmp);
    tmp=capitalize(str);

    if(!(target && interactive(target) && (there=environment(target))))
    {
	notify_fail("Cannot find player " + str + "\n");
	return 0;
    }

    if(target->query_coder_level() ||
      target->query_testplayer() && !(CODER))
    {
	notify_fail("Yeah, sure we are going to let you teleport to a coder.\n");
	return 0;
    }

    if((target->query_lord() > LL) && !(CODER))
    {
	notify_fail("You cannot teleport to higher players.\n");
	return 0;
    }

    here=environment(TP);

    if(there->query(PREVENT_TELEPORT))
    {
	notify_fail(tmp+" is currently in a place that doesn't allow teleporting.\n");
	return 0;
    }

    if(target->query_ghost())
    {
	notify_fail(tmp+" is currently a ghost you can't quite make out where they are at.\n");
	return 0;
    }

    if(!interactive_info(target, II_IP_NUMBER))
    {
	notify_fail(tmp+" is currently link-dead.\n");
	return 0;
    }

    if(here->query(PREVENT_TELEPORT))
    {
	notify_fail("You are in a place that doesn't allow teleporting.\n");
	return 0;
    }

    if(sscanf(object_name(there),"room/death/%s",tmp))
    {
	notify_fail("There is only one way to get to where "+target->query_pronoun()+" is.\n");
	return 0;
    }

    if(there==here)
    {
	notify_fail("But you are where that person is already.\n");
	return 0;
    }

    if (TP->is_fighting())
    {
	notify_fail("Your concentration fails.\n");
	return 0;
    }   

    if (SP < CO_TELEPORT)
    {
	notify_fail(SP_MES);
	return 0;
    }

    TP->add_sp(-CO_TELEPORT/2);

    /* Notify people of events */
    TM("You reach out and cut into the air with the tip of your nail.");
    tell_room(environment(TP),TP->query_name()+" cuts a hole in the air.\n",({TP}));

    /* Chance to fail: 80% (31), 60% (32), 40% (33), 20% (34), 0% (35+) */
    if (random(5) > LL - 12 ||
      TP->query_random_luck() + random(10)
      <=target->query_random_luck() + random(10))
    {
	notify_fail("Oh no! You fail in the spell!\n");
	return 0;
    }

    tell_room(there,"With a ripping sound a slit appears in space in front of you.\n");
    TM("You reach into the slit and rip it open.");
    TM("Your stomach wrenches as your leap into it.");

    TP->add_sp(-CO_TELEPORT/2);
    TP->move_player("X#"+object_name(there));
    TP->set_condition(C_STUNNED, 3 + random(4));

    return 1;
}
