string uptime;
string future;
int starttime;

check_times() {
  int fut;
  if(!uptime) {
    restore_object("/log/upsince");
    fut=uptime+24*60*60;
    future=ctime(fut);
#ifndef __LDMUD__
    future=future[0..9]+" 06:05:00 "+future[-4..-1];
#else
    future = future[0..9] + " 06:05:00 " + future[<4..<1];
#endif
  }
}

check_time() {
  string junk,current_hour,current_minute;
  string current_time;
  check_times();
  current_time=ctime();
  sscanf(current_time,"%s %s %d %d:%d:%s",
         junk,junk,junk,current_hour,current_minute,junk);
  
  write("Last reboot was at :"+starttime+"\n");
  write("Current time is:    "+current_time+"\n");
  write("Next reboot is at:  "+future+"\n");
}
