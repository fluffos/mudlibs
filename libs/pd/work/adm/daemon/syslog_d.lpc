/*
*************************
**      SYSLOG_D.C     **
*************************
 ^ The new mud logger for Primal Darkness Beta II
 * Much more detailed logging
 * Log rotation
*/

#include <std.h>
#include <security.h>
#include <daemons.h>
#include <syslog.h>

inherit DAEMON;


mapping types= ([ 
                   "advance" : "advance.log",
                   "skills"  : "skills.log",
                   "stats"   : "stats.log",
                   "enter"   : "connections.log",
                   "exit"    : "connections.log" 
               ]);

int do_log(string type, string msg)
{
 int date;
 string da_let,mo,day,yea,tmp, loc;
/*
 if(base_name(previous_object()) != OB_USER &&
  geteuid(previous_object()) != UID_LOG &&
   geteuid(previous_object()) != UID_ROOT) return ERR_NOACCESS;
*/
 if (!types[type]) return ERR_INVALIDTYPE;
 if (!msg||msg=="") return ERR_INVALIDMSG;
 date = TIME_D->query_tzone("PST");
 sscanf(ctime(date), "%s %s %d %s %d", da_let, mo, day, tmp, yea);
 loc = "/log/"+da_let+"_"+mo+"_"+day+"_"+yea;
 if (file_size(loc)==-1) mkdir(loc);
 seteuid(UID_LOG);
 write_file(loc+"/"+types[type], "["+ctime(date)+"] "+msg+"\n");
 seteuid(getuid());
 return 1;
}
