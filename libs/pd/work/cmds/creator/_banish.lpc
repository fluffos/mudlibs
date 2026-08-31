// Seeker [Friday May 5 2000 -- 16:45 -07:00]

#include <daemons.h>
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_banish(string str)
{
 string *ips;
 int x;

 if (!str || str=="")
   {
    write("Banish what site?\n For example: banish 127.0.0.*");
    return 1;
   }
 seteuid(UID_BANISH);
 ips = BANISH_D->query_banished_ips();
 x = sizeof(ips);
 while (x--)
   {
    if (ips[x]==str)
      {
       write("IP: ("+str+") has already been banned.");
       return 1;
      }
   }
 seteuid(UID_LOG);
 log_file("adm/banish", this_player()->query_name()+" banished "+str+" on "+ctime(time())+"\n");
 seteuid(getuid());
 BANISH_D->banish_ip(str);
 MSQL_D->msql_insert("pd", "banish", ({str}));
 seteuid(geteuid());
 write("IP: ("+str+") has been banned.");
 return 1;
}
