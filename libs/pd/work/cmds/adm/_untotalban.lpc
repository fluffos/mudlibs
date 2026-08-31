// Seeker [Friday May 5 2000 -- 16:45 -07:00]

#include <daemons.h>
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_untotalban(string str)
{
    string *ips;
    int x;

    if (!archp(previous_object()))
	return 0;

    if (!str || str=="")
    {
	write("Untotalban what site?\n For example: untotalban 127.0.0.*");
	return 1;
    }
    seteuid(UID_BANISH);
    ips = BANISH_D->query_total_bans();
    x = sizeof(ips);
    while (x--)
    {
	if (ips[x]==str)
	{
	    BANISH_D->remove_total_ban(str);
	    write("IP: ("+str+") has been un-totalbanned.");
	    seteuid(geteuid());
	    return 1;
	}
    }
    write("Could not find that listing.\n");
    seteuid(geteuid());
    return 1;
}

