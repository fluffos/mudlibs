#include <lord.h>
#include <curse.h>

/*
	Lord command:	detect
	Syntax:		detect <armour/weapon>
	Conditions:
		Caster must be level 36 or greater
		Caster must be able to move
		Must be cast at an armour or a weapon
		Caster must have enough sp
	Effects:
		Tells you how cursed/blessed a
		  weapon/armour is
*/

int detect_cmd(string str)
{
    object target;
    int curse_level;
    int curse_type;
    string curse_dec;


    if (((int)TP->query_level() < 36) && !(CODER))
	return 0;

    if(!str)
    {
	notify_fail("Usage: detect <item>\n");
	return 0;
    }

    target=present(lower_case(str),TP);

    if (!target)
    {
	notify_fail("You don't have "+str+".\n");
	return 0;
    }

    str=capitalize(str);

    if (!(target->is_weapon()) && !(target->is_armour()))
    {
	notify_fail(str+" is not an item that can be cursed.\n");
	return 0;
    }

    if (SP < CO_DETECT)
    {
	notify_fail(SP_MES);
	return 0;
    }

    if(target->is_weapon())
    {
	curse_level = (int)target->query_curse_level();
	curse_type = curse_level ? (int)target->query_curse_type():CT_NONE;

	if(curse_level < 0)
	{
	    curse_level = 0 - curse_level;
	}

	if(curse_type == CT_NONE)
	{
	    TM("You detect no curse in the "+target->query_name()+".");
	    return 1;
	}
	switch(curse_level)
	{
	case 0:		curse_dec = " is not ";
	    break;
	case 1..2:	curse_dec = " is just barely ";
	    break;
	case 3:		curse_dec = " is mildly ";
	    break;
	case 4..5:	curse_dec = " is rather strongly ";
	    break;
	case 6..8:	curse_dec = " is strongly ";
	    break;
	default:	curse_dec = " is very strongly ";
	    break;
	}

	if(curse_type == CT_BLESSED)
	    curse_dec = curse_dec + "blessed.";
	else
	    curse_dec = curse_dec + "cursed.";

    }
    else
    {
	curse_level = (int)target->query_curse_level();
	curse_type = curse_level ? (int)target->query_curse_type():CT_NONE;

	if(curse_level < 0)
	{
	    curse_level = 0 - curse_level;
	}

	if(curse_type == CT_NONE)
	{
	    TM("You detect no curse in the "+target->query_name()+".");
	    return 1;
	}

	switch(curse_level)
	{
	case 0:	 curse_dec = " is not ";
	    break;
	case 1:  curse_dec = " is just barely ";
	    break;
	case 2:	 curse_dec = " is mildly ";
	    break;
	case 3:  curse_dec = " is rather strongly ";
	    break;
	case 4:  curse_dec = " is strongly ";
	    break;
	default: curse_dec = " is very strongly ";
	    break;

	}

	if(curse_type == CT_BLESSED)
	    curse_dec = curse_dec + "blessed.";
	else
	    curse_dec = curse_dec + "cursed.";

    }

    TM("Your "+str+curse_dec);
    TP->add_sp(-CO_DETECT);
    return 1;
}
