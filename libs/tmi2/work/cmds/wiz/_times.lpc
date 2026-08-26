// The orginal TIMES command, Qixx@Hero
// help added by Pallando (92-02-05)

#include <mudlib.h>
inherit DAEMON;

int cmd_times(string arg) {
int times;
int cmd;
int cpu, utime,stime;
mapping use;

if (!arg) {write("Usage:  times #OfTimesToExecute CmdToExecute\n"); return 1;}
if (sscanf(arg,"%d %s",times,cmd)!=2) return cmd_times(0);

if (times<1) times=1;
if (times>30) times=30;
use=rusage();
utime=use["usertime"];
stime=use["stime"];
while (times--) cpu+=(int)this_player()->force_me(cmd);
use=rusage();
utime=use["usertime"]-utime;
stime=use["stime"]-stime;
write("User milliseconds="+utime+"  System milliseconds="+stime+"  Cycles="+cpu+"\n");
return 1;
}

int help()
{
  write( ""+
"Syntax: times <N> <command>\n"+
"Effect: repeats <command> <N> times.\n"+
"        Then shows the time resources used by it.\n"+
"See also: gauge\n"+
"NB if you arn't interested in the cycles used you can just type\n"+
"   <N> <command>\n"+
"without the \"times \", which will also have the effect of repeating\n"+
"the command <N> times.\n"+
  "" );
  return 1;
}
