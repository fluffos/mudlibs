//  Findip
//  Find all characters with a certain ip

#include <daemons.h>

int cmd_findip(string cmd) {
   string *r, args, ip;
   int x;
   if(!cmd || cmd=="") return notify_fail("Syntax: <findip [args] [ip]>\n");
   if(sscanf(cmd, "-%s %s", args, ip) != 2) {
       ip = cmd;
   }
   r=IP_D->sameip(ip);
   if(!r) return notify_fail("Unable to find any characters contained ip "+ip+"\n");
   for (x = 0; x < sizeof(r); x++) {
       if(!user_exists(r[x])) {
	       if(args == "a") {
	            r[x] = "*" + r[x];
		   } else {
		        r[x] = "";
		   }
	   }
   }
   write(format_page(r, 3));
   return 1;
}

void help() {

   write("Usage: <findip [arg] [ip]>");
   write("Argument can be: -a; Show all charactes including non-existant.");

}
