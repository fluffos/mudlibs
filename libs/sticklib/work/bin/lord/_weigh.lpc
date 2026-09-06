#include <lord.h>
#include <stats.h>

/*
	Lord command:	weigh
	Syntax:		weigh
	Conditions:
		User must be level 32
	Effects:
		Returns an approximate weight
		   of the players invintory
*/
int weigh_cmd()
{
    int weight, max_weight, rel_weight;
    string tmp;

    if (((int)TP->query_level() < 32) && !(CODER))
	return 0;

    if(!(CAN_MOVE(TP)))
    {
	notify_fail(MOVE);
	return 0;
    }

    TP->recount_weight();
    weight = (int)TP->query_weight();
    max_weight = (int) TP->query_stat(ST_STR) + 10;
    rel_weight = weight*100/max_weight;

    switch(rel_weight)
    {
    case  0..14: tmp = "very light";
	break;
    case 15..28: tmp = "light";
	break;
    case 29..42: tmp = "quite light";
	break;
    case 43..56: tmp = "quite heavy";
	break;
    case 57..70: tmp = "heavy";
	break;
    case 71..84: tmp = "very heavy";
	break;
    case 85..98: tmp = "extremely heavy";
	break;
    default:     tmp = "almost too heavy";
	break;
    }

    TM("Your load is "+tmp+".");

    return 1;
}
