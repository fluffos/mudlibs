#include <daemons.h>

nomask status kingdom_cmd(string arg)
{
    object ob;
    string cmd, who, kingdom, filename;

    if (!arg || sscanf(arg, "%s %s %s", cmd, who, kingdom) < 3)
	return notify_fail("Syntax: kingdom <add | remove> <player> <earth | "
	  "water | wind | fire>\n"), 0;

    ob = find_living(who = lower_case(who));

    if (!interactive(ob))
	return notify_fail(capitalize(who)+" does not seem to be in the game.\n"), 0;

    if (member(({"earth", "water", "wind", "fire"}), kingdom) == -1)
	return notify_fail("Valid kingdoms are earth, water wind or fire.\n"), 0;

    filename = "/log/history/"+who[0..0]+"/"+who;

    if (file_size(filename) < 0)
	write_file(filename, capitalize(implode(explode(who, ""), " ") + "\n"));

    switch (cmd)
    {
    case "add":
	ob->set_kingdom(kingdom);
	write_file(filename, "\n      Joined:  "+capitalize(kingdom)+
	  " Kingdom on "+ctime(time())+".");
	CHANNEL_D->join_channel(kingdom, ob);
	break;
    case "remove":
	ob->set_kingdom();
	write_file(filename, "\n    Resigned:  "+capitalize(kingdom)+
	  " Kingdom on "+ctime(time())+".");
	CHANNEL_D->remove_from_channel(kingdom, ob);
	break;
    default:
	return notify_fail("Available arguments are add and remove."), 0;
	break;
    }

    if(this_player())
	this_player()->tell_me("Ok.");
    return 1;
}
