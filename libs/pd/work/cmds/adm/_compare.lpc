// _compare.c
//  Command to compare a user's ip from the IP database.

#include <daemons.h>

int cmd_compare(string str) {
   string ip, *ips;
   int i;
   if(!str || str == "") { write("Syntax: <compare [user]>"); return 1; }
   ip=IP_D->query_ip(str);
   ips=IP_D->sameip(ip);
   ips -= ({ str });
   i=sizeof(ips);
   while(i--) {
     if(!user_exists(ips[i])) ips[i]+="!exist";
     if(BANISH_D->query_banished_ip(MULTI_D->get_user_ip(ips[i]))) ips[i]+="ban";
   }
   write("Comparing user "+str+" ("+ip+") to database.");
   if(!sizeof(ips)) write("No results found."); else
   write(format_page(ips, 3));
   return 1;
}
