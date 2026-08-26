// _ip.c
// Lets you know the IP name and number of one or all users.
// Cool stuff added by Disconnect [original by someone on DarkPowers]
// enjoy!
// Mobydick installed it into the TMI-2 mudlib, 4-27-94

#include <mudlib.h>
#include <config.h>

inherit DAEMON;

int cmd_ip(string str) {
  object ob,*all;
  int i;
  if(str && !find_living(str))
    return notify_fail("That user isn't online!\n");
  if(!str) {
    write(" -=-  Complete IP List   -=-\n -=- Disconnect [4/9/94] -=-\n\n");
    all=users();
    i=sizeof(all);
    while(i--)
      printf(" %-15s -> %-25s ( %-15s )\n", 
        (string)all[i]->query("cap_name"),
        all[i]->query("ip"), query_ip_number(all[i]));
    return 1;
  }
  ob=find_living(str);
  printf("#ip: %s -> %s ( %s )\n", ob->query("cap_name"),
    ob->query("ip"), query_ip_number(ob));
  return 1;
}

string help()
{
  return( "Syntax: ip [player]\n\n"
    "Will return both string and numerical ip address origin of the"
    "player specified.\n" );
  return("Used without [player] it lists the IP's of all users online.\n");
}
