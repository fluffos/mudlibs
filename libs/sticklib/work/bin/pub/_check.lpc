#include <lord.h>
#include <stats.h>
#include <race.h>

//
// Pub command:	check
// Syntax:	check <optional player/monster>
// Conditions:
//	You need to be a lord. NOT any more.
//	However, this command is NOT in nonlord helps.
//	You need to be able to move.
//	Users level 35 can see how full they are.
//	Users level 37 can use the command on other players.
//	Users level 40 can see how intoxicated they are.
// Effects:
//	Shows you a report of your own/a beings condition.

// Prototypes
int check_attacker();
int check_intoxication();
int check_satiatedness();
int check_cmd(string str);

int
check_cmd(string str)
{
    object target;
    string tname, level_str, hp_str, tmpstring;
    int level_diff, hp_diff;

    if (!str)
    {
	return check_attacker();
    }

    if (!TP->query_can_see())
    {
	notify_fail("You cannot see.\n");
	return 0;
    }

    if (!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    tname = lower_case(str);

    if((tname == "me") || (tname == "myself"))
	tname=(string)TP->query_real_name();

    target = present(tname,environment(TP));

    if(!target)
    {
	notify_fail("Hmm, there doesn't appear to be a "+str+" here.\n");
	return 0;
    }

    if(!living(target))
    {
	notify_fail("You can only check living beings.\n");
	return 0;
    }

    /* We can't check other players till level 37 */
    if (!(target->query_npc()) && (target != TP) &&
      ((int)TP->query_level() < 37))
    {
	notify_fail("You are not allowed to check other players.\n");
	return 0;
    }

    level_diff = (int)target->query_level() - (int)TP->query_level();
    level_str = capitalize(str) + " is ";

    if (level_diff > 60)
	level_str += "of Unbelievably higher level than you";
    else if (level_diff > 30)
	level_str += "of Immensely higher level than you";
    else if (level_diff > 15)
	level_str += "of much higher level than you";
    else if(level_diff > 10)
	level_str += "of higher level than you";
    else if(level_diff > 5)
	level_str += "of a bit higher level than you";
    else if(level_diff < -15)
	level_str += "of much lower level than you";
    else if(level_diff < -10)
	level_str += "of lower level than you";
    else if(level_diff < -5)
	level_str += "of a bit lower level than you";
    else
	level_str += "about the same level as you";

    level_str += ".\n";

    hp_diff = ((int)target->query_max_hp()) / ((int)TP->query_max_hp());

    if(!hp_diff)
    {
	hp_str = "You have ";
	tmpstring = capitalize(str);
	hp_diff = ((int)TP->query_max_hp()) / ((int)target->query_max_hp());
    }
    else
    {
	hp_str = capitalize(str)+" has ";
	tmpstring = "you";
    }

    if(1==hp_diff)
	hp_str += "about the same amount of hit points as "+tmpstring+".\n";
    else
    {
	if((hp_diff >= 2) && (hp_diff <= 5))
	    hp_str += ("about "+({ "two","three","four","five" })[hp_diff-2]);
	else
	    hp_str += "many";

	hp_str += " times more hit points than "+tmpstring+".\n";
    }

    TM(level_str);
    TM(hp_str);
    TM("/bin/daemons/descs"->hp_desc(target, 0));
    TM("/bin/daemons/descs"->ac_desc(target));
    TM("/bin/daemons/descs"->wc_desc(target));

    if(((int)TP->query_level() >= 37) && (target==TP))
	check_satiatedness();

    if(((int)TP->query_level() >= 40) && (target==TP))
	check_intoxication();

    return 1;
}

int check_attacker()
{
    string name;
    object target;

    target=(object)TP->query_attack();

    if(target && present(target,environment(TP)))
    {
	return (check_cmd((string)target->query_real_name()));
    }
    else
    {
	return (check_cmd((string)TP->query_real_name()));
    }
}

int
check_intoxication()
{
    string tmp, pos;
    int drunk;

    pos=(string)TP->Possessive();

    drunk = (int)TP->query_intoxication() * 100;
    drunk = drunk / ((int) TP->query_stat(ST_CON) +
      (int)TP->query_race_stat(RACE_DRUNKNESS_RATE));

    switch(drunk)
    {
    case 0:		tmp = "You haven't had a drink in ages.\n";
	break;
    case 1..20:	tmp = "You have had a drink.  JUST ONE THOUGH!.\n";
	break;
    case 21..40:	tmp = "You have just begun on your dive back into the bottle.\n";
	break;
    case 41..60:	tmp = "You stare at the bottle in wonder at how it got 1/2 full.\n";
	break;
    case 61..80:	tmp = "You stare down the opening wondering where it all went.\n";
	tmp;
    default:	tmp = "You have cralwed all the way into the bottle and died there.\n";
	break;
    }

    TM(tmp);

    return 1;
}

int check_satiatedness()
{
    string tmp;
    int full;

    full = (int)TP->query_stuffed() * 100;
    full = full / ((int)TP->query_stat(ST_CON) * 8);

    switch(full)
    {
    case 0:
	tmp="Your stomach has an echo it's been so long since you ate";
	break;
    case 1..25:
	tmp="Your stomach grumbles to remind you it's been a while since breakfast";
	break;
    case 26..50:
	tmp="Your dinner sits comfortably in your stomach";
	break;
    case 51..75:
	tmp="Maybe you really dind't need to eat that second corpse?";
	break;
    default:
	tmp="You discover that you *really* can eat enough for 2 people";
	break;
    }

    TM(tmp+".");
}
