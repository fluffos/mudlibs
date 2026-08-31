// report -- seeker


#include <std.h>

inherit DAEMON;

int cmd_report(string str)
{
 string outp;
 int hp, max_hp, sp, max_sp, mp, max_mp;

   if(this_player()->query("bear"))
     return notify_fail("You growl like a bear.\n");
   hp = (int)this_player()->query_hp();
   max_hp = (int)this_player()->query_max_hp();
   sp = (int)this_player()->query_sp();
   max_sp = (int)this_player()->query_max_sp();
   mp = (int)this_player()->query_mp();
   max_mp = (int)this_player()->query_max_mp();

outp = "I have "+hp+"/"+max_hp+" hp, "+sp+"/"+max_sp+" sp, "+mp+"/"+max_mp+" mp.";
   message("info", "%^CYAN%^You say:%^RESET%^ " +outp, this_player());
   message("info", "%^CYAN%^"+(string)this_player()->query_cap_name()+" says: %^RESET%^"+outp, environment(this_player()), this_player());
 return 1;
}
int help()
{
  write( @EndText
Syntax: report
Effect: allows you to report you hp, sp, and mp to the room.
See also: status
EndText
  );
  return 1;
}
 
