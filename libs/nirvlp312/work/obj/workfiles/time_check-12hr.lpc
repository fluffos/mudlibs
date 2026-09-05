int reboottime,starttime,hours,mins;
string last,now,future,uptime;
check_time() {
   int tmp,c_hour,c_min,f_hour,f_min,diff,current;
   string junk1,junk2,junk3,junk4;
  restore_object("log/upsince");
/*
  reboottime=starttime+29400;
*/
  reboottime=starttime+43800;
  now=ctime(time());
  last=uptime;
  future=ctime(reboottime);
  current=time();
  diff=reboottime-current;
  hours=diff/3600;
  mins=(diff-(hours*3600))/60;
  write("Last reboot was at "+last+"\n");
  write("It is now "+now+"\n");
  sscanf(future,"%s %s %d %d:%d:%s",junk1,junk3,junk4,f_hour,f_min,junk2);
  sscanf(now,"%s %s %d %d:%d:%s",junk1,junk3,junk4,c_hour,c_min,junk2);
/*
  if(f_hour > 4 && f_hour < 13) {
*/
  if(f_hour > 5 && f_hour < 17) {
    write("Next reboot is at "+extract(future,0,9)+" 06:05:00 \n");
/*
    if(c_hour > 20) { tmp = (24-c_hour)*3600-c_min*60;
       diff=18300+tmp; }
*/
    if(c_hour > 17) { tmp = (24-c_hour)*3600-c_min*60;
       diff=21900+tmp; }
       else diff=(6-c_hour)*3600-c_min*60+300;
       hours=diff/3600; mins=(diff-hours*3600)/60; }
  else
  write("Next reboot is at "+future+"\n");
  write(hours+" hours and "+mins+" minutes from now.\n");
  return 1;
}
discon_check() {
int current,diff;
  restore_object("log/upsince");
/*
  reboottime=starttime+29400;
*/
  reboottime=starttime+43800;
  current=time();
  diff=reboottime-current;
  return diff;
}
