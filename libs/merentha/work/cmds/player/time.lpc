// Petrarch
// Merentha Lib 1.0
// <time>

string help() {
return "Syntax: time\n\nThis command displays the current MUD time. \
It also displays the current real time on the west cost of North \
America.\n\n\
MUD time is much like real time, except it uses base 8 instead of base 60 \
time which we are familuar with.  There are 8 seconds in each minute, \
8 minutes in each hour, 8 hours in each day and 8 days in a week.  There \
are 4 weeks in a month and 8 months in a year.  Also one MUD second is \
about 64 real seconds.\
\n\n\
See also: days, months
";
}

string up_time() {
int i=uptime();
  return ""+(i/(60*60*24*7))+"w "+(i/(60*60*24))%7+"d "+(i/(60*60)%24)+"h "+(i/60)%60+"m "+i%60+"s";
}

varargs int command(string str) {
  message("command", border("%^RED%^MUD time: "+mud_time()+" "+mud_date()+
"\n%^GREEN%^Real time: "+ctime(time())+
"\n%^ORANGE%^"+mud_name()+" has been running for: "+up_time(),"time",
this_player()->getenv("SCREEN")), this_player());
  return 1;
}

