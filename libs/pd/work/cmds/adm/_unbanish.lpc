// Seeker [Friday May 5 2000 -- 16:45 -07:00]

#include <daemons.h>
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_unbanish(string str)
{
 string *ips;
 int x;

 if (!archp(previous_object()))
   return 0;

 if (!str || str=="")
   {
    write("Unbanish what site?\n For example: unbanish 127.0.0.*");
    return 1;
   }
 seteuid(UID_BANISH);
 ips = BANISH_D->query_banished_ips();
 x = sizeof(ips);
 while (x--)
   {
    if (ips[x]==str)
      {
       BANISH_D->unbanish_ip(str);
       write("IP: ("+str+") has been un-banned.");
       MSQL_D->msql_delete("pd", "banish", "ip=\""+str+"\"");
       seteuid(geteuid());
       return 1;
      }
   }
 write("Could not find that listing.\n");
 seteuid(geteuid());
 return 1;
}
