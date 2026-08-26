// Petrarch
// Merentha Lib 1.0
// <usage>

varargs int command() {
mapping usage=rusage();
  usage["utime"]=usage["utime"]/1000;
  usage["stime"]=usage["stime"]/1000;
  message("command", "User Time    : "+usage["utime"]/3600+"h "+(usage["utime"]%3600)/60+"m "+usage["utime"]%60+"s\n\
System Time  : "+usage["stime"]/3600+"h "+(usage["stime"]%3600)/60+"m "+usage["stime"]%60+"s\n\
Minor Faults : "+usage["minflt"]+"\n\
Major Faults : "+usage["majflt"]+"\n"+
query_load_average(), this_player());
  return 1;
}

string help() {
return "Syntax: usage\n\nDisplays some stats on the usage of system resources.";
}
