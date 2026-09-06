#include <lord.h>
/*
	Lord command:	sharpen
	Syntax:		sharpen <weapon>
	Conditions:
		User must be level 35 or higher
		User must not be a dwarf
		User must be able to move
		User must have enough spell points
		The weapon must not be sharp already
		The weapon must not be a 'blunt' weapon
	Effects:
		Returns the weapon to a 'sharp' condition
*/

int sharpen_cmd(string str)
{
    int cost;
    string tmp;
    object target;

    if(  ( ((int)TP->query_level() < 35) && !(CODER) ) ||
      ("dwarf" == (string)TP->query_race())  )
	return 0;

    if(!str)
    {
	notify_fail("Usage: sharpen <weapon>\n");
	return 0;
    }

    tmp=lower_case(str);
    target=present(tmp,TP);
    tmp=capitalize(str);

    if(!target)
    {
	notify_fail("You don't have a "+str+".\n");
	return 0;
    }

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    if(!target->is_weapon())
    {
	notify_fail(tmp+" is not a weapon.\n");
	return 0;
    }

    if(target->query_wielded())
    {
	notify_fail("You must remove it first.\n");
	return 0;
    }

    if(target->query_blunt())
    {
	notify_fail("Cannot sharpen "+str+".\n");
	return 0;
    }

    if(!target->query_bluntness())
    {
	notify_fail("It is sharp already.\n");
	return 0;
    }

    cost = (int)target->query_orig_value() - (int)target->query_value();

    if (SP < cost)
    {
	notify_fail(SP_MES);
	return 0;
    }

    if(random(101) < (int)target->query_bluntness())
    {
	notify_fail("Oh no! Your "+str+" broke when sharpened!\n");
	destruct(target);
	TP->add_sp(-(cost/2));
	return 0;
    }

    target->set_bluntness(0);

    TP->add_sp(-cost);

    TM("Ok. "+capitalize(str)+" is sharpened.");
    tell_room(environment(TP),TP->query_name()+" sharpened "+str+".\n",({TP}));

    return 1;

}
