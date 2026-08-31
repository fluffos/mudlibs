// Seeker [Friday May 5 2000 -- 16:45 -07:00]

#include <daemons.h>
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_totalban(string str)
{
    string *ips;
    int x;

    if (!archp(previous_object()))
	return 0;

    if (!str || str=="")
    {
	write("Banish what site?\n For example: totalban 127.0.0.*");
	return 1;
    }
    seteuid(UID_BANISH);
    ips = BANISH_D->query_total_bans();
    x = sizeof(ips);
    while (x--)
    {
	if (ips[x]==str)
	{
	    write("IP: ("+str+") has already been totalbanned.");
	    return 1;
	}
    }
    BANISH_D->total_ban_ip(str);
    seteuid(geteuid());
    write("IP: ("+str+") has been banned.");
    return 1;
}


