///bin/user/_muds.c
//from the Nightmare mudlib
//     Display how long a player has been idle.
//     Written by Plura@Nightmare 930205
//     Changed to use visible() to take into account level 1 wizards by
//     Pallando@Nightmare 93-09-10
//     Changed to query_invis() to hide invisible wizards 04OCT93 by
//     Gregon@Nightmare

#include <std.h>

inherit DAEMON;
void help();
protected string parse_time(int i);

int cmd_idle(string str) {
   object ob;
   
   if(str && (ob = find_player(lower_case(str))) && interactive(ob) &&
      !ob->query_invis() )
   {
      write(capitalize(str)+" has been idle for " +
         parse_time(query_idle(ob)) +".");
      return 1;
   }
    if(ob && !interactive(ob))
      {
      write(capitalize(str) + " is link dead now.");
      return 1;}
   if(str)
      {
      write("Could not find '"+str+"'.");
   return 1;
   }
   help();
   return 1;
}

void help() {
   write("Syntax: idle <player>\n\n" +
      "Shows how long <player> has been idle.\n"
      "See also: muds, finger, tell, reply\n"
   );
}

protected string
parse_time(int t)
{
   string str;
   str=(t%60)+" s";
   t /= 60;
   if(t%60>0)
      str=t%60+" m "+str;
   t /= 60;
   if(t%24>0)
      str=t%24+" h "+str;
   t /= 24;
   if(t>0)
      str=t+" d "+str;
   return str;
}
