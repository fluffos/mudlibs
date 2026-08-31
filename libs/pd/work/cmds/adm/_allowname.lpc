#include <daemons.h>
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_allowname(string str)
{
 string *ips;
 int x;

 if (!archp(previous_object()))
   return 0;

 if (!str || str=="")
   {
    write("Allow what name?  Syntax: <allowname [name]>");
    return 1;
   }
 seteuid(UID_BANISH);
 BANISH_D->allow_name(str);

 seteuid(geteuid());
 write("The name "+str+" is now allowed.");
 return 1;
}
