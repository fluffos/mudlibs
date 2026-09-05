/* By illarion@nirvana dec 2004
   change the defines below if the reboot cycle changes
   
   inspired by code by boltar which I couldn't figure out 
   note this code can't handle a boot_cycle any longer than 24
*/

#define BOOT_CYCLE 24
#define FIXED_HOUR 6
#define FIXED_MINUTE 5
string uptime;
string future;
int starttime;
int boot_day,boot_hour,boot_minute,boot_second;

string add_zero(int what) {
  if(what >= 0 && what <10)
    return "0"+what;
  return ""+what;
}
reset() {
  int cycle_time,fixed_time;
  string junk;
  int current_h,current_m,current_s;
  
  if(!uptime) {
    write("\n");
    restore_object("log/upsince");
    /* figure the time until the next boot on the current reboot cycle */
    cycle_time=starttime+(BOOT_CYCLE*3600);
    /* figure the time of the next fixed time reboot */
    sscanf(ctime(),"%s %s %d %d:%d:%d %s",
           junk,junk,junk,current_h,current_m,current_s,junk);
    fixed_time=time()-(current_h*3600)-(current_m*60)-current_s;
    fixed_time+=(FIXED_HOUR*3600)+(FIXED_MINUTE*60);
    if(fixed_time < time())
      fixed_time+=86400;
    /* whichever time is earlier is the time of the next reboot */
    if(fixed_time < cycle_time)
      future=ctime(fixed_time);
    else
      future=ctime(cycle_time);
    sscanf(future,"%s %s %d %d:%d:%d %s",
      junk,junk,boot_day,boot_hour,boot_minute,boot_second,junk);

  }
}
    

boot_stats(current_time) {
  string junk;
  int current_hour,current_minute, current_second, current_day;
  int hours, minutes, seconds;
  sscanf(current_time,"%s %s %d %d:%d:%d %s",
         junk,junk,current_day,current_hour,current_minute,current_second,junk);
  hours=24+boot_hour-current_hour;
  minutes=boot_minute-current_minute;
  seconds=boot_second-current_second;
  if(seconds<0) {
    seconds+=60;
    minutes-=1;
  }
  if(minutes<0) {
    minutes=60+minutes;
    hours-=1;
  }
  if(hours>23) {
    hours=hours-24;
  }

  return ({hours,minutes,seconds});
}    

check_time() {
  string current_time;
  string *reb_stats;
  current_time=ctime();
  
  write("\nLast reboot:  "+uptime+"\n"
       +"Current time: "+current_time+"\n"
       +"Next reboot:  "+future+"\n");
  reb_stats=boot_stats(current_time);
  if(sizeof(reb_stats)==3) 
    write("     "+reb_stats[0]+" hour"+(reb_stats[0]==1?"":"s")+", "
         +reb_stats[1]+" minute"+(reb_stats[1]==1?"":"s")+", and "
         +reb_stats[2]+" second"+(reb_stats[2]==1?"":"s")+" from now.\n");
}

discon_check() {
  string *reb_stats;
  reb_stats=boot_stats(ctime(),6);
  return reb_stats[0]*60*60+reb_stats[1]*60+reb_stats[2];
}
