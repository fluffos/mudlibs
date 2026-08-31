//  Use this to get the ip of a character.
#include <daemons.h>
#include <connection_cl.h>

int do_sort(class Connection, class Connection);

int cmd_getip(string s) {
   string ip_base, *out=({}), *k, *times;
   class Connection *conns;
   int i;
   if(!s || s=="") return notify_fail("Syntax: <getip [name]>\n");
   conns=IP_D->query_all_connections(s);
   ip_base=IP_D->query_ip(s);
   if(!ip_base) return notify_fail("Cannot find base ip for "+s+".\n");
   write(s+"'s current ip: "+ip_base+"");
   conns=sort_array(conns, "do_sort");
   i=sizeof(conns);
   while(i--) {
     out += ({ "%^BOLD%^%^GREEN%^IP%^RESET%^: "+conns[i]->ip+" %^BOLD%^%^GREEN%^Time%^RESET%^: "+ctime(conns[i]->time) });
   }
   this_player()->more(out, "info", "");
   return 1;
}


int do_sort(class Connection c1, class Connection c2) {
  if (c1->time > c2->time) return 1;
  else return -1;
}
