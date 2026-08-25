
// encumbrance cmd from player.c, now external. Morgoth 2/Mar/95

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;
}

string query_usage()
{
	return "encumbrance";
}

string query_short_help()
{
	return "Shows actual and max encumbrance.";
}

protected int cmd (string arg, object me)
{
	int now;
	int max;
	now=me->query_loc_weight();
	max=me->query_max_weight();
	write("Your current inventory weighs "+now+".  You can "+
		"carry up to "+max+", thanks to your strength.\n");
	return 1;
}
