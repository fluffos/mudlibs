// Seeker [Friday May 5 2000 -- 16:45 -07:00]

#include <daemons.h>
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_listbanish()
{
 string *ips;
 int x;

 if (!archp(previous_object()))
   return 0;

 seteuid(UID_BANISH);
 ips = BANISH_D->query_banished_ips();
 x = sizeof(ips);
 while (x--)
   {
    if (ips[x])
      {
       write("IP: ("+ips[x]+") is banished.");
      }
   }
 seteuid(geteuid());
 return 1;
}
