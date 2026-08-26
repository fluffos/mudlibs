 
//	File	:  /cmds/xtra/_cpu.c
//	Creator	:  Truilkan@Portals
//
//	This command determines the percentage of cpu usage presently
//	taken by the mud's gamedriver.
 
#include <mudlib.h>
 
inherit DAEMON;

#define SCALE	(1.0/10.0)
#define SYNTAX	"Syntax: cpu\n"

int cmd_cpu() {
   float value;
   mapping r;
   
   r = rusage();
   value = SCALE * (r["utime"] + r["stime"]) / uptime();
 
   printf("%s is presently using a CPU load of %f%%\n",
	  capitalize(mud_name()), value);

return 1; }
 
int help() {

   write( SYNTAX + "\n" +
     "This command displays the present cpu load level of the mud's" +
     " driver.\n");
 
return 1; }
 

