//  ustat.c 
//  Gets immortal usage stats.
//  Args: <ustat [name]> <ustat -s [name] [session]> <ustat -l [name]>

#include <daemons.h>
#define fail(s) notify_fail("Error: "+s+"\n");
#define usage(a,b) notify_fail("Usage "+(a?"["+a+"]":"")+": "+b+"\n");

int cmd_ustat(string s) {
   string flag, name, output, *k;
   int i, x, y, session, elapse;
   float avg, tmp;
   mapping dat;

   //  List Sessions
   if(!member_group(this_player()->query_name(), "superuser")) return 0;
   if(!s || s=="") {
     write("Usage: <ustat [name]> <ustat -s [name] [session]> <ustat -l [name]>");
     return 1;
   }
   if(sscanf(s, "-l %s", name)==1) {
     dat=IMSTAT_D->get_sessions(name);
     if(!dat) return fail("Unable to find information on "+name);
     i=sizeof(keys(dat));
     write("Complete session list for "+name+".  "+i+" session(s) found.");
     k=sort_array(keys(dat),"sort_by_date");
     output = "";
     while(i--) 
       output += ""+ctime((int)k[i])+" (ID: "+k[i]+")" + (dat[k[i]]["writable"] == 1?" (open)":"")+"\n";
     write(output);
     return 1;
   } else if(s[0..1] == "-l") return notify_fail("Usage [-l]: <ustat -l [name]>\n");

   //  Get Usage Session
   if(sscanf(s, "-s %s %d", name, session)==2) {
     dat=IMSTAT_D->get_session_stats(name, session);
     if(!dat) return fail("Unable to find session.");
     write("Session statistics for "+name+": ");
     output = "";
     output += "------------------------------------------------------------\n";
     output += "Session status: "+(dat["writable"]?"%^BOLD%^%^GREEN%^Open%^RESET%^":"%^BOLD%^%^RED%^Closed%^RESET%^")+"\n";
     output += "Session start: "+dat["time_start"]+"\n";
     output += "Session end: "+(dat["time_end"]?dat["time_end"]:"N/A")+"\n";
     output += "Time elapsed: ";
     if(dat["time_end"])
       elapse = to_float((dat["time_end"]-dat["time_start"])); else
     elapse = to_float((time()-dat["time_start"]));
     output += (elapse/60)+" minutes\n";
     i=sizeof(k=keys(dat["used_commands"]));
     while(i--) x += dat["used_commands"][k[i]];
     output += "# of commands: "+x+"\n";
     if(x) {
       tmp = elapse/60/60;
       if(!tmp) tmp=1;
       avg = to_float(x) / tmp;
       output += "Average: "+avg+"cmds p/hr\n";
     }
     else output += "Average: Unavailable.\n";
     write(output);
     return 1;
   } else if(s[0..1] == "-s") return notify_fail("Usage [-s]: <ustat -s [name] [session_id]>\n");

   dat = IMSTAT_D->get_average_stats(s);
   if(!dat) return fail("Unable to find information on "+s);
   write(identify(dat)+"sd");
   write("Usage statistics on "+s+"");
   output = "-------------------------------------------------------------\n";
   output += "Number of sessions: "+sizeof(IMSTAT_D->get_sessions(s))+"\n";
   output += "Last session logged at "+dat["last_session"]+"\nNumber of commands used: ";
   i=sizeof(k=keys(dat["used_commands"]));
   while(i--) x += dat["used_commands"][k[i]];
   output += ""+x+"\n";
   output += "Total online time: "+dat["total_time"]+"\n";
   write(dat["total_time"]+" "+(dat["total_time"] / 60)+" "+(dat["total_time"] / 60 / 60));
   if(dat["total_time"] && x) {
     avg = to_float(x) / (to_float(dat["total_time"]) / 60 / 60);
     output += "Average: "+avg+"cmds p/hr\n";
   }
   else output += "Average: Unavailable.\n";
   
   write(output);
   return 1;
}

int sort_by_date(string a, string b) {
   return strcmp(a+"",b+"");
}

void help() {
   write(@EOT
Usage of <ustat>.
<ustat> is used to report statistics about immortals activitity in the 
creation department.

<ustat [name]>: Reports the total statistics for a given user.
<ustat -s [name] [session]>: Reports statistics for a user session.  You 
   may retrieve the session ID from the next syntax.
<ustat -l [name]>: Reports the number of sessions along with the start time 
   and the session ID.


EOT);
}

