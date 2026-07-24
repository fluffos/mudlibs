#include <mudlib.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <uid.h>

inherit DAEMON ;
 
void load_sites();
 
string *SITES;
 
create() {  seteuid(getuid(this_object()));  load_sites();  }
 
void load_sites() {
   string *tmp, file;
   int loop;
 
   SITES = ({ });
 
   file = read_file( APPROVED_SITES );
  
   if(!file)  return;
 
   tmp = explode(file, "\n");

   for(loop=0; loop<sizeof(tmp); loop++)
   if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
      continue;
   else SITES += ({ tmp[loop] });

}
 
int telnet_permission(object caller, string func, mixed *info) {
   string eff_user, tmp1, tmp2, tmp3;
   int loop;
 
#if 0
   log_file("telnetd","Caller: " + identify(caller) + "  Func: " + identify(func) + "  Info: " + identify(info) + "\n");
#endif
 
 
   if(!SITES)  load_sites();
 
   eff_user = geteuid(caller);
 
 
  if(member_group(eff_user, "admin") || eff_user == ROOT_UID ||
   member_group(eff_user, "socket"))
   return 1;
 
 
   if(caller && member_array(base_name(caller), APPROVED_TELNET) != -1)
   return 1;
 
   if(!info[2])  return 1;
   for(loop=0; loop<sizeof(SITES); loop++) {
 
   if(SITES[loop] == info[2])  return 1;   
 
   else if(SITES[loop] == "*.*.*.*")  return 1; 

   else if(sscanf(SITES[loop],"%s.*.*.*", tmp1) == 1) {
   if(sscanf(info[2], tmp1 + ".%s.%s.%s", tmp1, tmp2, tmp3) == 3)
     return 1;
   }
   else if(sscanf(SITES[loop], "%s.%s.*.*", tmp1, tmp2) == 2) {
   if(sscanf(info[2], tmp1 + "." + tmp2 + ".%s.%s", tmp1, tmp2) == 2)
     return 1;
   }
   else if(sscanf(SITES[loop], "%s.%s.%s.*", tmp1, tmp2, tmp3) == 3) {
   if(sscanf(info[2], tmp1 + "." + tmp2 + "." + tmp3 + ".%s", tmp1) == 1)
     return 1; 
   }
 
   }

return 0; }
 
