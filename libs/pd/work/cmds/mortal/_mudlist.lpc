#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_mudlist(string str) {
    mapping borg;
string *muds, *outp;
    int i;
if (str) borg = (mapping)NETWORK_D->query_mud_info(str);
    if(str && !borg) 
      return notify_fail(mud_name()+" is not aware of that mud.\n");
    else if(str)
      message("info", sprintf("%s:\nAddress: %s %s\nDriver: %s    Mudlib: %s %s",
        borg["NAME"], borg["HOSTADDRESS"], borg["PORT"], 
        (borg["DRIVER"] ? borg["DRIVER"] : "Unknown"),
        (borg["MUDLIB"] ? borg["MUDLIB"] : "Unknown"),
        (borg["VERSION"] && borg["MUDLIB"] ? borg["VERSION"] : "")),
        this_player());
    else
   {
    muds = (string *)NETWORK_D->query_muds();
    i = sizeof(muds);
    outp = ({ });
    while(i--)
     {
/*  borg  = (mapping)NETWORK_D->query_mud_info(muds[i]); */
      outp += ({ "%^BLUE%^%^BOLD%^"+muds[i] });
      
     }
    this_player()->more(outp);
   }
    return 1;
}
int help()
{
  write( @EndText
Syntax: mudlist
Effect: lists the names of mud on intercre.
EndText
  );
  return 1;
}
