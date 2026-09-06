#include <daemons.h>

int i;
string *list, cap_clan;

nomask status clan_cmd(string arg)
{
    object ob;
    string cmd, who, clan, filename;

    if (!arg || sscanf(arg, "%s %s %s", cmd, who, clan) < 3)
	return notify_fail("Syntax: clan <add | remove> <player> <clan name>\n"), 0;

    ob = find_living(who = lower_case(who));

    if (!interactive(ob))
	return notify_fail(capitalize(who)+" does not seem to be in the game.\n"), 0;

    if (member(({"earth", "water", "wind", "fire"}), ob->query_kingdom()) == -1)
	return notify_fail("Target must be a member of a kingdom.\n"), 0;

    filename = "/log/history/"+who[0..0]+"/"+who;

    if (file_size(filename) < 0)
	write_file(filename, capitalize(implode(explode(who, ""), " ") + "\n"));

    list = explode(clan, " ");

    for (i = 0; i < sizeof(list); i++)
	list[i] = capitalize(list[i]);

    cap_clan = implode(list, " ");

    switch (cmd)
    {
    case "add":
	ob->set_clan(clan);
	write_file(filename, "\n      Joined:  "+cap_clan+" Clan on "+ctime(time())+".");
	//          CHANNEL_D->join_channel(kingdom, ob);
	break;
    case "remove":
	ob->set_clan();
	write_file(filename, "\n    Resigned:  "+cap_clan+" Clan on "+ctime(time())+".");
	//          CHANNEL_D->remove_from_channel(kingdom, ob);
	break;
    default:
	return notify_fail("Available arguments are add and remove."), 0;
	break;
    }

    if(this_player())
	this_player()->tell_me("Ok.");
    return 1;
}
